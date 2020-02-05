/* Copyright 2019 Neil Kettle
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#ifdef RIGHT_HALF
# include <stdint.h>
# include "i2c_master.h"

// I2C aliases and register addresses (see "mcp23018.md")
# define I2C_ADDR        0b0100000
# define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
# define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )
# define IODIRA          0x00            // i/o direction register
# define IODIRB          0x01
# define GPPUA           0x0C            // GPIO pull-up resistor register
# define GPPUB           0x0D
# define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
# define GPIOB           0x13
# define OLATA           0x14            // output latch register
# define OLATB           0x15

extern i2c_status_t mcp23018_status;
# define MCP23018_I2C_TIMEOUT 100

uint8_t init_mcp23018(void);
#endif

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

/*
 *  LEFT HAND                                        RIGHT HAND
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐       ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │ k00 │ k01 │ k02 │ k03 │ k04 │ k05 │ k06 │       │ k07 │ k08 │ k09 │ k0A │ k0B │ k0C │ k0D      │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘    ┌--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │ k10    │ k11 │ k12 │ k13 │ k14 │ k15 │       │ k16 │ k17 │ k18 │ k19 │ k1A │ k1B │ k1C │ k1D   │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐      └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │ k20     │ k21 │ k22 │ k23 │ k24 │ k25 │       │ k26 │ k27 │ k28 │ k29 │ k2A │ k2B │ k2C        │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐      └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │ k30      │ k31 │ k32 │ k33 │ k34 │ k35 │       │ k36 │ k37 │ k38 │ k39 │ k3A │ k3B │ k3C │ k3D │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘      ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │ k40  │ k41 │ k42  │ k43         │ k45 │       │ k46           │ k48   │ k4A  │ k4B │ k4C │ k4D │
 * └------┴-----┴------┴-------------┴-----┘       └---------------┴-------┴------┴-----┴-----┴-----┘
 */
#define LAYOUT_ymdk_sp64(                                       \
    k00,k01,k02,k03,k04,k05,k06,    k07,k08,k09,k0A,k0B,k0C,k0D,\
    k10,k11,k12,k13,k14,k15,    k16,k17,k18,k19,k1A,k1B,k1C,k1D,\
    k20,k21,k22,k23,k24,k25,    k26,k27,k28,k29,k2A,k2B,k2C,    \
    k30,k31,k32,k33,k34,k35,    k36,k37,k38,k39,k3A,k3B,k3C,k3D,\
    k40,k41,k42,k43,     k45,    k46,      k48, k4A,k4B,k4C,k4D \
    )                       \
   /* matrix positions */   \
   {                        \
    { k40,     k30,     k20,     k10,     k00,     XXXXXXX },   \
    { k41,     k31,     k21,     k11,     k01,     XXXXXXX },   \
    { k42,     k32,     k22,     k12,     k02,     XXXXXXX },   \
    { k43,     k33,     k23,     k13,     k03,     XXXXXXX },   \
    { k45,     k34,     k24,     k14,     k04,     XXXXXXX },   \
    { k06,     k35,     k25,     k15,     k05,     XXXXXXX },   \
    { XXXXXXX, XXXXXXX, XXXXXXX, k16,     k06,     XXXXXXX },   \
    { XXXXXXX, XXXXXXX, k25,     k16,     k06,     XXXXXXX },   \
    { k46,     k36,     k26,     k17,     k07,     k06     },   \
    { k48,     k37,     k27,     k18,     k08,     XXXXXXX },   \
    { k4A,     k38,     k28,     k19,     k09,     XXXXXXX },   \
    { k4B,     k39,     k29,     k1A,     k0A,     XXXXXXX },   \
    { k4C,     k3A,     k2A,     k1B,     k0B,     XXXXXXX },   \
    { k4D,     k3B,     k2B,     k1C,     k0C,     XXXXXXX },   \
    { k3D,     k3C,     k2C,     k1D,     k0D,     XXXXXXX }    \
   }

#define LAYOUT LAYOUT_sp64
