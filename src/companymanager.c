#include "companymanager.h"

int myRand(int arr[], int freq[], const int n)
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
void randomcompanyselection(){
int arr[]  = {1, 2, 3, 4, 5};
    int freq[] = {40, 5, 30, 10, 5};
    const int n = sizeof(arr) / sizeof(arr[0]);     

    srand(time(NULL));
    int num = 0;
    num = myRand(arr, freq, n);
}

void company_2::companyadvertising()
{

}
void companyadvertising();
void companyadvertising();
void companyadvertising();
void companyadvertising();

void company_1::companyadvertising()
{
}
