 /*-------------------------------------------------------------------------------
 * Module		: Port
 * File Name	: Port_Cfg.h
 * Description	: pre build configuration file for Port Module.
 * Author		: Mohamed salah-el-den
 * AR version	: V3.2.0
 * SW version	: V1.0.0
 -------------------------------------------------------------------------------*/


#ifndef PORT_DRIVER_CONFIGURATION_PORT_CFG_H_
#define PORT_DRIVER_CONFIGURATION_PORT_CFG_H_



/*-------------------------------AUTOSAR VERSION--------------------------*/
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION			(4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION			(0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION			(3U)

/*-------------------------------SOFTWARE VERSION--------------------------*/
#define PORT_CFG_SW_RELEASE_MAJOR_VERSION			(1U)
#define PORT_CFG_SW_RELEASE_MINOR_VERSION			(0U)
#define PORT_CFG_SW_RELEASE_PATCH_VERSION			(0U)


/*---------------------------------------------------------------------------------------------------------

											Inclusions

---------------------------------------------------------------------------------------------------------*/

#include "../../Std_Types.h"
/*autosar version checking*/
#if((PORT_CFG_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) ||	\
	(PORT_CFG_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION) ||	\
	(PORT_CFG_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
#error "AUTOSAR version mismatch between PORT driver and Std_Types module"
#endif

#include "../configuration/Port_Cfg.h"
/*autosar version checking*/
#if((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_TYPES_AR_RELEASE_MAJOR_VERSION) ||	\
	(PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_TYPES_AR_RELEASE_MINOR_VERSION) ||	\
	(PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_TYPES_AR_RELEASE_PATCH_VERSION))
#error "AUTOSAR version mismatch between PORT driver and port_Types module"
#endif
/*software version checking*/
#if((PORT_CFG_SW_RELEASE_MAJOR_VERSION != PORT_TYPES_SW_RELEASE_MAJOR_VERSION) ||	\
	(PORT_CFG_SW_RELEASE_MINOR_VERSION != PORT_TYPES_SW_RELEASE_MINOR_VERSION) ||	\
	(PORT_CFG_SW_RELEASE_PATCH_VERSION != PORT_TYPES_SW_RELEASE_PATCH_VERSION))
#error "software version mismatch between PORT driver and port_Types module"
#endif


/*----------------switches definition -----------------------------*/

#define PORT_DEV_ERROR_DETECT			(STD_OFF)
#define PORT_SET_PIN_DIRECTION_API		(STD_ON)
#define PORT_SET_PIN_MODE_API			(STD_ON)
#define PORT_VERSION_INFO_API			(STD_ON)

#define MCU_PIN_NUM		32
#define MCU_PORT_NUM	4

#define PORT_A_PIN_NUM	8
#define PORT_B_PIN_NUM	8
#define PORT_C_PIN_NUM	8
#define PORT_D_PIN_NUM	8


/*----------------Symbolic names definition -----------------------------*/

#define PORT_A_PIN_0	0
#define PORT_A_PIN_1	1
#define PORT_A_PIN_2	2
#define PORT_A_PIN_3	3
#define PORT_A_PIN_4	4
#define PORT_A_PIN_5	5
#define PORT_A_PIN_6	6
#define PORT_A_PIN_7	7

#define PORT_B_PIN_0	8
#define PORT_B_PIN_1	9
#define PORT_B_PIN_2	10
#define PORT_B_PIN_3	11
#define PORT_B_PIN_4	12
#define PORT_B_PIN_5	13
#define PORT_B_PIN_6	14
#define PORT_B_PIN_7	15

#define PORT_C_PIN_0	16
#define PORT_C_PIN_1	17
#define PORT_C_PIN_2	18
#define PORT_C_PIN_3	19
#define PORT_C_PIN_4	20
#define PORT_C_PIN_5	21
#define PORT_C_PIN_6	22
#define PORT_C_PIN_7	23

#define PORT_D_PIN_0	24
#define PORT_D_PIN_1	25
#define PORT_D_PIN_2	26
#define PORT_D_PIN_3	27
#define PORT_D_PIN_4	28
#define PORT_D_PIN_5	29
#define PORT_D_PIN_6	30
#define PORT_D_PIN_7	31

#endif /* PORT_DRIVER_CONFIGURATION_PORT_CFG_H_ */
