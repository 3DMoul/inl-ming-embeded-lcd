#ifndef COMPANYMANAGER_H
#define COMPANYMANAGER_H
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "lcd.h"
#include "millis.h"


// companies
struct company_1 { char name[23]; int payment;}; // Hederlige Harrys Bilar
struct company_2 { char name[22]; int payment;}; // Farmor Ankas Pajer AB
struct company_3 { char name[27]; int payment;}; // Svarte Petters Svartbyggen
struct company_4 { char name[24]; int payment;}; // Långbens detektivbyrå
struct IOT_Commercial { char name[18]; int payment;}; // IOT

int paymentSumCalc();
void freqcalc(int FQ[], int P);

// companie ad functions
void company_1_advertising(void);
void company_2_advertising(void);
int exactminut(void);
void company_3_advertising(void);
void company_4_advertising(void);
void IOT_Commercial_advertising(void);

// functions for selecting random company comercial
int rand_Func_findCeil(int arr[], int r, int l, int h);
int rand_Func_myRand(int arr[], int freq[], const int n);
int rand_Func_randomcompanyselection(int freq[]);

#endif