#include "companymanager.h"

// companies
struct company_1 c1 = { "Hederlige Harrys Bilar" , 5000};
struct company_2 c2 = { "Farmor Ankas Pajer AB" , 3000};
struct company_3 c3 = { "Svarte Petters Svartbyggen" , 1500};
struct company_4 c4 = { "Långbens detektivbyrå" , 4000};
struct IOT_Commercial c5 = { "IOT:s Reklambyrå" , 1000};

// companie ad functions
void company_1_advertising(){
    lcd_set_cursor(0,0);
	lcd_printf("Köp bil hos Harry" );
    for (int i = 0; i < 16; i++){
		lcd_scroll_right();
		_delay_ms(75);
        
	}
    //Hederlige Harrys Bilar:
    // Betalat 5000. Vill slumpmässigt visa en av tre meddelanden
    // "Köp bil hos Harry"  (scroll)
    // "En god bilaffär (för Harry!)" (text)
    // "Hederlige Harrys Bilar" (blinkande text)
}
void company_2_advertising(){
    // Farmor Ankas Pajer AB:
    // Betalat 3000. Vill slumpmässigt visa en av två
    // "Köp paj hos Farmor Anka"  (scroll)
    // "Skynda innan Mårten ätit alla pajer" (text)
}
void company_3_advertising(){
    // Svarte Petters Svartbyggen:
    // Betalat 1500. Vill visa
    // "Låt Petter bygga åt dig"  (scroll) - på jämna minuter
    // "Bygga svart? Ring Petter" (text) - på ojämna minuter
}
void company_4_advertising(){
    // Långbens detektivbyrå:
    // Betalat 4000. Vill visa
    // "Mysterier? Ring Långben" (text) 
    // "Långben fixar biffen" (text)
}
void IOT_Commercial_advertising(){
    // Ibland måste vi visa reklam för oss själva:
    // Vi ger oss själva tid motsvarande 1000 kr. 
    // "Synas här? IOT:s Reklambyrå" (text)
}

// random selection function
int rand_Func_myRand(int arr[], int freq[], const int n)
{
    // Create and fill prefix array
    int prefix[5], i;
    prefix[0] = freq[0];
    for (i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + freq[i];

    // prefix[n-1] is sum of all frequencies. Generate a random number
    // with value from 1 to this sum
    int r = (rand() % prefix[n - 1]) + 1;

    // Find index of ceiling of r in prefix array
    int indexc = findCeil(prefix, r, 0, n - 1);
    return arr[indexc];
}
int rand_Func_randomCompanySelection(void){
int arr[]  = {1, 2, 3, 4, 5};
    int freq[] = {40, 5, 30, 10, 5};
    const int n = sizeof(arr) / sizeof(arr[0]);     

    srand(time(NULL));
    int num = 0;
    num = rand_Func_myRandmyRand(arr, freq, n);
    return num;
}
