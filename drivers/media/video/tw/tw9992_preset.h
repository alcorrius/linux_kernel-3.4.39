#ifndef _MT9D111_PRESET_H
#define _MT9D111_PRESET_H

struct reg_val {
    u8 reg;
    u8 val;
};

static u8 TW9992_DataSet[] = {
	0x7a, 0x00, //using Shadow Register so no Input cropping setting for NTSC
	0x00, 0x92,
	0x01, 0x00,
	0x02, 0x46,
	0x03, 0x78,
	0x04, 0x00,
	0x05, 0x09,
	0x06, 0x00,
	0x07, 0x02,
	0x08, 0x12,
	0x09, 0xF0,
	0x0A, 0x09,
	0x0B, 0xD1,
	0x0C, 0xCC,
	0x0D, 0x00,
	0x10, 0x00,
	0x11, 0x64,
	0x12, 0x11,
	0x13, 0x80,
	0x14, 0x80,
	0x15, 0x00,
	0x17, 0x80,
	0x18, 0x44,
	0x19, 0x06,
	0x1A, 0x10,
	0x1B, 0x00,
	0x1C, 0x0F,		//0x08,
	0x1D, 0x7F,
	0x1F, 0x00,
	0x20, 0x50,
	0x21, 0x22,
	0x22, 0xF0,
	0x23, 0xD8,
	0x24, 0xBC,
	0x25, 0xB8,
	0x26, 0x44,
	0x27, 0x38,
	0x28, 0x00,
	0x29, 0x00,
	0x2A, 0x78,
	0x2B, 0x44,
	0x2C, 0x30,
	0x2D, 0x14,
	0x2E, 0xA5,
	0x2F, 0xE0,
	0x30, 0x00,
	0x31, 0x10,
	0x32, 0xFF,
	0x33, 0x05,
	0x34, 0x1A,
	0x35, 0x00,
	0x36, 0x7A,			//0x5A, requested by Daniel Kim, 09242014
	0x37, 0x18,
	0x38, 0xDD,
	0x39, 0x00,
	0x3A, 0x30,
	0x3B, 0x00,
	0x3C, 0x00,
	0x3D, 0x00,
	0x3F, 0x1A,
	0x40, 0x80,
	0x41, 0x00,
	0x42, 0x00,
	0x48, 0x02,
	0x49, 0x00,
	0x4A, 0x81,
	0x4B, 0x0A,
	0x4C, 0x00,
	0x4D, 0x01,
	0x4E, 0x01,
	0x50, 0x00,
	0x51, 0x00,
	0x52, 0x00,
	0x53, 0x00,
	0x54, 0x06,
	0x55, 0x00,
	0x56, 0x00,
	0x57, 0x00,
	0x58, 0x00,
	0x60, 0x00,
	0x61, 0x00,
	0x62, 0x00,
	0x63, 0x00,
	0xC0, 0x06,
	0xC1, 0x20,

	0x71, 0xA5,
	0xA2, 0x30,
	0x70, 0x01, //start with MIPI Normal operation

	0x07, 0x02, //using Shadow Register so no Input cropping setting for NTSC
	0x08, 0x15,
	0x09, 0xf0,
	0x0a, 0x14,
	0x0b, 0xd0,

	0xff, 0xff
};

static u8 TW9992_NTSC_Int[] = {

	0x7a, 0x00, //using Shadow Register so no Input cropping setting for NTSC

	0x07, 0x02,
	0x08, 0x15,
	0x09, 0xf0,
	0x0a, 0x14,
	0x0b, 0xd0,

	0xff, 0xff
};



static u8 TW9992_PAL_Int[] = {

	0x7a, 0x00, //using Shadow Register so no Input cropping setting for PAL

	0x07, 0x12,
	0x08, 0x17,
	0x09, 0x20,
	0x0a, 0x0f,
	0x0b, 0xd0,

	0xff, 0xff
};

#endif
