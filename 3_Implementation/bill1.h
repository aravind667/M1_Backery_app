#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
double price[7] = {180.00, 105.00, 190.00, 140.00, 120.00, 220.00, 160.00};
double mealTaxPrices[7];
int peopleNumber;
void bill1(void)
{

    char response = 'y';

    printStaters();
    while (response == 'y' || response == 'Y')
    {
        printf("please enter number of persons  :");
        scanf("%d", &peopleNumber);

        orderMeals1();

        printf("\nwould you like to continue(y/n):");
        scanf("\n%c", &response);
    }

    printf("\n      ******************** THANK YOU FOR COMING  *************************\n");
    printf("\20**********************   HOPE IT PLEASURES UR PALLETE  **************************\20 \n");
    system("pause");
}

void printStaters()
{

    printf("\20*******************  WELCOME TO APPLE BACKERY RESTURANT **************************\20\n");
    printf(" \t\t\t Below is the Staters:\20\n");
    printf(" \t\t\t MEALS\t\t\tPRICE:\n");
    printf(" \t\t\t \22*******************************\22\n");
    printf(" \t\t\t 1- Paneer Tikka\tRS180.00\n");
    printf(" \t\t\t 2- Sabudana Tikki\tRS105.00\n");
    printf(" \t\t\t 3- Veg Kofta  \tRS190.00\n");
    printf(" \t\t\t 4- VEG/NON_VEG MOMOS\tRS140.00\n");
    printf(" \t\t\t 5- VEG SPRING ROLLS\tRS120.00\n");
    printf(" \t\t\t 6- SPECIAL TIKKI COMBO\tRS220.00\n");
    printf(" \t\t\t 7- MANCHURIA \tRS160.00\n");

    printf("\n");
}
void orderMeals1()
{
    double totalPriceForFood;
    double allPayment, discount;
    printf("                      \t\t**** ORDER MENUE****\n");

    totalPriceForFood = orderForPerson();
    allPayment = totalPriceForFood;

    printf("\n \t\t     \22**************************************\22    \n");
    printf(" \t\t   ******************  final BILL   ************      \n");
    printf(" \t\t\tnumber\t\tcount\t\ttotal price\n");
    printf(" \t\t\tpersons\t\t%d\t\t%5.2f\n", peopleNumber, totalPriceForFood);
    printf(" \t\t\tTotal bill\t\t\t%5.2f\n", allPayment);

    if (allPayment < 10)
        discount = ((allPayment * 0.5) / 100);
    else if (allPayment >= 10 && allPayment < 20)
        discount = ((allPayment * 1) / 100);
    else if (allPayment >= 20 && allPayment < 30)
        discount = ((allPayment * 1.5) / 100);
    else if (allPayment >= 30 && allPayment < 40)
        discount = ((allPayment * 2.0) / 100);
    else
        discount = ((allPayment * 5.0) / 100);

    printf(" \t\t\tTotal bill after discount\t%5.2f\n", allPayment - discount);
}
double orderForPersonStat()
{
    int menuOption, i, amount;
    char response = 'y';
    double totalPerPerson = 0.0, totalAllPerson = 0.0;
    double tax = 5.0;
    if (peopleNumber <= 0)
        printf("\n ");
    else
        printf("*personol order:\n");
    for (i = 0; i < peopleNumber; i++)
    {
        printf("Person %d please enter your orders\n", i + 1);
        while (response == 'y' || response == 'Y')
        {
            printf("please enter your option:");
            scanf("%d", &menuOption);
            if (menuOption < 1 || menuOption > 7)
            {
                printf("sorry we don`t have this order \nagain! ");
                continue;
            }
            printf("please enter your amount of order:");
            scanf("%d", &amount);

            totalPerPerson = totalPerPerson + (amount * price[menuOption - 1]);

            printf("\nWould you like to enter more orders(y/n):");
            scanf("\n%c", &response);
        }
        printf("\n");
        totalAllPerson += totalAllPerson + totalPerPerson;
        totalPerPerson = 0.0;
        response = 'y';
    }

    return totalAllPerson + ((totalAllPerson * tax) / 100);
}