
#include "StdTypes.h"
#include "MemMap.h"
#include "Utlis.h"

#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "Timers.h"
#include "UART.h"

#include "LCD_Interface.h"
#include "Sensors_Interface.h"
#include "UART_Service.h"
#include "Timers_Services.h"
#include "Bluetooth.h"
#define F_CPU  8000000
#include <util/delay.h>

int main(void)
{
	/********************* Initialisation ***************************/
DIO_Init();
ADC_Init(VREF_VCC,ADC_SCALER_64);
LCD_Init();
UART_Init();   
Motor_Init();
Servo_Init();
   /*****************************************************************/

LCD_SetCursor(0,0);
LCD_WriteString("  Smart Control ");

    while (1) 
    {
 		Bluetooth_GetCommand();
 		Bluetooth_ApplyCommand();
    }
}

