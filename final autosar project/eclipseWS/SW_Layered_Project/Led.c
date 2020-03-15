/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/
#include "Port_Driver/static_code/Port.h"
#include "Dio.h"
#include "Led.h"

/* LED Configurations Structure */
//static Port_Config  g_LED_Config;

/*********************************************************************************************/
/* Description: Called by the LED_Init function (only) used to fill the led configurations structure */
//static void LED_configurations(void)
//{
//	g_LED_Config.port = LED_PORT; // LED Port
//	g_LED_Config.pin_num = LED_PIN_NUM; //LED PIN Number
//	g_LED_Config.direction = OUTPUT; //LED is OUTPUT
//}
///*********************************************************************************************/
// void LED_init(void)
//{
//	LED_configurations(); // fill the g_LED_Config structure with the led configurations
//	Port_SetDirection(&g_LED_Config); // set the direction of the LED
//	Dio_WriteChannel(DioConf_LED_CHANNEL_ID_INDEX,LED_OFF); // LED OFF
//}
/*********************************************************************************************/
void LED_setOn(void)
{
	Dio_WriteChannel(DioConf_LED_CHANNEL_ID_INDEX,LED_ON); // LED ON
}
/*********************************************************************************************/
void LED_setOff(void)
{
	Dio_WriteChannel(DioConf_LED_CHANNEL_ID_INDEX,LED_OFF); // LED OFF
}
/*********************************************************************************************/
void LED_refreshOutput(void)
{
	Dio_LevelType state = Dio_ReadChannel(DioConf_LED_CHANNEL_ID_INDEX);
	Dio_WriteChannel(DioConf_LED_CHANNEL_ID_INDEX,state); // re-write the same value
}
/*********************************************************************************************/
void LED_toggle(void)
{
	Dio_LevelType state = Dio_FlipChannel(DioConf_LED_CHANNEL_ID_INDEX);
}
/*********************************************************************************************/
