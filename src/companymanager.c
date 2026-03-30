#include "companymanager.h"

// companies
struct company_1 Hederlige_Harrys_Bilar = { "Hederlige Harrys Bilar" , 5000};
struct company_2 Farmor_Ankas_Pajer_AB = { "Farmor Ankas Pajer AB" , 3000};
struct company_3 Svarte_Petters_Svartbyggen = { "Svarte Petters Svartbyggen" , 1500};
struct company_4 Långbens_detektivbyrå = { "Långbens detektivbyrå" , 4000};
struct IOT_Commercial IOT_ = { "IOT:s Reklambyrå" , 1000};

int paymentSumCalc(){
    int tempSum = 0;
    tempSum += Hederlige_Harrys_Bilar.payment;
	tempSum += Farmor_Ankas_Pajer_AB.payment;
	tempSum += Svarte_Petters_Svartbyggen.payment;
	tempSum += Långbens_detektivbyrå.payment;
	tempSum += IOT_.payment;
    return tempSum;
}

void freqcalc(int FQ[], int P){
    if(P <= 0) {
        for(int i=0;i<5;i++)
            FQ[i] = 1;  // Default equal probability
        return;
    }
	FQ[0] = round((100 * Hederlige_Harrys_Bilar.payment) / P);
    FQ[1] = round((100 * Farmor_Ankas_Pajer_AB.payment) / P);
    FQ[2] = round((100 * Svarte_Petters_Svartbyggen.payment) / P);
    FQ[3] = round((100 * Långbens_detektivbyrå.payment) / P);
    FQ[4] = round((100 * IOT_.payment) / P);
}

// companie ad functions
void company_1_advertising(void){
    millis_t millis_since_last_change = 0;
    millis_t millis_since_last_change_switch = 0;
    millis_t current_millis = 0;
    millis_since_last_change = millis_get();
    millis_since_last_change_switch = millis_get();
    current_millis = millis_get();

    while (current_millis - millis_since_last_change < 20000)
    {
        current_millis = millis_get();
        int version = 0;
        version = rand() % 3;
        
        lcd_clear();
        switch (version)
        {
            case 0:
            lcd_set_cursor(0,0);
            lcd_puts("Köp bil");
            lcd_set_cursor(0,1);
            lcd_puts("hos Harry");
            while ((current_millis - millis_since_last_change_switch < 5000))
            {
                current_millis = millis_get();
                for (int i = 0; i < 16; i++){
                    lcd_scroll_right();
                    _delay_ms(100);
                }
            }
            break;
        case 1:
            lcd_set_cursor(0,0);
            lcd_puts("En god bilaffär ");
            lcd_set_cursor(0,1);
            lcd_puts("(för Harry!)")
            while ((current_millis - millis_since_last_change_switch < 5000))
            {
                current_millis = millis_get();
            }
            break;
        case 2:
            lcd_set_cursor(0,0);
            lcd_puts("Hederlige Harrys" );
            lcd_set_cursor(0,1);
            lcd_puts("Bilar" );
            lcd_enable_blinking();
            while ((current_millis - millis_since_last_change_switch < 5000))
            {
                current_millis = millis_get();
            }
            lcd_disable_blinking();
            break;
        }
        millis_since_last_change_switch = current_millis; 
        
    }
}
void company_2_advertising(void){
    millis_t millis_since_last_change = 0;
    millis_t millis_since_last_change_switch = 0;
    millis_t current_millis = 0;
    millis_since_last_change = millis_get();
    millis_since_last_change_switch = millis_get();
    current_millis = millis_get();
    while (current_millis - millis_since_last_change < 20000)
    {
        current_millis = millis_get();
        int version = 0;
        version = rand() % 2;
        
        lcd_clear();
        switch (version)
        {
        case 0:
            lcd_set_cursor(0,0);
            lcd_puts("Köp bil");
            lcd_set_cursor(0,1);
            lcd_puts("hos Harry");
            while ((current_millis - millis_since_last_change_switch < 5000))
            {
                current_millis = millis_get();
                for (int i = 0; i < 16; i++){
                    lcd_scroll_right();
                    _delay_ms(100);
                }
            }
            break;
        case 1:
            lcd_set_cursor(0,0);
            lcd_puts("Skynda innan Mårten");
            lcd_set_cursor(0,1);
            lcd_puts("ätit alla pajer");
            while ((current_millis - millis_since_last_change_switch < 5000))
            {
                current_millis = millis_get();
            }
            break;
        }
        millis_since_last_change_switch = current_millis; 
        
    }
    // Farmor Ankas Pajer AB:
    // Betalat 3000. Vill slumpmässigt visa en av två
    // "Köp paj hos Farmor Anka"  (scroll)
    // "Skynda innan Mårten ätit alla pajer" (text)
}
int exactminut(void){
    time_t now;
    struct tm *local;

    time(&now);                 // get current time
    local = localtime(&now);    // convert to local time

    int minute = local->tm_min; // extract minute (0–59)
    return minute;
}
void company_3_advertising(void){
    millis_t millis_since_last_change = 0;
    millis_t millis_since_last_change_switch = 0;
    millis_t current_millis = 0;
    struct tm datetime;
    time_t timestamp;
    millis_since_last_change = millis_get();
    millis_since_last_change_switch = millis_get();
    current_millis = millis_get();
    while (current_millis - millis_since_last_change < 20000)
    {
        current_millis = millis_get();
        if ((exactminut()%2) == 0){
            lcd_clear();
            lcd_set_cursor(0,0);
            lcd_puts("Låt Petter");
            lcd_set_cursor(0,1);
            lcd_puts("bygga åt dig");
            for (int i = 0; i < 40; i++){
                    lcd_scroll_right();
                    _delay_ms(100);
                }
        }
        else{
            lcd_clear();
            lcd_set_cursor(0,0);
            lcd_puts("Bygga svart?");
            lcd_set_cursor(0,1);
            lcd_puts("Ring Petter");
        }
        
    }
    // Svarte Petters Svartbyggen:
    // Betalat 1500. Vill visa
    // "Låt Petter bygga åt dig"  (scroll) - på jämna minuter
    // "Bygga svart? Ring Petter" (text) - på ojämna minuter
}
void company_4_advertising(void){
    millis_t millis_since_last_change = 0;
    millis_t current_millis = 0;
    millis_since_last_change = millis_get();
    current_millis = millis_get();
    lcd_set_cursor(0,0);
    lcd_puts("Mysterier? Ring Långben");
    lcd_set_cursor(0,1);
    lcd_puts("Långben fixar biffen");
    while (current_millis - millis_since_last_change < 20000)
    {
        current_millis = millis_get();
    }
    // Långbens detektivbyrå:
    // Betalat 4000. Vill visa
    // "Mysterier? Ring Långben" (text) 
    // "Långben fixar biffen" (text)
}
void IOT_Commercial_advertising(void){
    millis_t millis_since_last_change = 0;
    millis_t current_millis = 0;
    millis_since_last_change = millis_get();
    current_millis = millis_get();

    lcd_set_cursor(0,0);
    lcd_puts("Synas här?");
    lcd_set_cursor(0,1);
    lcd_puts("IOT:s Reklambyrå");
    while (current_millis - millis_since_last_change < 20000)
    {
        current_millis = millis_get();
    }
    // Ibland måste vi visa reklam för oss själva:
    // Vi ger oss själva tid motsvarande 1000 kr. 
    // "Synas här? IOT:s Reklambyrå" (text)
}


int rand_Func_findCeil(int arr[], int r, int l, int h)
{
    int mid;
    while (l < h)
    {
         mid = l + ((h - l) >> 1);  // Same as mid = (l+h)/2
        (r > arr[mid]) ? (l = mid + 1) : (h = mid);
    }
    return (arr[l] >= r) ? l : -1;
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
    int indexc = rand_Func_findCeil(prefix, r, 0, n - 1);
    return arr[indexc];
}
int rand_Func_randomcompanyselection(int *freq) {
    int sum = 0;
    for (int i = 0; i < 5; i++) sum += freq[i];
    if (sum <= 0) return -1;  // cannot select, sum invalid

    int r = rand() % sum;  // always 0 <= r < sum
    int cum = 0;
    for (int i = 0; i < 5; i++) {
        cum += freq[i];
        if (r < cum) return i;  // selected index
    }
    return -1; // fallback (should never happen)
}
