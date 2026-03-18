#ifndef COMPANYMANAGER_H
#define COMPANYMANAGER_H
#include <stdio.h>
#include <string.h>


struct company_1 { char name[23]; };
struct company_2 { char name[22]; };
struct company_3 { char name[27]; };
struct company_4 { char name[24]; };
struct IOT_Commercial { char name[18]; };

void company_1_advertising(struct company_1 c);
void company_2_advertising(struct company_2 c);
void company_3_advertising(struct company_3 c);
void company_4_advertising(struct company_4 c);
void IOT_Commercial_advertising(struct IOT_Commercial c);

// functions for selecting random company comercial
int rand_Func_myRand(int arr[], int freq[], const int n);
void rand_Func_randomcompanyselection(void);

#endif