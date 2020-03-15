/*-------------------------------------------------------------------------------
 * Module		: Port
 * File Name	: Port.c
 * Description	: Source file for Port Module.
 * Author		: Mohamed salah-el-den
 * AR version	: V3.2.0
 -------------------------------------------------------------------------------*/
#include "Port.h"
#include "Port_Reg.h"
#include "Common_Macros.h"
#include "../../Det.h"

STATIC Port_ConfigType * g_cfgPtr = NULL_PTR;
STATIC uint8 Port_state	= DIO_NOT_INITIALIZED;

STATIC void Port_getPinPointers(Port_PinType Pin , Port_ATmega16PinDataType * ATmega16PinData){
	if((Pin >= 0) &&
			(Pin < PORT_A_PIN_NUM)){
		ATmega16PinData->directionReg 	= &DDRA_REG;
		ATmega16PinData->portReg		= &PORTA_REG;
		ATmega16PinData->pinnum			= Pin;
	}
	else if((Pin >= PORT_A_PIN_NUM) &&
			(Pin < PORT_A_PIN_NUM + PORT_B_PIN_NUM)){
		ATmega16PinData->directionReg 	= &DDRB_REG;
		ATmega16PinData->portReg		= &PORTB_REG;
		ATmega16PinData->pinnum			= Pin - PORT_A_PIN_NUM;
	}
	else if((Pin>=PORT_A_PIN_NUM + PORT_B_PIN_NUM) &&
			(Pin<PORT_A_PIN_NUM + PORT_B_PIN_NUM + PORT_C_PIN_NUM)){
		ATmega16PinData->directionReg 	= &DDRC_REG;
		ATmega16PinData->portReg		= &PORTC_REG;
		ATmega16PinData->pinnum			= Pin - (PORT_A_PIN_NUM + PORT_B_PIN_NUM);
	}
	else if((Pin>=PORT_A_PIN_NUM + PORT_B_PIN_NUM + PORT_C_PIN_NUM) &&
			(Pin<PORT_A_PIN_NUM + PORT_B_PIN_NUM + PORT_C_PIN_NUM + PORT_D_PIN_NUM)){
		ATmega16PinData->directionReg 	= &DDRD_REG;
		ATmega16PinData->portReg		= &PORTD_REG;
		ATmega16PinData->pinnum			= Pin - (PORT_A_PIN_NUM + PORT_B_PIN_NUM + PORT_C_PIN_NUM);
	}
	else{
		/*no action*/
	}
}

/**********************************************************************************************************
	Service name: 		Port_Init
	Service ID[hex]: 	0x00
	Sync/Async: 		Synchronous
	Reentrancy: 		Non Reentrant
	Parameters (in): 	ConfigPtr Pointer to configuration set.
	Parameters(inout):	None
	Parameters (out): 	None
	Return value: 		None
	Description: 		Initializes the Port Driver module.
 **********************************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if(ConfigPtr == NULL_PTR){
		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID,
				PORT_INIT_API_ID,
				PORT_E_PARAM_CONFIG
		);
	}
#endif
	g_cfgPtr = (Port_ConfigType *)ConfigPtr;

	Port_PinType pinConfigIndex = 0;			/*variable to loop through Configuration structure*/
	Port_ATmega16PinDataType ATmega16PinData;	/*variable to hold data pointers to DDR , PORT registers and pin number in ATMEGA 16 */

	for(pinConfigIndex = 0 ; pinConfigIndex<MCU_PIN_NUM ; pinConfigIndex++){
		Port_getPinPointers(pinConfigIndex , &ATmega16PinData);
		/*----------------------------------------- configure pin direction -----------------------------------------------------*/
		WRITE_BIT(	*ATmega16PinData.directionReg, ATmega16PinData.pinnum, ConfigPtr->PinConfig[pinConfigIndex].PortPinDirection);
		if(ConfigPtr->PinConfig[pinConfigIndex].PortPinDirection == PORT_PIN_IN){
			/*-------------------------------------configure internal resistors ------------------------------------------------*/
			WRITE_BIT(	*ATmega16PinData.portReg, ATmega16PinData.pinnum, ConfigPtr->PinConfig[pinConfigIndex].PortPinIntRes);
		}
		else if(ConfigPtr->PinConfig[pinConfigIndex].PortPinDirection == PORT_PIN_OUT){
			/*-----------------------------------------configure pin level -----------------------------------------------------*/
			WRITE_BIT(	*ATmega16PinData.portReg, ATmega16PinData.pinnum, ConfigPtr->PinConfig[pinConfigIndex].PortPinLevelValue);
		}
		else{
			/*no action*/
		}
	}
	Port_state = DIO_INITIALIZED;
}

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/**********************************************************************************************************
	Service name: 		Port_SetPinDirection
	Service ID[hex]: 	0x01
	Sync/Async: 		Synchronous
	Reentrancy: 		Reentrant
	Parameters (in):	Pin 		Port Pin ID number
						Direction 	Port Pin Direction
	Parameters(inout): 	None
	Parameters (out): 	None
	Return value: 		None
	Description: 		Sets the port pin direction
 **********************************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if(Port_state == DIO_NOT_INITIALIZED){
		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_API_ID,
				PORT_E_UNINIT
		);
	}
	if(Pin >= MCU_PIN_NUM){
		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_API_ID,
				PORT_E_DIRECTION_UNCHANGEABLE
		);
	}
#endif
	Port_ATmega16PinDataType ATmega16PinData;

	if(g_cfgPtr->PinConfig[Pin].PortPinDirectionChangeable == TRUE){
		Port_getPinPointers(Pin , &ATmega16PinData);									/*get the PORT , pin data out of PIN ID*/
		/*----------configure pin direction ------------------------------*/
		WRITE_BIT(	*ATmega16PinData.directionReg, ATmega16PinData.pinnum, Direction);
	}
	else{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_API_ID,
				PORT_E_DIRECTION_UNCHANGEABLE
		);
#endif
	}
}
#endif

/**********************************************************************************************************
	Service name:		Port_RefreshPortDirection
	Service ID[hex]: 	0x02
	Sync/Async: 		Synchronous
	Reentrancy: 		Non Reentrant
	Parameters (in): 	None
	Parameters (inout): None
	Parameters (out): 	None
	Return value: 		None
	Description: 		Refreshes port direction.
 **********************************************************************************************************/
void Port_RefreshPortDirection(void){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if(Port_state == DIO_NOT_INITIALIZED){
		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID,
				PORT_REFRESH_PORT_DIRECTION_API_ID,
				PORT_E_UNINIT
		);
	}
#endif
	uint8 portDirection;
	portDirection = DDRA_REG;
	DDRA_REG = portDirection;

	portDirection = DDRB_REG;
	DDRB_REG = portDirection;

	portDirection = DDRC_REG;
	DDRC_REG = portDirection;

	portDirection = DDRD_REG;
	DDRD_REG = portDirection;
}

#if (PORT_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************
	Service name: 		Port_GetVersionInfo
	Service ID[hex]: 	0x03
	Sync/Async: 		Synchronous
	Reentrancy: 		Non Reentrant
	Parameters (in): 	None
	Parameters (inout): None
	Parameters (out): 	versioninfo Pointer to where to store the version information of this module.
	Return value: 		None
	Description: 		Returns the version information of this module.
 **********************************************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if(Port_state == DIO_NOT_INITIALIZED){
		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_API_ID,
				PORT_E_UNINIT
		);
	}
	if(versioninfo == NULL_PTR){
		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_API_ID,
				PORT_E_PARAM_POINTER
		);
	}

#endif

	versioninfo->vendorID			=	PORT_VENDOR_ID;
	versioninfo->moduleID			=	PORT_MODULE_ID;
	versioninfo->sw_major_version	=	PORT_SW_RELEASE_MAJOR_VERSION;
	versioninfo->sw_minor_version	=	PORT_SW_RELEASE_MINOR_VERSION;
	versioninfo->sw_patch_version	=	PORT_SW_RELEASE_PATCH_VERSION;
}
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
/**********************************************************************************************************
	Service name: 		Port_SetPinMode
	Service ID[hex]: 	0x04
	Sync/Async: 		Synchronous
	Reentrancy: 		Reentrant
	Parameters (in):	Pin 	Port Pin ID number
						Mode 	New Port Pin mode to be set on port pin.
	Parameters (inout): None
	Parameters (out): 	None
	Return value: 		None
	Description: 		Sets the port pin mode.
 **********************************************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode){
	/*not applicable*/
}
#endif
