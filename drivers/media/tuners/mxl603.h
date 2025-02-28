/*
    MaxLinear MXL603 VSB/QAM/DVBT tuner driver

    Copyright (C) 2008 MaxLinear
    Copyright (C) 2008 Steven Toth <stoth@linuxtv.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifndef __MXL603_H
#define __MXL603_H

#include <linux/i2c.h>
#include <media/dvb_frontend.h>

struct mxl603_config {

	/* 7 bit i2c address */
	u8 i2c_address;

#define IF_FREQ_3650000HZ    3650000
#define IF_FREQ_4000000HZ    4000000
#define IF_FREQ_4100000HZ    4100000
#define IF_FREQ_4150000HZ    4150000
#define IF_FREQ_4500000HZ    4500000
#define IF_FREQ_4570000HZ    4570000
#define IF_FREQ_5000000HZ    5000000
#define IF_FREQ_5380000HZ    5380000
#define IF_FREQ_6000000HZ    6000000
#define IF_FREQ_6280000HZ    6280000
#define IF_FREQ_7200000HZ    7200000
#define IF_FREQ_8250000HZ    8250000
#define IF_FREQ_35250000HZ    35250000
#define IF_FREQ_36000000HZ    36000000
#define IF_FREQ_36150000HZ    36150000
#define IF_FREQ_36650000HZ    36650000
#define IF_FREQ_44000000HZ    44000000
	u32 if_freq;

#define CRYSTAL_FREQ_16000000HZ  16000000
#define CRYSTAL_FREQ_24000000HZ  24000000
	u32 xtal_freq;


#define MXL_DIV_OUT_1	0
#define MXL_DIV_OUT_4	1
	u8 div_out;

#define MXL_CLOCK_OUT_DISABLE	0
#define MXL_CLOCK_OUT_ENABLE	1
	u8 clock_out;
	u8 osc_clk; /* in MHz, selectable values: 4,16,18,20,22,24,26,28 */
	u8 signalMode;
	u32 out_freq;

#define MXL_SINGLESUPPLY_3_3V_DISABLE	0
#define MXL_SINGLESUPPLY_3_3V_ENABLE	1
	u8 single_Supply;

};

#if defined(CONFIG_MEDIA_TUNER_MXL603) || \
	(defined(CONFIG_MEDIA_TUNER_MXL603_MODULE) && defined(MODULE))
extern struct dvb_frontend *mxl603_attach(struct dvb_frontend *fe,
					    struct i2c_adapter *i2c,
					    struct mxl603_config *config);
#else
static inline struct dvb_frontend *mxl603_attach(struct dvb_frontend *fe,
					    struct i2c_adapter *i2c,
					    struct mxl603_config *config)
{
	printk(KERN_WARNING "%s: driver disabled by Kconfig\n", __func__);
	return NULL;
}
#endif /* CONFIG_DVB_TUNER_MXL603 */

#endif /* __MXL603_H */

