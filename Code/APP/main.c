#include "APP_Includes.h"


int main(void){
	u8 hours = 0, minutes = 0, seconds = 0;
	DIO_voidInit();
	LCD_init();
	
	LCD_GoToXY(0, 5);
	LCD_displayCharacter('h');
	LCD_displayString(":");
	
	LCD_GoToXY(0, 7);
	LCD_displayCharacter('m');
	LCD_displayString(":");
	
	LCD_GoToXY(0, 9);
	LCD_displayCharacter('s');
	
	
	while(1){
		LCD_GoToXY(1, 5);
		LCD_DisplayInteger(hours);
		LCD_displayString(":");
		
		LCD_GoToXY(1, 7);
		LCD_DisplayInteger(minutes);
		LCD_displayString(":");
		LCD_GoToXY(1, 9);
		LCD_DisplayInteger(seconds++);
		_delay_ms(15);
		
		if(seconds == 60){
			LCD_ClearScreen();
			LCD_GoToXY(0, 5);
			LCD_displayCharacter('h');
			LCD_displayString(":");
			
			LCD_GoToXY(0, 7);
			LCD_displayCharacter('m');
			LCD_displayString(":");
			
			LCD_GoToXY(0, 9);
			LCD_displayCharacter('s');
			
			
			LCD_GoToXY(1, 5);
			LCD_DisplayInteger(hours);
			LCD_displayString(":");
			
			
			LCD_GoToXY(1, 7);
			minutes++;
			LCD_DisplayInteger(minutes);
			LCD_displayString(":");
			
			
			LCD_GoToXY(1, 9);
			seconds = 0;
			LCD_DisplayInteger(seconds);
			
		}
		
		if(minutes == 2){
			DIO_u8SetPinValue(3, 1, 1);
			LCD_ClearScreen();
			
			LCD_GoToXY(0, 4);
			LCD_displayString("Time Out!");
			
			LCD_GoToXY(1, 5);
			LCD_DisplayInteger(hours);
			LCD_displayString(":");
			
			
			LCD_GoToXY(1, 7);
			LCD_DisplayInteger(minutes);
			LCD_displayString(":");
			
			
			LCD_GoToXY(1, 9);
			LCD_DisplayInteger(seconds);
			break;
		}
	}
	return 0;
}
