The foci of this repository are the [sleep.c](https://github.com/Valkryst/C_PThread_Sleep/blob/main/src/sleep.c)
and [sleep.h](https://github.com/Valkryst/C_PThread_Sleep/blob/main/src/sleep.h)
files.

## Compiling

Add `sleep.c` and `sleep.h` to your project, update your build script, and
compile as you normally would.

See the provided [Makefile](https://github.com/Valkryst/C_PThread_Sleep/blob/main/Makefile)
as a reference.

## Dependencies

For development purposes, `sleep.c` depends on my
[C_Logging](https://github.com/Valkryst/C_Logging) library. By replacing all
calls to `printError` in `sleep.c`, you can remove this dependency.
