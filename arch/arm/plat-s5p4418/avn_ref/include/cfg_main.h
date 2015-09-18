/*------------------------------------------------------------------------------
 *
 *	Copyright (C) 2009 Nexell Co., Ltd All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *  AND	WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS
 *  FOR A PARTICULAR PURPOSE.
 *
 *	Module     : System memory config
 *	Description:
 *	Author     : Platform Team
 *	Export     :
 *	History    :
 *	   2009/05/13 first implementation
 ------------------------------------------------------------------------------*/
#ifndef __CFG_MAIN_H__
#define __CFG_MAIN_H__

#include <nx_type.h>

//------------------------------------------------------------------------------
// PLL input crystal
//------------------------------------------------------------------------------
#define CFG_SYS_PLLFIN							24000000UL

/*------------------------------------------------------------------------------
 * 	System Name
 */
#define	CFG_SYS_CPU_NAME						"s5p4418"
#define	CFG_SYS_BOARD_NAME						"s5p4418-avn_ref"

/*------------------------------------------------------------------------------
 * 	BUS config
 */
#define CFG_BUS_RECONFIG_ENB					0

/*------------------------------------------------------------------------------
 * 	Uart
 */
#define CFG_UART_DEBUG_CH						0	/* For Low level debug */
#define	CFG_UART_DEBUG_BAUDRATE					115200
#define	CFG_UART_CLKGEN_CLOCK_HZ				14750000	/* 50000000 */

/*------------------------------------------------------------------------------
 * 	Timer List (SYS = Source, EVT = Event, WDT = WatchDog)
 */
#define	CFG_TIMER_SYS_TICK_CH					0
#define	CFG_TIMER_EVT_TICK_CH					1

/*------------------------------------------------------------------------------
 * 	Extern Ethernet
 */
#define CFG_ETHER_EXT_PHY_BASEADDR          	0x04000000	// DM9000: CS1
#define	CFG_ETHER_EXT_IRQ_NUM					(IRQ_GPIO_C_START + 26)

/*------------------------------------------------------------------------------
 * 	Nand (HWECC)
 */
/* MTD */
#define CFG_NAND_ECC_BYTES 						1024
#define CFG_NAND_ECC_BITS               		40			/* 512 - 4,8,16,24 1024 - 24,40,60 */
//#define CFG_NAND_ECCIRQ_MODE

/* FTL */
#define CFG_NAND_FTL_START_BLOCK				0x6000000	/* byte address, Must Be Multiple of 8MB */

/*------------------------------------------------------------------------------
 *	Nand (GPIO)
 */
#define CFG_IO_NAND_nWP							(PAD_GPIO_C + 27)		/* GPIO */

/*------------------------------------------------------------------------------
 * 	Display (DPC and MLC)
 */
/* Primary */
#define CFG_DISP_PRI_SCREEN_LAYER               0
#define CFG_DISP_PRI_SCREEN_RGB_FORMAT          MLC_RGBFMT_A8R8G8B8
#define CFG_DISP_PRI_SCREEN_PIXEL_BYTE	        4
#define CFG_DISP_PRI_SCREEN_COLOR_KEY	        0x090909

#define CFG_DISP_PRI_VIDEO_PRIORITY				2	// 0, 1, 2, 3
#define CFG_DISP_PRI_BACK_GROUND_COLOR	     	0x0

#define CFG_DISP_PRI_MLC_INTERLACE              CFALSE

#define	CFG_DISP_PRI_LCD_WIDTH_MM				155
#define	CFG_DISP_PRI_LCD_HEIGHT_MM				90

#define CFG_DISP_PRI_RESOL_WIDTH          		1024	// X Resolution
#define CFG_DISP_PRI_RESOL_HEIGHT				 600	// Y Resolution

#define CFG_DISP_PRI_HSYNC_SYNC_WIDTH           20
#define CFG_DISP_PRI_HSYNC_BACK_PORCH           140
#define CFG_DISP_PRI_HSYNC_FRONT_PORCH          160
#define CFG_DISP_PRI_HSYNC_ACTIVE_HIGH          CTRUE
#define CFG_DISP_PRI_VSYNC_SYNC_WIDTH           3
#define CFG_DISP_PRI_VSYNC_BACK_PORCH           20
#define CFG_DISP_PRI_VSYNC_FRONT_PORCH          12
#define CFG_DISP_PRI_VSYNC_ACTIVE_HIGH 	        CTRUE

#define CFG_DISP_PRI_CLKGEN0_SOURCE             DPC_VCLK_SRC_PLL0
#define CFG_DISP_PRI_CLKGEN0_DIV                16
#define CFG_DISP_PRI_CLKGEN0_DELAY              0
#define CFG_DISP_PRI_CLKGEN0_INVERT				0
#define CFG_DISP_PRI_CLKGEN1_SOURCE             DPC_VCLK_SRC_VCLK2
#define CFG_DISP_PRI_CLKGEN1_DIV                1
#define CFG_DISP_PRI_CLKGEN1_DELAY              0
#define CFG_DISP_PRI_CLKGEN1_INVERT				0
#define CFG_DISP_PRI_CLKSEL1_SELECT				0
#define CFG_DISP_PRI_PADCLKSEL                  DPC_PADCLKSEL_VCLK	/* VCLK=CLKGEN1, VCLK12=CLKGEN0 */

#define	CFG_DISP_PRI_PIXEL_CLOCK				800000000/CFG_DISP_PRI_CLKGEN0_DIV

#define	CFG_DISP_PRI_OUT_SWAPRB 				CFALSE
#define CFG_DISP_PRI_OUT_FORMAT                 DPC_FORMAT_RGB666
#define CFG_DISP_PRI_OUT_YCORDER                DPC_YCORDER_CbYCrY
#define CFG_DISP_PRI_OUT_INTERLACE              CFALSE
#define CFG_DISP_PRI_OUT_INVERT_FIELD           CFALSE
#define CFG_DISP_LCD_MPY_TYPE						0

/*------------------------------------------------------------------------------
 * 	LVDS
 */
#define CFG_DISP_LVDS_LCD_FORMAT                LVDS_LCDFORMAT_JEIDA

/*------------------------------------------------------------------------------
 * 	PWM
 */
#define CFG_LCD_PRI_PWM_CH						0
#define CFG_LCD_PRI_PWM_FREQ					30000
#define CFG_LCD_PRI_PWM_DUTYCYCLE				50		/* (%) */

/*------------------------------------------------------------------------------
 * 	Audio I2S (0, 1, 2)
 */
#define	CFG_AUDIO_I2S0_MASTER_MODE				CTRUE	// CTRUE
#define	CFG_AUDIO_I2S0_TRANS_MODE				0		// 0:I2S, 1:Left 2:Right justified */
#define	CFG_AUDIO_I2S0_FRAME_BIT				32		// 32, 48
#define	CFG_AUDIO_I2S0_SAMPLE_RATE				48000
#define	CFG_AUDIO_I2S0_PRE_SUPPLY_MCLK			1

#define	CFG_AUDIO_I2S1_MASTER_MODE				CTRUE	// CTRUE
#define	CFG_AUDIO_I2S1_TRANS_MODE				0		// 0:I2S, 1:Left 2:Right justified */
#define	CFG_AUDIO_I2S1_FRAME_BIT				32		// 32, 48
#define	CFG_AUDIO_I2S1_SAMPLE_RATE				48000
#define	CFG_AUDIO_I2S1_PRE_SUPPLY_MCLK			1

#define	CFG_AUDIO_I2S2_MASTER_MODE				CTRUE	// CTRUE
#define	CFG_AUDIO_I2S2_TRANS_MODE				0		// 0:I2S, 1:Left 2:Right justified */
#define	CFG_AUDIO_I2S2_FRAME_BIT				32		// 32, 48
#define	CFG_AUDIO_I2S2_SAMPLE_RATE				48000
#define	CFG_AUDIO_I2S2_PRE_SUPPLY_MCLK			0

/*------------------------------------------------------------------------------
 * 	Audio SPDIF (TX/RX)
 */
#define	CFG_AUDIO_SPDIF_TX_HDMI_OUT				CTRUE
#define	CFG_AUDIO_SPDIF_TX_SAMPLE_RATE			48000
#define	CFG_AUDIO_SPDIF_RX_SAMPLE_RATE			48000

/*------------------------------------------------------------------------------
 * 	I2C
 */
#define CFG_I2C0_CLK							100000
#define CFG_I2C1_CLK							400000
#define CFG_I2C2_CLK							100000
#define CFG_I2C3_CLK							100000
#define CFG_I2C4_CLK							100000
#define CFG_I2C5_CLK							100000
#define CFG_I2C6_CLK							100000
#define CFG_I2C7_CLK							100000
#define CFG_I2C8_CLK							100000
#define CFG_I2C9_CLK							100000

#define CFG_I2C1_RETRY_CNT 						10	
#define CFG_I2C1_RETRY_DELAY 					500

/*------------------------------------------------------------------------------
 * 	SPI
 */
#define CFG_SPI0_CLK							10000000
#define CFG_SPI1_CLK							10000000
#define CFG_SPI2_CLK							10000000

#define CFG_SPI0_COM_MODE						1 /* available 0: INTERRUPT_TRANSFER, 1: POLLING_TRANSFER, 2: DMA_TRANSFER */

#define CFG_SPI0_CS_GPIO_MODE					1		/* 0 FSS CONTROL, 1: CS CONTRO GPIO MODE */

#define CFG_SPI0_CS								PAD_GPIO_C + 30	/* 0 FSS CONTROL, 1: CS CONTRO GPIO MODE */
/*------------------------------------------------------------------------------
 *  MPEGTSIF
 */
#define CFG_MPEGTS_MASTER_MODE					1 /* 0: slave, 1: master */
#define CFG_MPEGTS_SLAVE_MODE					0 /* 0: slave, 1: master */
#define CFG_MPEGTS_CLOCKPOL						1 /* 0: falling, 1: rising */
#define CFG_MPEGTS_DATAPOL						1 /* 0: data is low, 1: data is high */
#define CFG_MPEGTS_SYNCPOL						1 /* 0: falling, 1: rising */
#define CFG_MPEGTS_ERRORPOL						1 /* 0: falling, 1: rising */
#define CFG_MPEGTS_DATAWIDTH					0 /* 0: 8bit, 1: 1bit */
#define CFG_MPEGTS_WORDCNT						47 /* 1 ~ 64 */

/*------------------------------------------------------------------------------
 * 	Keypad
 */
#define USERDEF_KEY1							251
#define USERDEF_KEY2							252
#define USERDEF_KEY3							253
#define USERDEF_KEY4							254

#define CFG_KEYPAD_KEY_BUTTON					{ PAD_GPIO_ALV + 0, PAD_GPIO_ALV + 1, PAD_GPIO_ALV + 2, PAD_GPIO_ALV + 3, PAD_GPIO_ALV + 4}
#define CFG_KEYPAD_KEY_CODE						{ KEY_POWER, USERDEF_KEY1, USERDEF_KEY2, USERDEF_KEY3, USERDEF_KEY4 }
#define CFG_KEYPAD_REPEAT						CFALSE /* 0: Repeat Off 1 : Repeat On */

/*------------------------------------------------------------------------------
 * 	SDHC
 */
#define	CFG_SDMMC0_DETECT_IO					(PAD_GPIO_E + 31)	/* external cd */

/*------------------------------------------------------------------------------
 * 	DWCOTG
 */

#define CFG_SWITCH_USB_5V_EN        			(PAD_GPIO_ALV + 5)
#define CFG_SWITCH_USB_HOST_DEVICE     			(PAD_GPIO_B + 20)
#define CFG_OTG_BOOT_MODE           			CFG_OTG_MODE_DEVICE

/*------------------------------------------------------------------------------
 * 	ADC
 */
#define	CFG_ADC_SAMPLE_RATE						(700 * 1000)

/*------------------------------------------------------------------------------
 * 	Suspend mode
 */

/* Wakeup Source : ALIVE [0~7] */
#define CFG_PWR_WAKEUP_SRC_ALIVE0				CTRUE					/* KEY */
#define CFG_PWR_WAKEUP_MOD_ALIVE0				PWR_DECT_FALLINGEDGE
#define CFG_PWR_WAKEUP_SRC_ALIVE1				CFALSE
#define CFG_PWR_WAKEUP_MOD_ALIVE1				PWR_DECT_FALLINGEDGE
#define CFG_PWR_WAKEUP_SRC_ALIVE2				CFALSE
#define CFG_PWR_WAKEUP_MOD_ALIVE2				PWR_DECT_FALLINGEDGE
#define CFG_PWR_WAKEUP_SRC_ALIVE3				CFALSE
#define CFG_PWR_WAKEUP_MOD_ALIVE3				PWR_DECT_FALLINGEDGE
#define CFG_PWR_WAKEUP_SRC_ALIVE4				CFALSE
#define CFG_PWR_WAKEUP_MOD_ALIVE4				PWR_DECT_FALLINGEDGE
#define CFG_PWR_WAKEUP_SRC_ALIVE5				CFALSE
#define CFG_PWR_WAKEUP_MOD_ALIVE5				PWR_DECT_FALLINGEDGE

/*
 * Wakeup Source : RTC ALARM
 * ifndef Enable ALARM Wakeup
 */
#define	CFG_PWR_WAKEUP_SRC_ALARM				CFALSE

//------------------------------------------------------------------------------
// Static Bus #0 ~ #9, NAND, IDE configuration
//------------------------------------------------------------------------------
//	_BW	  : Staic Bus width for Static #0 ~ #9            : 8 or 16
//
//	_TACS : adress setup time before chip select          : 0 ~ 15
//	_TCOS : chip select setup time before nOE is asserted : 0 ~ 15
//	_TACC : access cycle                                  : 1 ~ 256
//	_TSACC: burst access cycle for Static #0 ~ #9 & IDE   : 1 ~ 256
//	_TOCH : chip select hold time after nOE not asserted  : 0 ~ 15
//	_TCAH : address hold time after nCS is not asserted   : 0 ~ 15
//
//	_WAITMODE : wait enable control for Static #0 ~ #9 & IDE : 1=disable, 2=Active High, 3=Active Low
//	_WBURST	  : burst write mode for Static #0 ~ #9          : 0=disable, 1=4byte, 2=8byte, 3=16byte
//	_RBURST   : burst  read mode for Static #0 ~ #9          : 0=disable, 1=4byte, 2=8byte, 3=16byte
//
//------------------------------------------------------------------------------
#define CFG_SYS_STATICBUS_CONFIG( _name_, bw, tACS, tCOS, tACC, tSACC, tCOH, tCAH, wm, rb, wb )	\
	enum {											\
		CFG_SYS_ ## _name_ ## _BW		= bw,		\
		CFG_SYS_ ## _name_ ## _TACS		= tACS,		\
		CFG_SYS_ ## _name_ ## _TCOS		= tCOS,		\
		CFG_SYS_ ## _name_ ## _TACC		= tACC,		\
		CFG_SYS_ ## _name_ ## _TSACC	= tSACC,	\
		CFG_SYS_ ## _name_ ## _TCOH		= tCOH,		\
		CFG_SYS_ ## _name_ ## _TCAH		= tCAH,		\
		CFG_SYS_ ## _name_ ## _WAITMODE	= wm, 		\
		CFG_SYS_ ## _name_ ## _RBURST	= rb, 		\
		CFG_SYS_ ## _name_ ## _WBURST	= wb		\
	};

//                      ( _name_ , bw, tACS tCOS tACC tSACC tOCH tCAH, wm, rb, wb )
CFG_SYS_STATICBUS_CONFIG( STATIC0 ,  8,    1,   1,   6,    6,   1,   1,  1,  0,  0 )		// 0x0000_0000
CFG_SYS_STATICBUS_CONFIG( STATIC1 ,  8,    6,   6,  32,   32,   6,   6,  1,  0,  0 )		// 0x0400_0000
CFG_SYS_STATICBUS_CONFIG(    NAND ,  8,    0,   3,   9,    1,   3,   0,  1,  0,  0 )		// 0x2C00_0000, tOCH, tCAH must be greter than 0

#endif /* __CFG_MAIN_H__ */
