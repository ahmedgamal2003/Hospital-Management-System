#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hospital.h"


extern int counter;
extern hos arr[50];


void new_pat(void)
{
    hos new_p;
    printf("\n\nEnter the name of patient number %i: ",counter+1);
    fflush(stdin);
    gets(new_p.name);
    printf("Enter the bed number: ");
    scanf("%i",&new_p.bed_number);
 L1:printf("Enter the cash: ");
    scanf("%lf",&new_p.cash);
    if(new_p.cash<0)
    {
        printf("The cash must be positive\n");
        goto L1;
    }
    printf("Enter account status (paid or unpaid): ");
    fflush(stdin);
    gets(new_p.type);
    printf("Enter the doctor's name: ");
    fflush(stdin);
    gets(new_p.doc);
    arr[counter]=new_p;
    counter++;
}


void edit_pat(int bed_number)
{
    int i;
    for(i=0;i<=counter;i++)
    {
        if(bed_number==arr[i].bed_number)
        {
            printf("\n\nEnter the patient's new name: ");
            fflush(stdin);
            gets(arr[i].name);
            printf("Enter the new bed number: ");
            scanf("%i",&arr[i].bed_number);
         L2:printf("Enter the cash: ");
            scanf("%lf",&arr[i].cash);
            if(arr[i].cash<0)
            {
                printf("The cash must be positive\n");
                goto L2;
            }
            printf("Enter account status (paid or unpaid): ");
            fflush(stdin);
            gets(arr[i].type);
            printf("Enter the doctor's name: ");
            fflush(stdin);
            gets(arr[i].doc);
            break;
        }
    }
}


void delete_pat(int bed_number)
{
    int i,index;
    for(i=0;i<=counter;i++)
    {
        if(arr[i].bed_number==bed_number)
        {
            index=i;
            for(i=0;i<=counter;i++)
            {
                arr[i]=arr[i+1];
            }
        }
    }
    arr[counter].bed_number=-1;
    arr[counter].cash=-1;
    strcpy(arr[counter].doc,"-1");
    strcpy(arr[counter].name,"-1");
    strcpy(arr[counter].type,"-1");
    counter--;
}

void print_data(int bed_number)
{
    int i;
    for(i=0;i<=counter;i++)
    {
        if(arr[i].bed_number==bed_number)
        {
            printf("\n\npatient name: %s\n",arr[i].name);
            printf("Bed number: %i\n",arr[i].bed_number);
            printf("Doctor name: %s\n",arr[i].doc);
            printf("Account status: %s\n",arr[i].type);
            printf("Cash: %.2lf\n",arr[i].cash);
            break;
        }
    }
}

void account_inquiry(int bed_number)
{
    int i;
    for(i=0;i<=counter;i++)
    {
        if(arr[i].bed_number==bed_number)
        {
            if(strcmp(arr[i].type,"paid")==0)
            {
                printf("\n\nThere are no funds payable\n");
                break;
            }
            else
            {
                printf("\n\nThere are funds payable up to: %.2lf\nThanks\n",arr[i].cash);
                break;
            }
        }
    }
}


void pay_money(int bed_number,double money)
{
    int i;
    for(i=0;i<=counter;i++)
    {
     L4:if(arr[i].bed_number==bed_number)
        {
            if(money>arr[i].cash)
            {
                printf("\n\nThe money greater than cash\nTry again\nEnter the money: ");
                scanf("%i",arr[i].cash);
                goto L4;
            }
            else
            {
                arr[i].cash=arr[i].cash-money;
                printf("remaining: %.2lf\n",arr[i].cash);
                break;
            }
        }
    }
}
