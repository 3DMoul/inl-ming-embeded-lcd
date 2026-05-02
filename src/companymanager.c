#include "companymanager.h"

// companies
struct company_1 Hederlige_Harrys_Bilar = { "Hederlige Harrys Bilar" , 5000.0};
struct company_2 Farmor_Ankas_Pajer_AB = { "Farmor Ankas Pajer AB" , 3000.0};
struct company_3 Svarte_Petters_Svartbyggen = { "Svarte Petters Svartbyggen" , 1500.0};
struct company_4 Långbens_detektivbyrå = { "Långbens detektivbyrå" , 4000.0};
struct IOT_Commercial IOT_ = { "IOT:s Reklambyrå" , 1000.0};

// interrupt time 
volatile uint8_t seconds = 0;
volatile uint8_t minutes = 0;

ISR(TIMER1_COMPA_vect) {
    seconds++;

    if (seconds >= 60) {
        seconds = 0;
        minutes++;
    }
}

void timer1_init() {
    TCCR1B |= (1 << WGM12);               // CTC mode
    OCR1A = 15624;                       // 1 sec @16MHz, prescaler 1024
    TIMSK1 |= (1 << OCIE1A);             // enable interrupt
    TCCR1B |= (1 << CS12) | (1 << CS10); // start timer
}

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
	FQ[0] = round(100 * (Hederlige_Harrys_Bilar.payment / P));
    FQ[1] = round(100 * (Farmor_Ankas_Pajer_AB.payment / P));
    FQ[2] = round(100 * (Svarte_Petters_Svartbyggen.payment / P));
    FQ[3] = round(100 * (Långbens_detektivbyrå.payment / P));
    FQ[4] = round(100 * (IOT_.payment / P));
}

// companie ad functions
void company_1_advertising(void){
    millis_t millis_since_last_change = 0;
    millis_t current_millis = 0;
    millis_since_last_change = millis_get();
    current_millis = millis_get();
    int version = 0;
    version = rand() % 3;

    while (current_millis - millis_since_last_change < 20000)
    {
        current_millis = millis_get();
        
        lcd_clear();
        switch (version)
        {
            case 0:
            lcd_set_cursor(0,0);
            lcd_puts("Köp bil");
            lcd_set_cursor(0,1);
            lcd_puts("hos Harry");
                for (int i = 0; i < 40; i++){
                    lcd_scroll_right();
                    _delay_ms(100);
                }
            break;
        case 1:
            lcd_set_cursor(0,0);
            lcd_puts("En god bilaffär ");
            lcd_set_cursor(0,1);
            lcd_puts("(för Harry!)");
            break;
        case 2:
            lcd_set_cursor(0,0);
            lcd_puts("Hederlige Harrys" );
            lcd_set_cursor(0,1);
            lcd_puts("Bilar" );
            lcd_enable_blinking();
            break;
        }
    }
    lcd_disable_blinking();
}
void company_2_advertising(void){
    millis_t millis_since_last_change = 0;
    millis_t current_millis = 0;
    millis_since_last_change = millis_get();
    current_millis = millis_get();
    int version = 0;
    version = rand() % 2;
    lcd_clear();

    while (current_millis - millis_since_last_change < 20000)
    {
        current_millis = millis_get();
        
        switch (version)
        {
        case 0:
            lcd_set_cursor(0,0);
            lcd_puts("Köp paj ");
            lcd_set_cursor(0,1);
            lcd_puts("hos Farmor Anka");
                for (int i = 0; i < 40; i++){
                    lcd_scroll_right();
                    _delay_ms(100);
                }
            break;
        case 1:
            lcd_set_cursor(0,0);
            lcd_puts("Skynda innan Mårten");
            lcd_set_cursor(0,1);
            lcd_puts("ätit alla pajer");
            break;
        }
        
    }
    // Farmor Ankas Pajer AB:
    // Betalat 3000. Vill slumpmässigt visa en av två
    // "Köp paj hos Farmor Anka"  (scroll)
    // "Skynda innan Mårten ätit alla pajer" (text)
}
void company_3_advertising(void){
    millis_t millis_since_last_change = 0;
    millis_t current_millis = 0;
    millis_since_last_change = millis_get();
    current_millis = millis_get();
    lcd_clear();
    
    while (current_millis - millis_since_last_change < 20000)
    {
        current_millis = millis_get();
        if ((minutes % 2) == 0){
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
    int version = 0;
    version = rand() % 2;
    lcd_clear();

    while (current_millis - millis_since_last_change < 20000)
    {
        current_millis = millis_get();
        switch (version)
        {
        case 0:
            lcd_set_cursor(0,0);
            lcd_puts("Mysterier?");
            lcd_set_cursor(0,1);
            lcd_puts("Ring Långben");
            break;
        case 1:
            lcd_set_cursor(0,0);
            lcd_puts("Långben fixar biffen");
            lcd_set_cursor(0,1);
            lcd_puts("biffen");
            break;
        }
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
int rand_Func_myRand(int arr[], int freq[], const int n)  // Removed arr[] parameter, now returns index directly
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
    int arr[]  = {0, 1, 2, 3, 4};
    const int n = sizeof(arr) / sizeof(arr[0]);     

    // Use a different seed value for every run.
    int num = rand_Func_myRand(arr, freq, n);
    
    return num;

}

