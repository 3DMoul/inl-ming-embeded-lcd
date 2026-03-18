#ifndef COMPANYMANAGER_H
#define COMPANYMANAGER_H
#include <stdio.h>
#include <string.h>

// companies
struct company_1 { char name[23]; }; // Hederlige Harrys Bilar
struct company_2 { char name[22]; }; // Farmor Ankas Pajer AB
struct company_3 { char name[27]; }; // Svarte Petters Svartbyggen
struct company_4 { char name[24]; }; // Långbens detektivbyrå
struct IOT_Commercial { char name[18]; }; // IOT

// companie ad functions
void company_1_advertising(struct company_1 c);
void company_2_advertising(struct company_2 c);
void company_3_advertising(struct company_3 c);
void company_4_advertising(struct company_4 c);
void IOT_Commercial_advertising(struct IOT_Commercial c);

// functions for selecting random company comercial
int rand_Func_myRand(int arr[], int freq[], const int n);
void rand_Func_randomcompanyselection(void);

#endif