#ifndef __SI2183_H__
#define __SI2183_H__

#include <linux/dvb/frontend.h>
#include <linux/i2c.h>

#define SI2183_I2C_TOP_ADDR (0x32 >> 1)
#define SI2183_I2C_QAM_ADDR (0x34 >> 1)


struct si2183_config {
	u8 demod_address;
	/* serial/parallel output */
#define SI2183_PARALLEL_OUTPUT 0
#define SI2183_SERIAL_OUTPUT   1
	u8 output_mode;
#define SI2183_TSCLK_NOT_INVERT 0
#define SI2183_TSCLK_INVERT   1
	u8 tsclk_inv;
#define Si2183_CONFIG_CLK_CLKIO    0
#define Si2183_CONFIG_CLK_XTAL_IN  1
#define Si2183_CONFIG_CLK_MODE_XTAL 2
	u8 clk_mode;
#define Si2183_CONFIG_TUNER_I2CSW_DISABLE    0
#define Si2183_CONFIG_TUNER_I2CSW_ENABLE     1
	u8 i2c_gate_en;
	u8 i2c_adap_id;
	/*compatible c689/c699 and c68a/c69a*/
#define SI2183_TS_MODE_ADAPT 0
#define SI2183_TS_MODE_MANUAL 1
	u8 ts_clk_mode;
	int res_gpio;
};

void si2183_get_ops(struct dvb_frontend_ops *ops, int delivery_system);
int si2183_i2c_detect(u8 addr, int *);

#if defined(CONFIG_DVB_SI2183) || \
	(defined(CONFIG_DVB_SI2183_MODULE) && defined(MODULE))
extern struct dvb_frontend *si2183_attach(struct si2183_config *config, struct i2c_adapter *i2c);
#else
static inline struct dvb_frontend *si2183_attach(struct si2183_config *config, struct i2c_adapter *i2c)
{
	printk(KERN_WARNING "%s: driver disabled by Kconfig\n", __func__);
	return NULL;
}
#endif /* CONFIG_DVB_d_si21xx */

#endif /* __SI2183_H__ */
