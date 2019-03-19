package main

import (
	"log"
	"os"

	"github.com/itchio/ox/syscallex"
	"github.com/itchio/ox/winox/execas"
)

func inject(dllFile string, exeFile string) {
	cwd, err := os.Getwd()
	must(err)

	cmd := execas.Command(exeFile)
	cmd.Dir = cwd
	cmd.Env = os.Environ()
	cmd.Stdout = os.Stdout
	cmd.Stdin = os.Stdin

	var creationFlags uint32 = syscallex.CREATE_SUSPENDED
	cmd.SysProcAttr = &syscallex.SysProcAttr{
		CreationFlags: creationFlags,
	}

	log.Printf("Creating process suspended...")
	err = cmd.Start()
	must(err)

	log.Printf("Resuming process...")
	_, err = syscallex.ResumeThread(cmd.SysProcAttr.ThreadHandle)
	must(err)

	log.Printf("Okay, waiting now")
	err = cmd.Wait()
	must(err)

	log.Printf("And we're done!")
}
