// #include <avr/io.h>
// #include <util/delay.h>
// #include <stdio.h>

// #define BIT_SET(a, b) ((a) |= (1ULL << (b)))
// #define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
// #define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
// #define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

// //Blinka #13 = interna lampan på Uno
// //Dvs pin 5 på port B
// //https://www.arduino.cc/en/Reference/PortManipulation
// //
// void internalLed()
// {
// 	BIT_SET(DDRB, 1);
// 	BIT_SET(DDRB, 2);
// 	BIT_SET(DDRB, 3);
// 	while (1)
// 	{
// 		BIT_SET(PORTB, 3);
// 		_delay_ms(5000);
// 		BIT_CLEAR(PORTB, 3);
// 		BIT_SET(PORTB, 1);
// 		_delay_ms(2000);
// 		BIT_CLEAR(PORTB, 1);
// 		BIT_SET(PORTB, 2);
// 		_delay_ms(5000);
// 		BIT_CLEAR(PORTB, 2);
// 		BIT_SET(PORTB, 1);
// 		_delay_ms(2000);
// 		BIT_CLEAR(PORTB, 1);
// 	}

// }



// //Blinka pin 7 (PORT D)
// int main(void)
// {
// 	internalLed();
// 	return 0;
// }

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include <stdio.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)
// https://wokwi.com/projects/363784064760337409
int main(void)
{
	lcd_init();
	// lcd_enable_blinking();
	// lcd_enable_cursor();
	// bättre implementering slutar i sluttet av en arrar där den är \0 som gör att man kan göra den hur långs som helst utan att ändra for loopen något
	char text[] = "Skriv in k'\xF6\'den:";
	for(int i = 0; text[i] != '\0'; i++){
		if (text[i] == '\'')
		continue;
		else if (text[i] == '\xE5')
		lcd_write('\xE5');
		else if (text[i] == '\xE4')
		lcd_write('\xE4');
		else if (text[i] == '\xF6')
		lcd_write('\xF6');
		else
    	lcd_write(text[i]);
    _delay_ms(100);
}
	int num = 0;
	// min inmplementering dålig ej dynamisk
	// char text[] = "Skriv in koden:";
	//   for (int i = 0; i < 15 ; i++) {
		//     lcd_write(text[i]);   // write single character
		//     _delay_ms(75);
		// }
	while(1) {
		num++;
		_delay_ms(500);
		for (int i = 0; i < 16; i++){
			lcd_scroll_right();
			_delay_ms(75);
		}
		_delay_ms(500);
		lcd_set_cursor(0,1);
		lcd_printf("Waiting: %d", num);
	   for (int i = 0; i < 16; i++){
	   lcd_scroll_left();
	   _delay_ms(75);
		}
		_delay_ms(3000);
	}
	return 0;
}