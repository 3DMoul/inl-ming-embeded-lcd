#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "lcd.h"
#include "millis.h"
#include "companymanager.h"
#include "uart.h"

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
    millis_init();
	init_serial();
	srand(time(NULL));
	lcd_init();
    sei();
	
	double paymentSum = paymentSumCalc();
	if (paymentSum < 0) {
		printf("Warning: paymentSum < 0, resetting to 0\n");
		paymentSum = 0;
	}
	int int1 = 0;
	int int2 = 0;
	int int3 = 0;
	int int4 = 0;
	int int5 = 0;
	int freq[5];
	freqcalc(freq, paymentSum);
	
	int companynumber = 0;
	
	while(1) {
		companynumber = rand_Func_randomcompanyselection(freq);
		printf("random numb%d\n",companynumber);
		if(companynumber < 0) {
			printf("Random selection failed with code %d\n", companynumber);
			continue; // or handle appropriately
		}
		switch (companynumber)
		{
			case 0:
			printf("0\n");
			lcd_clear();
			company_1_advertising();
			int1++;
			break;
			case 1:
			printf("1\n");
			lcd_clear();
			company_2_advertising();
			int2++;
			break;
			case 2:
			printf("2\n");
			lcd_clear();
			company_3_advertising();
			int3++;
			break;
			case 3:
			printf("3\n");
			lcd_clear();
			company_4_advertising();
			int4++;
			break;
			case 4:
			printf("4\n");
			lcd_clear();
			IOT_Commercial_advertising();
			int5++;
			break;
			
			default:
			break;
		}
		printf("Freq array in main: %d %d %d %d %d\n", 
		   int1, int2, int3, int4, int5);
		
		
		
	}
	return 0;
}
