/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xC0DE
#define PRODUCT_ID      0xD001
#define DEVICE_VER 		0x0001
#define MANUFACTURER    CodedWrench
#define PRODUCT         CodedPad
#define DESCRIPTION     CodedWrench KeyPad 

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 4

/* CodedPad PCB default pin-out */
#define MATRIX_ROW_PINS { D0, D4, C6 }
#define MATRIX_COL_PINS { F4, F7, F6, F5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

#define TAPPING_TERM 130

#endif
