#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "lcd.h"
#include "millis.h"
#include "companymanager.h"

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
    millis_init();
    sei();
	struct company_1 Hederlige_Harrys_Bilar;
	struct company_2 Farmor_Ankas_Pajer_AB;
	struct company_3 Svarte_Petters_Svartbyggen;
	struct company_4 Långbens_detektivbyrå;
	struct IOT_Commercial IOT_;
	
	
	double paymentSum = 0;
	paymentSum = paymentSumCalc(
		Hederlige_Harrys_Bilar.payment,
		Farmor_Ankas_Pajer_AB.payment, 
		Svarte_Petters_Svartbyggen.payment,
		Långbens_detektivbyrå.payment,IOT_.payment);
		
	int freq[5];
	freq[0] = 100*(Hederlige_Harrys_Bilar.payment/paymentSum);
	freq[1] = 100*(Farmor_Ankas_Pajer_AB.payment/paymentSum);
	freq[2] = 100*(Svarte_Petters_Svartbyggen.payment/paymentSum);
	freq[3] = 100*(Långbens_detektivbyrå.payment/paymentSum);
	freq[4] = 100*(IOT_.payment/paymentSum);
		


	millis_t millis_since_last_change = 0;
    millis_t current_millis = 0;

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
	int companynumber = 0;
	
	while(1) {
		current_millis = millis_get();
		if(current_millis_clear - millis_since_last_clear >= 20000){
			companynumber = rand_Func_randomCompanySelection(freq);
		}
		



	}
	return 0;
}
