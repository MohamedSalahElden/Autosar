/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.c
 *
 * Description: Source file for Led Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/
#include "Dio.h"
#include "Port_Driver/static_code/Port.h"
#include "Button.h"

/* Button Configurations Structure */
//static Port_Config g_Button_Config;

/* Count the number of Pressed times increment if the switch pressed for 20 ms */
static uint8 g_Pressed_Count  = 0;

/* Count the number of Released times increment if the switch released for 20 ms */
static uint8 g_Released_Count = 0;

static uint8 g_button_state     = BUTTON_RELEASED;

/*******************************************************************************************************************/
/* Description: Called by the Button_Init function (only) used to fill the Button configurations structure */
//static void BUTTON_configurations()
//{
//	g_Button_Config.port      = BUTTON_PORT; //Button PORT
//	g_Button_Config.pin_num   = BUTTON_PIN_NUM; //Button PIN Number
//	g_Button_Config.direction = INPUT; //Button is INPUT
//}
///*******************************************************************************************************************/
//void BUTTON_init()
//{
//	BUTTON_configurations();
//	Port_SetDirection(&g_Button_Config);
//}
/*******************************************************************************************************************/
uint8 BUTTON_getState(void)
{
	return g_button_state;
}
/*******************************************************************************************************************/
void BUTTON_refreshState(void)
{
	uint8 state = Dio_ReadChannel(DioConf_BUTTON_CHANNEL_ID_INDEX);
	if(state == BUTTON_PRESSED)
	{
		g_Pressed_Count++;
		g_Released_Count = 0;
	}
	else
	{
		g_Released_Count++;
		g_Pressed_Count = 0;
	}

	if(g_Pressed_Count == 3)
	{
		g_button_state = BUTTON_PRESSED;
		g_Pressed_Count       = 0;
		g_Released_Count      = 0;
	}
	else if(g_Released_Count == 3)
	{
		g_button_state = BUTTON_RELEASED;
		g_Released_Count      = 0;
		g_Pressed_Count       = 0;
	}
}
/*******************************************************************************************************************/
