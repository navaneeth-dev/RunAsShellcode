cmake_minimum_required( VERSION 3.27 )
set(CMAKE_ASM_NASM_OBJECT_FORMAT "win64")
project( Stardust LANGUAGES ASM_NASM )
enable_language( C CXX ASM )

set(COMPILE_FLAGS "-Os -fno-asynchronous-unwind-tables -nostdlib -fno-ident -fpack-struct=8 -falign-functions=1 -s -ffunction-sections -falign-jumps=1 -w -falign-labels=1 -fPIC -Wl,-T../scripts/Linker.ld -Wl,-s,--no-seh,--enable-stdcall-fixup -Iinclude -masm=intel -fpermissive -mrdrnd -D KAINE_TRANSPORT_HTTP")

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_COMPILER g++ )
set( CMAKE_CXX_FLAGS    ${COMPILE_FLAGS} )

set( CMAKE_C_STANDARD   11 )
set( CMAKE_C_COMPILER   g++ )
set( CMAKE_C_FLAGS      ${COMPILE_FLAGS} )



include_directories( include )

set( STARDUST-SRC
        src/PreMain.c
        src/Main.c
        src/Ldr.c
        src/Utils.c
)

add_executable( Stardust ${STARDUST-SRC} src/Stardust.nasm )
set_source_files_properties(src/Stardust.nasm PROPERTY LANGUAGE ASM_NASM )