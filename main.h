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

#ifndef	_MAIN_H_
#define	_MAIN_H_

#define	BOARD_OSC_FREQ	64000000

#define	PIN_LED_0	0
#define	PIN_LED_1	1
#define	PIN_LED_2	2
#define	PIN_LED_3	3

#define	COREUARTAPB0_BASE_ADDR		0x70001000UL
#define	COREGPIO_BASE_ADDR		0x70002000UL
#define	COREGPIO_IN_BASE_ADDR		0x70002000UL
#define	CORETIMER0_BASE_ADDR		0x70003000UL
#define	CORETIMER1_BASE_ADDR		0x70004000UL
#define	COREGPIO_OUT_BASE_ADDR		0x70005000UL
#define	FLASH_CORE_SPI_BASE		0x70006000UL
#define	CORE16550_BASE_ADDR		0x70007000UL

#endif /* !_MAIN_H_ */
