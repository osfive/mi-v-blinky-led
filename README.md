# mi-v-blinky-led
RISC-V Creative MI-V Hello World &amp; LED blink example

### Build under Linux / FreeBSD

Build 32-bit toolchain: https://github.com/riscv/riscv-gnu-toolchain

    $ export CROSS_COMPILE=/path/to/riscv32-unknown-linux-gnu-
    $ git clone --recursive https://github.com/osfive/mi-v-blinky-led
    $ cd mi-v-blinky-led
    $ make
