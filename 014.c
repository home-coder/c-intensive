/*************************************************************************
 > Filename   : 014.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-03-03 17:14:04
 ************************************************************************/

#include <stdio.h>

/* 
   write_bits !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   aw9817_i2c_read(aw9817, reg_addr, &reg_val);
   reg_val &= mask;
   reg_val |= reg_data;
   aw9817_i2c_write(aw9817, reg_addr, reg_val);

* write a new value to an AD1843 bitfield and return the old value.

static int ad1843_write_bits(struct snd_ad1843 *ad1843,
		const struct ad1843_bitfield *field,
		int newval)
{
	int w, mask, oldval, newbits;

	w = ad1843->read(ad1843->chip, field->reg);
	mask = ((1 << field->nbits) - 1) << field->lo_bit;
	oldval = (w & mask) >> field->lo_bit;
	newbits = (newval << field->lo_bit) & mask;
	w = (w & ~mask) | newbits;
	ad1843->write(ad1843->chip, field->reg, w);

	return oldval;
}

 */
