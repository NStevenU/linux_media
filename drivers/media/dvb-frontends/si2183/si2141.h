#ifndef __TUNER_SI2141_H_
#define __TUNER_SI2141_H_

#include <linux/i2c.h>

typedef enum{
    GT_TUNER_SI2148 = 0,
    GT_TUNER_SI2141 = 1,
}tuner_id_t;

struct si2141_config {
	int id;
	u8 i2c_address;
};

#if defined(CONFIG_DVB_SI2183) || \
	(defined(CONFIG_DVB_SI2183_MODULE) && defined(MODULE))
extern struct dvb_frontend *si2141_attach(struct dvb_frontend *fe,
					 struct i2c_adapter *i2c,
					 struct si2141_config *config);
#else
static inline struct dvb_frontend *si2141_attach(struct dvb_frontend *fe,
					 struct i2c_adapter *i2c,
					 struct si2141_config *config)
{
	printk(KERN_WARNING "%s: driver disabled by Kconfig\n", __func__);
	return NULL;
}
#endif

#endif /*__TUNER_SI2141_H_*/

