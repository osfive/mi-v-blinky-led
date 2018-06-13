# mi-v-blinky-led
RISC-V Creative MI-V Hello World &amp; LED blink example

### Build under Linux

Build 32-bit RV32GC toolchain: https://github.com/riscv/riscv-gnu-toolchain

    $ export CROSS_COMPILE=/path/to/riscv32-unknown-linux-gnu-
    $ git clone --recursive https://github.com/osfive/mi-v-blinky-led
    $ cd mi-v-blinky-led
    $ bmake

### Build under FreeBSD

Build 32-bit RV32GC toolchain (FreeBSD version): https://github.com/freebsd-riscv/riscv-gnu-toolchain

    $ setenv CROSS_COMPILE /path/to/riscv32-unknown-freebsd12.0-
    $ git clone --recursive https://github.com/osfive/mi-v-blinky-led
    $ cd mi-v-blinky-led
    $ make
