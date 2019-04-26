/*-
 * Copyright (c) 2018 Ruslan Bukin <br@bsdpad.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#include <sys/console.h>
#include <sys/thread.h>
#include <sys/systm.h>

#include <riscv/microsemi/core_uart.h>
#include <riscv/microsemi/core_gpio.h>
#include <riscv/microsemi/core_timer.h>

#include <main.h>

static struct core_uart_softc uart_sc;
static struct core_gpio_softc gpio_sc;
static struct core_gpio_softc gpio_out_sc;
static struct core_timer_softc timer0_sc;
static struct core_timer_softc timer1_sc;

void
udelay(uint32_t usec)
{

	core_timer_udelay(&timer0_sc, usec, BOARD_OSC_FREQ / 64);
}

static void
uart_putchar(int c, void *arg)
{
	struct core_uart_softc *sc;

	sc = arg;

	if (sc == NULL)
		return;

	if (c == '\n')
		core_uart_putc(sc, '\r');

	core_uart_putc(sc, c);
}

static void
miv_init(void)
{

	core_uart_init(&uart_sc, COREUARTAPB0_BASE_ADDR,
	    BOARD_OSC_FREQ, 115200, CTRL2_DATA_8_BITS);
	core_gpio_init(&gpio_sc, COREGPIO_IN_BASE_ADDR);
	core_gpio_init(&gpio_out_sc, COREGPIO_OUT_BASE_ADDR);

	core_timer_init(&timer0_sc, CORETIMER0_BASE_ADDR,
	    0xffffffff, PRESCALER_DIV_64);
	core_timer_init(&timer1_sc, CORETIMER1_BASE_ADDR,
	    0xffffffff, PRESCALER_DIV_64);
}

void
main(void)
{
	int i;

	zero_bss();
	md_init();

	miv_init();

	console_register(uart_putchar, (void *)&uart_sc);

	i = PIN_LED_0;

	while (1) {
		printf("Hello World! Blinking LED number %d\n", i);

		core_gpio_output(&gpio_out_sc, i, 1);
		udelay(100000);
		core_gpio_output(&gpio_out_sc, i, 0);

		if (++i > PIN_LED_3)
			i = PIN_LED_0;
	}
}
