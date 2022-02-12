/**
 * @file bakery.c
 * @author KOTTAKOTA ARAVIND (aravindsurya62071@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-02-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bill1.h"
#include "functions.h"

struct pass
{
    char username[50];
    int date;
    int month;
    int year;
    int pnumber;
    char fname[20];
    char lname[20];
    char fathname[20];
    char address[50];
};

struct userpass
{
    char password[50];
};

struct money
{
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};
//////////////////////////main
int main()
{
    int choice;

    // Creating a Main
    // menu for the user
    printf("\n\n");
    printf("\t\t                      ****************WELCOME TO APPLE RESTURANT***************\n");

    printf("\t                         --------------------------------------------------------------------\n\n");

    printf(" \t\t\t\t\t\t               APPLE BACKERY RESTURANT- richness of flavours\n \n");

    printf("\t\t\t1.... CREATE A LOGIN ACCOUNT \n \n");

    printf("\t\t\t2.... ALREADY A USER? SIGN IN \n \n");

    printf("\t\t\t3.... EXIT\n \n");

    printf("\n \n\t\t\tENTER YOUR CHOICE..");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:

        printf("\n\n USERNAME 50 CHARACTERS MAX!!");
        printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
        account();
        break;

    case 2:
        login();
        break;

    case 3:
        exit(0);
        break;

    }
}
void account(void)
{
    struct userpass p1;
    FILE *fp;
    struct pass u1;

    // Opening file to
    // write data of a user
    fp = fopen("username.txt", "ab");

    // Inputs
    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

    printf("\n\nFIRST NAME..");
    scanf("%s", &u1.fname[20]);

    printf("\n\nLAST NAME..");
    scanf("%s", &u1.lname[20]);

    printf("\n\nFATHER's NAME..");
    scanf("%s", &u1.fathname[20]);

    printf("\n\nADDRESS..");
    scanf("%s", &u1.address[50]);

    printf("\n\nDATE OF BIRTH..");
    printf("\nDATE-");
    scanf("%d", &u1.date);
    printf("\nMONTH-");
    scanf("%d", &u1.month);
    printf("\nYEAR-");
    scanf("%d", &u1.year);

    printf("\n\nPHONE NUMBER:");
    scanf("%d", &u1.pnumber);

    printf("\n\nUSERNAME..: ");
    scanf("%s", &u1.username[50]);

    printf("\n\nPASSWORD..:");
    scanf("%s", &p1.password[50]);

    // Taking password in the form of
    // stars

    // Writing to the file
    fwrite(&u1, sizeof(u1), 1, fp);

    // Closing file
    fclose(fp);

    accountcreated();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////created
void accountcreated(void)
{
    int i;

    printf("PLEASE WAIT UNTIL....\n\nYOUR DATA IS PROCESSING....");
    for (i = 0; i < 200000000; i++)
    {
        i++;
        i--;
    }

    printf("\n \n ACCOUNT CREATED SUCCESSFULLY(order & enjoy) :) :) :).....");

    printf("\nPress enter to login");

    login();
}
///////////////////////////////////login
void login(void)
{

    char username[50];
    char password[50];

    FILE *fp;
    struct pass u1;
    struct userpass p1;

    // Opening file of
    // user data
    fp = fopen("username.txt", "rb");

    if (fp == NULL)
    {
        printf("ERROR IN OPENING FILE");
    }

    printf("\n \t\t\t ACCOUNT LOGIN ");

    printf("\n \t***********************************************");

    printf("\n \n \t\t\t==== LOG IN ====");

    printf("\nUSERNAME.. ");
    scanf("%s", &username[50]);

    printf("\nPASSWORD..");
    scanf("%s", &password[50]);
    // Input the password

    // Checking if username
    // exists in the file or not
    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if ((strcmp(username, u1.username) == 0) || (strcmp(password, p1.password) == 0))
        {
            login_suc();
            show_det(username);
        }
    }

    // Closing the file
    fclose(fp);
}

/////////////////////////////////success
void login_suc(void)
{
    int i;

    printf("PLZ WAIT A WHILE.....\t");
    printf("\n \t\tfetching details\n\n");
    for (i = 0; i < 20000; i++)
    {
        i++;
        i--;
    }

    printf("\nLOGIN SUCCESSFUL :-) :-) :-)....\n");
    printf("\n\nPress enter to continue");

   
}

///////////////////////////////////details

void show_det(char username1[])
{

    FILE *fp;
    int choice;
    fp = fopen("username.txt", "rb");
    struct pass u1;

    if (fp == NULL)
    {
        printf("error in opening file");
    }

    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if (strcmp(username1, u1.username) == 0)
        {
            printf("WELCOME, %s %s", u1.fname, u1.lname);

            printf("\n..........................\n");
            printf("\n==== YOUR ACCOUNT INFO ====\n");
            printf("\n***************************\n");
            printf("\nNAME..%s %s", u1.fname, u1.lname);

            printf("\nFATHER's NAME..%s %s", u1.fathname, u1.lname);

            printf("\nMOBILE NUMBER..%d", u1.pnumber);

            printf("\nDATE OF BIRTH.. %d-%d-%d", u1.date, u1.month, u1.year);

            printf("\nADDRESS..%s", u1.address);
        }
    }

    fclose(fp);

    // Menu to perform different
    // actions by user
    printf(" \nHOME\n ");
    printf("******\n");
    printf(" 1....MENU\n");
    printf(" 2....ADD MONEY\n");
    printf(" 3....CHECK BALANCE\n");
    printf(" 4....LOG OUT\n");
    printf(" 5....EXIT\n");

    printf(" ENTER YOUR CHOICES..");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        Menu();
        break;

    case 2:
        transfermoney();
        break;
    case 3:
        checkbalance(username1);
        break;

    case 4:
        logout();
        login();
        break;

    case 5:
        exit(0);
        break;
    }
}
void Menu(void)
{
    int men_ch;
    int p;
    printf("\n1...STATERS");
    printf("\n2...MAIN COURSE");
    printf("\n3...DESERTS");
    printf("\n4...BOOK A DINE^_-");
    printf("\n enter ur choices according to pallate : ");
    scanf("%d", &men_ch);

    switch (men_ch)
    {
    case 1:
        bill1();
        break;

    case 2:
        bill();
        break;

    case 3:
        bill();
        break;

    case 4:

        printf("enter how many people : ");
        scanf("%d", &p);
        printf("The dine is booked for %d people", p);
        break;
    }
}

void bill(void)
{

    char response = 'y';

    printMeals();
    while (response == 'y' || response == 'Y')
    {
        printf("please enter number of persons  :");
        scanf("%d", &peopleNumber);

        orderMeals();

        printf("\nwould you like to continue(y/n):");
        scanf("\n%c", &response);
    }

    printf("\n      ******************** THANK YOU FOR COMING  *************************\n");
    printf("\20**********************   HOPE IT PLEASURES UR PALLETE  **************************\20 \n");
    system("pause");
}

void printMeals()
{

    printf("\20*******************  WELCOME TO APPLE BACKERY RESTURANT **************************\20\n");
    printf(" \t\t\t Below is the menue:\20\n");
    printf(" \t\t\t MEALS\t\t\tPRICE:\n");
    printf(" \t\t\t \22*******************************\22\n");
    printf(" \t\t\t 1- Fish and Chips\tRS180.00\n");
    printf(" \t\t\t 2- chickne Spaghetti\tRS105.00\n");
    printf(" \t\t\t 3- T-Bone Mutton\tRS190.00\n");
    printf(" \t\t\t 4- Chicken Chop\tRS140.00\n");
    printf(" \t\t\t 5- Chicken Maryland\tRS120.00\n");
    printf(" \t\t\t 6- Red Lobster\tRS220.00\n");
    printf(" \t\t\t 7- Seafood Platter\tRS160.00\n");

    printf("\n");
}
void orderMeals()
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
double orderForPerson()
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
            scanf("\n%c", &response);
        }
        printf("\n");
        totalAllPerson += totalAllPerson + totalPerPerson;
        totalPerPerson = 0.0;
        response = 'y';
    }

    return totalAllPerson + ((totalAllPerson * tax) / 100);
}

void transfermoney(void)
{
    int i, j;
    FILE *fm, *fp;
    struct pass u1;
    struct money m1;
    char usernamet[20];
    char usernamep[20];

    // Opening file in read mode to
    // read user's username
    fp = fopen("username.txt", "rb");

    // Creating a another file
    // to write amount along with
    // username to which amount
    // is going to be transfered
    fm = fopen("mon.txt", "ab");

    printf("---- ADDING MONEY TO WALLET----\n");
    printf("========================\n\n");

    printf("\nFROM (your username).. ");
    scanf("%s", &usernamet[50]);

    printf("\n TO (name of wallet)..");
    scanf("%s", &usernamep[50]);

    // Checking for username if it
    // is present in file or not
    while (fread(&u1, sizeof(u1), 1, fp))

    {
        if (strcmp(usernamep, u1.username) == 0)
        {
            strcpy(m1.usernameto, u1.username);
            strcpy(m1.userpersonfrom, usernamet);
        }
    }

    // Taking amount input
    printf("\nENTER THE AMOUNT TO BE ADDED..\n\n");
    scanf("%ld", &m1.money1);

    // Writing to the file
    fwrite(&m1, sizeof(m1), 1, fm);

    printf(
        "--------------------------------------------------"
        "--------------------------------------------");

    printf(
        "--------------------------------------------------"
        "--------------------------------------------");

    printf("\nAdding amount, Please wait..");

    for (i = 0; i < 70; i++)
    {
        for (j = 0; j < 1200000; j++)
        {
            j++;
            j--;
        }
        printf("*");
    }

    printf("\n                     AMOUNT ADDED SUCCESSFULLY ....");

    // Close the files
    fclose(fp);
    fclose(fm);

    // Function to return
    // to the home screen
    show_det(usernamet);
}

void checkbalance(char username2[])
{

    FILE *fm;
    struct money m1;
    int i = 1, summoney = 0;

    // Opening amount file record
    fm = fopen("mon.txt", "rb");

    printf("      ==== BALANCE DASHBOARD ====\n");
    printf("\n    ***************************");
    // Reading username to
    // fetch the correct record
    while (fread(&m1, sizeof(m1), 1, fm))
    {
        if (strcmp(username2, m1.usernameto) == 0)
        {
            printf("\nS no.: %d \n", i);
            i++;
            printf("\nTRANSACTION ID : %s \n", m1.userpersonfrom);

            printf("\nAMOUNT : %ld \n", m1.money1);
            // Adding and
            // finding total money
            summoney = summoney + m1.money1;
        }
    }

    printf("\nTOTAL AMOUNT =%d", summoney);


    // Closing file after
    // reading it
    fclose(fm);
    show_det(username2);
}

void logout(void)
{
    int i, j;

    printf("\n    please wait, logging out");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 25000000; j++)
        {
            i++;
            i--;
        }
        printf(".");
    }

    printf("Sign out successfully..\n");

    printf("             press any key to continue..");


}