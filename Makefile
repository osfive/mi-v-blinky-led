APP =		mi-v-blinky-led
ARCH =		riscv

CC =		${CROSS_COMPILE}gcc
LD =		${CROSS_COMPILE}ld
OBJCOPY =	${CROSS_COMPILE}objcopy

LDSCRIPT =	${.CURDIR}/ldscript

OBJECTS =	main.o						\
		osfive/sys/riscv/microsemi/core_gpio.o		\
		osfive/sys/riscv/microsemi/core_uart.o		\
		osfive/sys/riscv/microsemi/core_timer.o		\
		osfive/sys/kern/subr_prf.o			\
		osfive/sys/kern/subr_console.o			\
		osfive/lib/libc/stdio/printf.o			\
		osfive/lib/libc/string/strlen.o			\
		osfive/lib/libc/string/bzero.o			\
		start.o

CFLAGS =	-O -pipe -g -nostdinc -fno-omit-frame-pointer		\
	-march=rv32g -mabi=ilp32 -fno-builtin-printf			\
	-fno-optimize-sibling-calls -ffreestanding -fwrapv		\
	-fdiagnostics-show-option -fms-extensions -finline-limit=8000	\
	-Wall -Wredundant-decls -Wnested-externs -Wstrict-prototypes	\
	-Wmissing-prototypes -Wpointer-arith -Winline -Wcast-qual	\
	-Wundef -Wno-pointer-sign -Wno-format -Wmissing-include-dirs	\
	-Wno-unknown-pragmas -Werror

all:	__compile __link

clean:	__clean

.include "osfive/mk/bsd.mk"
