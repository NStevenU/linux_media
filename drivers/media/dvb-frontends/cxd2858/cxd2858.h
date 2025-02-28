#ifndef __CXD2858_H__
#define __CXD2858_H__
#include <linux/i2c.h>
#include <media/dvb_frontend.h>

#include "sony_i2c.h"
#include "sony_integ_dvbt_t2.h"
#include "sony_tunerdemod.h"
#include "sony_tunermodule.h"
#include "sony_integ_dvbt_t2.h"
#include "sony_tunerdemod_dvbt_monitor.h"
#include "sony_tunerdemod_dvbt2_monitor.h"
#include "sony_tunerdemod_isdbt_monitor.h"
#include "sony_integ_isdbt.h"
#include "sony_devio_i2c.h"


#define	 SONY_FE_OFDM  0
#define	 SONY_FE_ISDBT  1


struct cxd2858_config {
	u8 demod_address;
	/* serial/parallel output */
#define CXD2858_PARALLEL_OUTPUT 0
#define CXD2858_SERIAL_OUTPUT   1
	u8 output_mode;
#define CXD2858_TSCLK_NOT_INVERT 0
#define CXD2880_TSCLK_INVERT   1
	u8 tsclk_inv;
#define CXD2858_CONFIG_CLK_CLKIO    0
#define CXD2858_CONFIG_CLK_XTAL_IN  1
#define CXD2858_CONFIG_CLK_MODE_XTAL 2
    u8 clk_mode;
#define CXD2858_CONFIG_TUNER_I2CSW_DISABLE    0
#define CXD2858_CONFIG_TUNER_I2CSW_ENABLE     1
    u8 i2c_gate_en;
/*compatible c689/c699 and c68a/c69a*/
#define CXD2858_TS_MODE_ADAPT 0
#define CXD2858_TS_MODE_MANUAL 1
    u8 ts_clk_mode;
};

typedef struct sony_demod_driver{
	sony_tunerdemod_t       tunerDemod;    /**< Main IC driver struct instance */
	sony_i2c_t 				I2c;
	sony_regio_t             regio;         /**< Register I/O struct instance */
	sony_integ_dvbt_t2_scan_param_t t_scanParam;
	sony_integ_isdbt_scan_param_t 	i_scanParam;			/*isdbt*/
} sony_demod_driver_t;

struct cxd2858_state {
	sony_demod_driver_t *pDriver;
	sony_dtv_system_t 	 system;

	/* configuration settings */
	struct cxd2858_config *config;
	struct i2c_adapter *i2c;
	struct dvb_frontend frontend;

	enum fe_modulation cur_modulation;
    u32 cur_frequency;
	u8 inversion;
	uint8_t mixed;
    u8 numPLPs;
    u8 plpIds[255];
};
extern struct dvb_frontend *cxd2858_attach(struct cxd2858_config *config, struct i2c_adapter *i2c);

#endif /*__CXD2858_H__*/

