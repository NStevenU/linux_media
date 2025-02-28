
#ifndef __RS6000_H__
#define __RS6000_H__

#include <linux/i2c.h>
#include <linux/dvb/frontend.h>

extern struct dvb_frontend *rs6000_attach(struct i2c_adapter *i2c);

#endif /* __RS6000_H__ */
