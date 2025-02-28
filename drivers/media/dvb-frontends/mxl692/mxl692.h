/*
    Panasonic MXL692 VSB/QAM demodulator driver

    Copyright (C) 2006 Steven Toth <stoth@linuxtv.org>

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

#ifndef __MXL692_H__
#define __MXL692_H__

#include <linux/dvb/frontend.h>


//for call back
#define FX2_HARDWARE_RESET 0x01
#define FX2_HARDWARE_LNA   0x02
//

struct mxl692_config {
	/* the demodulator's i2c address */
	u8 demod_address;

	/* serial/parallel output */
#define MXL692_PARALLEL_OUTPUT 0
#define MXL692_SERIAL_OUTPUT   1
	u8 output_mode;

	/* GPIO Setting */
#define MXL692_GPIO_OFF 0
#define MXL692_GPIO_ON  1
	u8 gpio;

	/* IF Freq for QAM in KHz, VSB is hardcoded to 5380 */
	u16 qam_if;

	/* Spectral Inversion */
#define MXL692_INVERSION_OFF 0
#define MXL692_INVERSION_ON  1
	u8 inversion;

	/* Return lock status based on tuner lock, or demod lock */
#define MXL692_TUNERLOCKING 0
#define MXL692_DEMODLOCKING 1
	u8 status_mode;

	/* MPEG signal timing */
#define MXL692_MPEGTIMING_CONTINOUS_INVERTING_CLOCK       0
#define MXL692_MPEGTIMING_CONTINOUS_NONINVERTING_CLOCK    1
#define MXL692_MPEGTIMING_NONCONTINOUS_INVERTING_CLOCK    2
#define MXL692_MPEGTIMING_NONCONTINOUS_NONINVERTING_CLOCK 3
	u16 mpeg_timing;

	/* HVR-1600 optimizations (to better work with MXL5005s)
	   Note: some of these are likely to be folded into the generic driver
	   after being regression tested with other boards */
#define MXL692_HVR1600_NOOPTIMIZE 0
#define MXL692_HVR1600_OPTIMIZE   1
	u8 hvr1600_opt;
};

#if defined(CONFIG_DVB_MXL692) || (defined(CONFIG_DVB_MXL692_MODULE) \
	&& defined(MODULE))
extern struct dvb_frontend *mxl692_attach(const struct mxl692_config *config,
					   struct i2c_adapter *i2c);
#else
static inline struct dvb_frontend *mxl692_attach(
	const struct mxl692_config *config,
	struct i2c_adapter *i2c)
{
	printk(KERN_WARNING "%s: driver disabled by Kconfig\n", __func__);
	return NULL;
}
#endif /* CONFIG_DVB_MXL692 */

#endif /* __MXL692_H__ */

/*
 * Local variables:
 * c-basic-offset: 8
 */
