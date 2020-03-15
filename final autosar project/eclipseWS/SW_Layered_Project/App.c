 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: App.c
 *
 * Description: Source file for Application Tasks.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "App.h"
#include "Button.h"
#include "Led.h"
#include "Dio.h"
#include "Port_Driver/static_code/Port.h"
#include "Micro_Config.h"

/* Task Called Once to initialize all the Modules */
void Init_Task(void)
{
	/* Enable Interrupts */
	SREG  |= (1<<7);

	Dio_Init(&Dio_Configuration);
	Port_Init(&Port_Configuration);
//	/* Initialize LED Driver */
//	LED_init();
//
//	/* Initialize BUTTON Driver */
//	BUTTON_init();
}

/* Task called every 20 Mili-seconds to check the button state */
void Button_Task(void)
{
	BUTTON_refreshState();
}

/* Task called every 40 Mili-seconds to refresh the LED */
void Led_Task(void)
{
	LED_refreshOutput();
}

/* Task called every 60 Mili-seconds to get the button status and toggle the led */
void App_Task(void)
{
	static uint8 button_previous_state = BUTTON_RELEASED;
	static uint8 button_current_state  = BUTTON_RELEASED;
	
	button_current_state = BUTTON_getState(); //Read the button state
	
	/* Only Toggle the led in case the current state of the switch is pressed
	 * and the previous state is released */ 
	if((button_current_state == BUTTON_PRESSED) && (button_previous_state == BUTTON_RELEASED))
	{
		LED_toggle();
	}
	
	button_previous_state = button_current_state;
}
