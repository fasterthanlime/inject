#include <windows.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    if (getenv("WAIT")) {
        /* printf("Waiting for user input...\n"); */
        /* fflush(stdout); */
        /* char str[1024]; */
        /* gets(str); */

        for (int i = 0; i < 10; i++) {
            printf("Sleeping 250ms.. (%d)\n", i);
        fflush(stdout);
            usleep(1000 * 250);
        }
    }

    char *ex = getenv("HOOK");
    if (ex && strcmp("1", ex) == 0) {
        HMODULE mod = LoadLibraryW(L"detour_test_lib.dll");
        if (!mod) {
            printf("LoadLibraryW failed: error number %lu\n", GetLastError());
            fflush(stdout);
            return 1;
        }
    }
    MessageBoxW(
            NULL,
            L"This is just a regular code sample",
            L"Nothing to see here",
            MB_OK
    );
}
