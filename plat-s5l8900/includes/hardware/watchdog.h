/*
 * Copyright (c) 2013 fergy <ramon.rebersak@gmail.com>
 * http://idroidproject.org
 *
 * This code is based on Samsung S3C platform
  
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * S5L8900X Watchdog timer control
 */


#define S5L8900X_WATCHDOG	0x3E300000

#ifndef __ASM_ARCH_REGS_S5L8900X_WATCHDOG_H
#define __ASM_ARCH_REGS_S5L8900X_WATCHDOG_H

#define S5L8900X_WDOGREG(x) ((x) + S5L8900X_VA_WATCHDOG)

#define S5L8900X_WTCON IPHONE_WDOGREG(0x00)
#define S5L8900X_WTDAT IPHONE_WDOGREG(0x04)
#define S5L8900X_WTCNT IPHONE_WDOGREG(0x08)

#define IPHONE_WTCON_RSTEN (0x01)
#define IPHONE_WTCON_INTEN (1<<2)
#define IPHONE_WTCON_ENABLE (1<<5)

#define IPHONE_WTCON_DIV16 (0<<3)
#define IPHONE_WTCON_DIV32 (1<<3)
#define IPHONE_WTCON_DIV64 (2<<3)
#define IPHONE_WTCON_DIV128 (3<<3)

#define IPHONE_WTCON_PRESCALE(x) ((x) << 8)
#define IPHONE_WTCON_PRESCALE_MASK (0xff00)

#endif /* __ASM_ARCH_REGS_S5L8900X_WATCHDOG_H */

