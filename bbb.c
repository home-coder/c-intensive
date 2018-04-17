/*************************************************************************
 > Filename   : bbb.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-03-03 16:55:42
 ************************************************************************/

#include <stdio.h>

static int aw9817_i2c_write(struct aw9817 *aw9817, unsigned char reg_addr, unsigned char reg_data)
{
	struct i2c_client *client = aw9817->i2c;
	unsigned char retry;

	client->addr = reg_addr;
	while (retry < I2C_TRANSFER_ENTRIES) {
		ret = i2c_master_send(client, reg_data, 1);
		if (ret < 0) {
			pr_err("i2c write %x errno=%d\n", reg_data, ret);
		} else {
			break;
		}
		retry++;
		msleep(I2C_TRANSFER_DELAY);
	}
}

static int aw9817_i2c_write_bits(struct aw9817 *aw9817, unsigned char reg_addr, unsigned char mask, unsigned char reg_data)
{
	unsigned char reg_val;

	aw9817_i2c_read(aw9817, reg_addr, &reg_val);
	reg_val &= mask;
	reg_val |= reg_data;
	aw9817_i2c_write(aw9817, reg_addr, reg_val);

	return 0;
}
