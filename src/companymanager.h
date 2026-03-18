#ifndef COMPANYMANAGER_H
#define COMPANYMANAGER_H
#include <stdio.h>
#include <string.h>
#include "lcd.h"

// companies
struct company_1 { char name[23]; int payment;}; // Hederlige Harrys Bilar
struct company_2 { char name[22]; int payment;}; // Farmor Ankas Pajer AB
struct company_3 { char name[27]; int payment;}; // Svarte Petters Svartbyggen
struct company_4 { char name[24]; int payment;}; // Långbens detektivbyrå
struct IOT_Commercial { char name[18]; int payment;}; // IOT

// companie ad functions
void company_1_advertising();
void company_2_advertising();
void company_3_advertising();
void company_4_advertising();
void IOT_Commercial_advertising(struct IOT_Commercial c);

// functions for selecting random company comercial
int rand_Func_myRand(int arr[], int freq[], const int n);
void rand_Func_randomcompanyselection(void);

#endif