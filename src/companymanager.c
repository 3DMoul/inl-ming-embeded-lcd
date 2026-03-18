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
}
void company_2_advertising(){

}
void company_3_advertising(){

}
void company_4_advertising(){

}
void IOT_Commercial_advertising(){

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
void rand_Func_randomCompanySelection(){
int arr[]  = {1, 2, 3, 4, 5};
    int freq[] = {40, 5, 30, 10, 5};
    const int n = sizeof(arr) / sizeof(arr[0]);     

    srand(time(NULL));
    int num = 0;
    num = rand_Func_myRandmyRand(arr, freq, n);
}
