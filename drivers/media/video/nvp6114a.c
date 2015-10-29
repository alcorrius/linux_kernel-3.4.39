#include <linux/i2c.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/switch.h>
#include <linux/delay.h>

#include <media/v4l2-device.h>
#include <media/v4l2-subdev.h>
#include <media/v4l2-ctrls.h>

#include <mach/platform.h>
#include <mach/soc.h>

#include "nvp6114a.h"
#include "nvp6114a-preset.h"

#define AHD_DEV_NAME	"NVP6114A"
#define NVP6114A	0x85
#define PID 0xF4

static struct dev_state nvp6114a;

/**
 *util functions
 */
static inline struct dev_state *to_state(struct v4l2_subdev *sd)
{
	return container_of(sd, struct dev_state, sd);
}

static bool check_id(struct i2c_client *client)
{
	i2c_smbus_write_byte_data(client, 0XFF, 0x00);
	u8 pid = i2c_smbus_read_byte_data(client, PID);
	if( pid == NVP6114A )
		return true;

	printk(KERN_ERR "fail to check id: 0x%02X\n", pid);
		return false;
}

static int _i2c_read_byte(struct i2c_client *client, u8 addr, u8 *data)
{
	s8 i = 0;
	s8 ret = 0;
	u8 buf = 0;
	
	struct i2c_msg msg[2];

	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].len = 1;
	msg[0].buf = &addr;

	msg[1].addr = client->addr;
	msg[1].flags = I2C_M_RD;
	msg[1].len = 1;
	msg[1].buf = &buf;

	for(i=0; i<I2C_RETRY_CNT; i++) {
		ret = i2c_transfer(client->adapter, msg, 2);
		if(likely(ret ==  2))
			break;
	}

	if (unlikely(ret != 2)) {
		dev_err(&client->dev, "%s failed reg:0x%02x\n", __func__, addr);
		return -EIO;	
	}

	*data = buf;

	return 0;
}


static int _i2c_write_byte(struct i2c_client *client, u8 addr, u8 val)
{
	s8 i = 0;
	s8 ret = 0;
	u8 buf[2];
	struct i2c_msg msg;

	msg.addr = client->addr;
	msg.flags = 0;
	msg.len = 2;
	msg.buf = buf;

	buf[0] = addr;
	buf[1] = val;

	for(i=0; i<I2C_RETRY_CNT; i++) {
		ret = i2c_transfer(client->adapter, &msg, 1);
		if(likely(ret == 1))
			break;
	}

	if (ret !=  1) {
		printk(KERN_ERR "%s: failed to write addr 0x%x, val 0x%x\n", __func__, addr, val);
		return -EIO;
	}

	return 0;
}


static int nvp6114a_initialize_ctrls(struct dev_state *me)
{
	return 0;
}

static int nvp6114a_write_table(struct i2c_client *client,
								unsigned char addr, 
								unsigned char *tbl_ptr, unsigned char tbl_cnt)
{
	unsigned char i=0;

	for(i=0; i<tbl_cnt; i++)
	{
		printk("%s : reg_addr = 0x%02x, reg_val = 0x%02x\n", __func__, (addr+i), *(tbl_ptr+i));

		if(_i2c_write_byte(client, (addr+i), *(tbl_ptr+i)) != 0)
		{
			printk(KERN_ERR "%s : fail to write addr 0x%02X, val 0x%02X\n", __func__, (addr+i), *(tbl_ptr+i));
			//break;
		}
	}	

	return 0;
}

static int nvp6114a_write_data(struct i2c_client *client, u8 write_addr, unsigned char reg_val[])
{
	if(_i2c_write_byte(client, 0xFF, write_addr) == 0) 
	{
		printk("%s - write_addr : 0x%02X\n", __func__, write_addr);

		nvp6114a_write_table(client, 0x00, reg_val, 254); 
	}

	return 0;
}

static void nvp6114a_device_init(struct i2c_client *client)
{
	nvp6114a_write_data(client, 0x00, NVP6114A_720_B0_30P_Buf);
	nvp6114a_write_data(client, 0x01, NVP6114A_720_B1_30P_Buf);
	nvp6114a_write_data(client, 0x02, NVP6114A_720_B2_30P_Buf);
	nvp6114a_write_data(client, 0x03, NVP6114A_720_B3_30P_Buf);
//	nvp6114a_write_data(client, 0x04, NVP6114A_720_B4_30P_Buf);
	nvp6114a_write_data(client, 0x05, NVP6114A_720_B5_30P_Buf);
/*
	nvp6114a_write_data(client, 0x06, NVP6114A_720_B6_30P_Buf);
	nvp6114a_write_data(client, 0x07, NVP6114A_720_B7_30P_Buf);
	nvp6114a_write_data(client, 0x08, NVP6114A_720_B8_30P_Buf);
*/
	nvp6114a_write_data(client, 0x09, NVP6114A_720_B9_30P_Buf);
	nvp6114a_write_data(client, 0x0A, NVP6114A_720_BA_30P_Buf);
//	nvp6114a_write_data(client, 0x0B, NVP6114A_720_BB_30P_Buf);
}


static int nvp6114a_s_stream(struct v4l2_subdev *sd, int enable)
{
	struct dev_state *state = to_state(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);	
	int i2c_id = i2c_adapter_id(client->adapter);
	unsigned char data;

	printk("+++ %s +++\n", __func__);

	if( enable )
	{
		if( !state->first )
		{
			if(!check_id(client))
				return -EINVAL;
			
			if (_i2c_read_byte(client, PID, &data) == 0)
				printk("nvp6114a reg =0xF4, data = 0x%02X\n", data);

			nvp6114a_device_init(client);

			//state->first = true;
		}
	}

	printk("--- %s ---\n", __func__);

	return 0;
}

static int nvp6114a_s_fmt(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh, 
	struct v4l2_subdev_format *fmt)
{
	int err=0;
	struct v4l2_mbus_framefmt *_fmt = &fmt->format;
	struct dev_state *state = to_state(sd);
	
	vmsg("%s\n", __func__);

	state->width = _fmt->width;
	state->height = _fmt->height;

	printk("%s : mode %d, %dx%d\n", __func__, state->mode, state->width, state->height);

	return err;
}

static int nvp6114a_s_power(struct v4l2_subdev *sd, int on)
{
	vmsg("%s: %d\n", __func__, on);
	return 0;
}

static const struct v4l2_subdev_core_ops nvp6114a_core_ops = {
	.s_power = nvp6114a_s_power,
};

static const struct v4l2_subdev_video_ops nvp6114a_video_ops = {
	.s_stream	=	nvp6114a_s_stream,
};

static const struct v4l2_subdev_pad_ops nvp6114a_pad_ops = {
	.set_fmt = nvp6114a_s_fmt,
};

static const struct v4l2_subdev_ops nvp6114a_ops = {
	.core = &nvp6114a_core_ops,
	.video = &nvp6114a_video_ops,
	.pad = &nvp6114a_pad_ops,
};

/**
 * media_entity_operations
 */
static int _link_setup(struct media_entity *entity,
						const struct media_pad *local,
						const struct media_pad *remote, u32 flags)
{
	/* printk("%s: entered\n", __func__); */
	return 0;
}

static const struct media_entity_operations nvp6114a_media_ops = {
	.link_setup = _link_setup,
};

static int nvp6214_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct dev_state *state = &nvp6114a;
	struct v4l2_subdev *sd;
	int ret;

	sd = &state->sd;
	strcpy(sd->name, id->name);

	v4l2_i2c_subdev_init(sd, client, &nvp6114a_ops);

	sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	state->pad.flags = MEDIA_PAD_FL_SOURCE;
	sd->entity.type = MEDIA_ENT_T_V4L2_SUBDEV_SENSOR;
	sd->entity.ops = &nvp6114a_media_ops;
	ret = media_entity_init(&sd->entity, 1, &state->pad, 0);
	if (ret < 0) {
		dev_err(&client->dev, "%s: failed to media_entiti_init()\n", __func__);
		return -ENOENT;
	};

	i2c_set_clientdata(client, sd);
	state->i2c_client = client;
	state->first = false;

	dev_info(&client->dev, "nvp6114a has been probed\n");

	return 0;
}

static int nvp6114a_remove(struct i2c_client *client)
{
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	v4l2_device_unregister_subdev(sd);
	v4l2_ctrl_handler_free(sd->ctrl_handler);
	media_entity_cleanup(&sd->entity);
	return 0;
}

static const struct i2c_device_id nvp6114a_id[] = {
	{ AHD_DEV_NAME, 0},
	{}
};
MODULE_DEVICE_TABLE(i2c, nvp6114a_id);

static struct i2c_driver nvp6114a_i2c_driver = {
	.driver = {
		.name = AHD_DEV_NAME,
		.owner = THIS_MODULE,
	}, 
	.probe = nvp6214_probe,
	.remove = __devexit_p(nvp6114a_remove),
	.id_table = nvp6114a_id,
};

static int __init nvp6114a_init(void)
{
	int ret;
	ret = i2c_add_driver(&nvp6114a_i2c_driver);
	if (ret != 0 )
	{
		printk(KERN_ERR "Failed to register nvp6114a I2C Drier: %d\n", ret);
		return ret;
	}

	return 0;
}

static void __exit nvp6114a_exit(void)
{
	i2c_del_driver(&nvp6114a_i2c_driver);
}

module_init(nvp6114a_init);
module_exit(nvp6114a_exit);

MODULE_DESCRIPTION("NVP6114A AHD Sensor Driver");
MODULE_AUTHOR("<jkchoi@nexell.co.kr>");
MODULE_LICENSE("GPL");
