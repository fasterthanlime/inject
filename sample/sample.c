#include <windows.h>

int main() {
    /* LoadLibraryW(L"detour_test_lib.dll"); */
    MessageBoxW(
            NULL,
            L"This is just a regular code sample",
            L"Nothing to see here",
            MB_OK
    );
}
