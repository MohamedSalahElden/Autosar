 /*-------------------------------------------------------------------------------
 * Module		: Port
 * File Name	: Port.h
 * Description	: header file for Port Module.
 * Author		: Mohamed salah-el-den
 * AR version	: V3.2.0
 * SW version	: V1.0.0
 -------------------------------------------------------------------------------*/


#ifndef PORT_DRIVER_STATIC_CODE_PORT_H_
#define PORT_DRIVER_STATIC_CODE_PORT_H_


#define PORT_VENDOR_ID								(1000U)
#define PORT_MODULE_ID								(124U)
#define PORT_INSTANCE_ID							(0U)
/*-------------------------------AUTOSAR VERSION--------------------------*/
#define PORT_AR_RELEASE_MAJOR_VERSION			(4U)
#define PORT_AR_RELEASE_MINOR_VERSION			(0U)
#define PORT_AR_RELEASE_PATCH_VERSION			(3U)

/*-------------------------------SOFTWARE VERSION--------------------------*/
#define PORT_SW_RELEASE_MAJOR_VERSION			(1U)
#define PORT_SW_RELEASE_MINOR_VERSION			(0U)
#define PORT_SW_RELEASE_PATCH_VERSION			(0U)


/*---------------------------------------------------------------------------------------------------------

											Inclusions

---------------------------------------------------------------------------------------------------------*/

#include "../../Std_Types.h"
/*autosar version checking*/
#if((PORT_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) ||	\
	(PORT_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION) ||	\
	(PORT_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
#error "AUTOSAR version mismatch between PORT driver and Std_Types module"
#endif

#include "Port_types.h"
/*autosar version checking*/
#if((PORT_AR_RELEASE_MAJOR_VERSION != PORT_TYPES_AR_RELEASE_MAJOR_VERSION) ||	\
	(PORT_AR_RELEASE_MINOR_VERSION != PORT_TYPES_AR_RELEASE_MINOR_VERSION) ||	\
	(PORT_AR_RELEASE_PATCH_VERSION != PORT_TYPES_AR_RELEASE_PATCH_VERSION))
#error "AUTOSAR version mismatch between PORT driver and port_Types module"
#endif
/*software version checking*/
#if((PORT_SW_RELEASE_MAJOR_VERSION != PORT_TYPES_SW_RELEASE_MAJOR_VERSION) ||	\
	(PORT_SW_RELEASE_MINOR_VERSION != PORT_TYPES_SW_RELEASE_MINOR_VERSION) ||	\
	(PORT_SW_RELEASE_PATCH_VERSION != PORT_TYPES_SW_RELEASE_PATCH_VERSION))
#error "software version mismatch between PORT driver and port_Types module"
#endif

#include "../configuration/Port_Cfg.h"
/*autosar version checking*/
#if((PORT_AR_RELEASE_MAJOR_VERSION != PORT_CFG_AR_RELEASE_MAJOR_VERSION) ||	\
	(PORT_AR_RELEASE_MINOR_VERSION != PORT_CFG_AR_RELEASE_MINOR_VERSION) ||	\
	(PORT_AR_RELEASE_PATCH_VERSION != PORT_CFG_AR_RELEASE_PATCH_VERSION))
#error "AUTOSAR version mismatch between PORT driver and port_Types module"
#endif
/*software version checking*/
#if((PORT_SW_RELEASE_MAJOR_VERSION != PORT_CFG_SW_RELEASE_MAJOR_VERSION) ||	\
	(PORT_SW_RELEASE_MINOR_VERSION != PORT_CFG_SW_RELEASE_MINOR_VERSION) ||	\
	(PORT_SW_RELEASE_PATCH_VERSION != PORT_CFG_SW_RELEASE_PATCH_VERSION))
#error "software version mismatch between PORT driver and port_Types module"
#endif

#include "../configuration/Port_PBcfg.h"

#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)

/*---------------------------------------------------------------------------------------------------------

											ERROR CLASSIFICATION

---------------------------------------------------------------------------------------------------------*/
#define PORT_E_PARAM_PIN 				((uint8)(0x0A))		/* Invalid Port Pin ID requested									*/
#define PORT_E_DIRECTION_UNCHANGEABLE 	((uint8)(0x0B))		/* Port Pin not configured as changeable                            */
#define PORT_E_PARAM_CONFIG 			((uint8)(0x0C))		/* API Port_Init service                                            */
#define PORT_E_PARAM_INVALID_MODE 		((uint8)(0x0D))		/* called with wrong parameter.                                     */
#define PORT_E_MODE_UNCHANGEABLE 		((uint8)(0x0E))		/* API Port_SetPinMode service called when mode is unchangeable.    */
#define PORT_E_UNINIT 					((uint8)(0x0F))		/* API service called without module initialization                 */
#define PORT_E_PARAM_POINTER 			((uint8)(0x10))		/* APIs called with a Null Pointer                                  */

/*---------------------------------------------------------------------------------------------------------

											function ID

---------------------------------------------------------------------------------------------------------*/
#define 	PORT_SET_PIN_DIRECTION_API_ID				((uint8)0x01)	/**/
#define 	PORT_INIT_API_ID                        	((uint8)0x00)	/**/
#define 	PORT_SET_PIN_MODE_API_ID                	((uint8)0x04)	/**/
#define 	PORT_GET_VERSION_INFO_API_ID            	((uint8)0x03)	/**/
#define 	PORT_REFRESH_PORT_DIRECTION_API_ID      	((uint8)0x02)	/**/

/*---------------------------------------------------------------------------------------------------------

											FUNCTION PROTOTYPES

---------------------------------------------------------------------------------------------------------*/

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
void Port_Init(const Port_ConfigType* ConfigPtr);

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
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
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
void Port_RefreshPortDirection(void);
#endif

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
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
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
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

#endif /* PORT_DRIVER_STATIC_CODE_PORT_H_ */
