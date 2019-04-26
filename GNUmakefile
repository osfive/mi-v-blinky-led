APP =		mi-v-blinky-led
MACHINE =	riscv

CC =		${CROSS_COMPILE}gcc
LD =		${CROSS_COMPILE}ld
OBJCOPY =	${CROSS_COMPILE}objcopy

LDSCRIPT =	${CURDIR}/ldscript

OBJECTS =	main.o						\
		osfive/sys/riscv/microsemi/core_gpio.o		\
		osfive/sys/riscv/microsemi/core_uart.o		\
		osfive/sys/riscv/microsemi/core_timer.o		\
		start.o

KERNEL =
LIBRARIES = libc

CFLAGS =	-O -pipe -g -nostdinc -fno-omit-frame-pointer		\
	-march=rv32g -mabi=ilp32 -fno-builtin-printf			\
	-fno-optimize-sibling-calls -ffreestanding -fwrapv		\
	-fdiagnostics-show-option -fms-extensions -finline-limit=8000	\
	-Wall -Wredundant-decls -Wnested-externs -Wstrict-prototypes	\
	-Wmissing-prototypes -Wpointer-arith -Winline -Wcast-qual	\
	-Wundef -Wno-pointer-sign -Wno-format -Wmissing-include-dirs	\
	-Wno-unknown-pragmas -Werror

all:	_compile _link

clean:	_clean

include osfive/mk/default.mk
include osfive/mk/gnu-toolchain.mk
