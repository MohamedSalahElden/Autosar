 /*-------------------------------------------------------------------------------
 * Module		: Port
 * File Name	: Port.h
 * Description	: header file for Port Module.
 * Author		: Mohamed salah-el-den
 * AR version	: V3.2.0
 * SW version	: V1.0.0
 -------------------------------------------------------------------------------*/



#ifndef PORT_TYPES_DRIVER_STATIC_CODE_PORT_H_
#define PORT_TYPES_DRIVER_STATIC_CODE_PORT_H_

/*-------------------------------AUTOSAR VERSION--------------------------*/
#define PORT_TYPES_AR_RELEASE_MAJOR_VERSION			(4U)
#define PORT_TYPES_AR_RELEASE_MINOR_VERSION			(0U)
#define PORT_TYPES_AR_RELEASE_PATCH_VERSION			(3U)

/*-------------------------------SOFTWARE VERSION--------------------------*/
#define PORT_TYPES_SW_RELEASE_MAJOR_VERSION			(1U)
#define PORT_TYPES_SW_RELEASE_MINOR_VERSION			(0U)
#define PORT_TYPES_SW_RELEASE_PATCH_VERSION			(0U)

/*-------------------------------Inclusions--------------------------*/

#include "../configuration/Port_Cfg.h"


/*-------------------------------TYPES DEFINITIONS--------------------------*/

/****************************************************************************
	Name: 			Port_PinType
	Type: 			uint	ATmega16 has 4port * 8pins = 32 channel
	Range: 			Shall cover all available port pins.
					The type should be chosen for
					the specific MCU platform (best performance).
	Description: 	Data type for the symbolic name of a port pin.
*****************************************************************************/
typedef uint8 Port_PinType;
/****************************************************************************
	Name:			Port_PinDirectionType
	Type: 			Enumeration
	Range: 			PORT_PIN_IN Sets port pin as input.
					PORT_PIN_OUT Sets port pin as output.
	Description: 	Possible directions of a port pin.
*****************************************************************************/
typedef enum{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;
/****************************************************************************
	Name: 			Port_PinModeType
	Type: 			uint Implementation specific
	Range: 			As several port pin modes shall be configurable on one pin,
					the range shall be determined by the implementation.
	Description: 	Different port pin modes.
*****************************************************************************/
typedef enum {
	PORT_PIN_MODE_ADC		,
	PORT_PIN_MODE_CAN       ,
	PORT_PIN_MODE_DIO       ,
	PORT_PIN_MODE_DIO_GPT   ,
	PORT_PIN_MODE_DIO_WDG   ,
	PORT_PIN_MODE_FLEXRAY   ,
	PORT_PIN_MODE_ICU       ,
	PORT_PIN_MODE_LIN       ,
	PORT_PIN_MODE_MEM       ,
	PORT_PIN_MODE_PWM       ,
	PORT_PIN_MODE_SPI
}Port_PinModeType;

typedef enum{
	PORT_PIN_LEVEL_LOW,
	PORT_PIN_LEVEL_HIGH
}Port_PinLevelValueType;

typedef enum{
	PORT_INT_RES_DISABLE,
	PORT_INT_PULL_UP_RES
}Port_PinIntResType;


typedef struct{
	Port_PinDirectionType	PortPinDirection;
	boolean 				PortPinDirectionChangeable;
	Port_PinModeType 		PortPinInitialMode;
	Port_PinLevelValueType 	PortPinLevelValue;
	Port_PinModeType 		PortPinMode;
	boolean 				PortPinModeChangeable;
	Port_PinIntResType		PortPinIntRes;
}Port_PinConfigType;

typedef struct{
	volatile uint8 *  directionReg;
	volatile uint8 *  portReg;
	uint8 	pinnum;
}Port_ATmega16PinDataType;

/****************************************************************************
	Name:			Port_ConfigType
	Type: 			Structure (Hardware Dependent Structure)
	Range: 			The contents of the initialization data
					structure are specific to the microcontroller.
	Description: 	Type of the external data structure
					containing the initialization data for this module.
*****************************************************************************/
typedef struct{
	Port_PinConfigType PinConfig[MCU_PIN_NUM];
}Port_ConfigType;

#endif /* PORT_DRIVER_STATIC_CODE_PORT_H_ */
