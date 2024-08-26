#include <stdio.h>
#include <stdlib.h>
#include "Hospital.h"
int counter;
hos arr[50];
int main()
{
    int bed_number;
    double money;
    char choice;
    while(1)
    {
        printf("\n\n\n===============================================\n");
        printf("=================== Welcome ===================\n");
        printf("===============================================\n");
             printf("Select the your choice :\n\n\
1-new Patient\n\
2-Edit Patient data\n\
3-delete Patient data\n\
4-print data\n\
5-Money payable\n\
6-account inquiry\n\
7-Exit\n\n\
Your choice: ");
    fflush(stdin);
    scanf("%c",&choice);
    switch (choice)
    {
    case '1':
        if(counter>3)
        {
            printf("\n\nYou can't add a new patient\n");
            break;
        }
        new_pat();
        break;
    case '2':
        printf("\n\nEnter the bed number: ");
        scanf("%i",&bed_number);
        edit_pat(bed_number);
        break;
    case '3':
        printf("\n\nEnter the bed number: ");
        scanf("%i",&bed_number);
        delete_pat(bed_number);
        break;
    case '4':
        printf("\n\nEnter the bed number: ");
        scanf("%i",&bed_number);
        print_data(bed_number);
        break;
    case '5':
        printf("\n\nEnter the bed number: ");
        scanf("%i",&bed_number);
     L1:printf("Enter the money: ");
        scanf("%lf",&money);
        if(money<=0)
        {
            printf("The money must be greater the zero\nTry again\n");
            goto L1;
        }
        pay_money(bed_number,money);
        break;
    case '6':
        printf("\n\nEnter the bed number: ");
        scanf("%i",&bed_number);
        account_inquiry(bed_number);
        break;
    case '7':
        exit(0);
    default:
        printf("\nWrong choice \n");
    }

    }
    return 0;
}
