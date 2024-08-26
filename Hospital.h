#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct hospital
{
    char name[20];
    int bed_number;
    double cash;
    char type [20];
    char doc[20];
}hos;

void new_pat(void);
void edit_pat(int bed_number);
void delete_pat(int bed_number);
void print_data(int bed_number);
void account_inquiry(int bed_number);
void pay_money(int bed_number,double money);

