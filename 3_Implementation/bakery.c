#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void checkbalance(char *);
void transfermoney(void);
void Menu(void);
void show_det(char *);
void person(char *);
void login(void);
void login_suc(void);
void account(void);
void accountcreated(void);
void login_fail(void);
void logout(void);
void bill(void);

struct pass
{
    char username[50];
    int date;
    int month;
    int year;
    char pnumber[15];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
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
    int i, a, b, choice;
    int passwordlength;

    // Creating a Main
    // menu for the user
    printf("\n\n");
    printf("WELCOME TO DELICIOUS FOODS\n\n");

    printf("**********************************\n\n");

    printf("APPLE BACKERY- richness of flavours\n \n");

    printf("1.... CREATE A LOGIN ACCOUNT \n \n");

    printf("2.... ALREADY A USER? SIGN IN \n \n");

    printf("3.... EXIT\n \n");

    printf("\n \nENTER YOUR CHOICE..");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
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

        getch();
    }
}
void account(void)
{
    char password[20];
    int passwordlength, i, seek = 0;
    char ch;
    FILE *fp, *fu;
    struct pass u1;
    struct userpass p1;

    struct userpass u2;

    // Opening file to
    // write data of a user
    fp = fopen("username.txt", "ab");

    // Inputs
    system("cls");
    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

    printf("\n\nFIRST NAME..");
    scanf("%s", &u1.fname);

    printf("\n\n\nLAST NAME..");
    scanf("%s", &u1.lname);

    printf("\n\nFATHER's NAME..");
    scanf("%s", &u1.fathname);

    printf("\n\nMOTHER's NAME..");
    scanf("%s", &u1.mothname);

    printf("\n\nADDRESS..");
    scanf("%s", &u1.address);

    printf("\n\nDATE OF BIRTH..");
    printf("\nDATE-");
    scanf("%d", &u1.date);
    printf("\nMONTH-");
    scanf("%d", &u1.month);
    printf("\nYEAR-");
    scanf("%d", &u1.year);

    printf("\n\nPHONE NUMBER");
    scanf("%s", u1.pnumber);

    printf("\n\nUSERNAME.. ");
    scanf("%s", &u1.username);

    printf("\n\nPASSWORD..");

    // Taking password in the form of
    // stars
    for (i = 0; i < 50; i++)
    {
        ch = getch();
        if (ch != 13)
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }

    // Writing to the file
    fwrite(&u1, sizeof(u1),
           1, fp);

    // Closing file
    fclose(fp);

    // Calling another function
    // after successful creation
    // of account
    accountcreated();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////created
void accountcreated(void)
{
    int i;
    char ch;
    system("cls");
    printf("PLEASE WAIT UNTIL....\n\nYOUR DATA IS PROCESSING....");
    for (i = 0; i < 200000000; i++)
    {
        i++;
        i--;
    }

    printf("\n \n ACCOUNT CREATED SUCCESSFULLY(order & enjoy).....");

    printf("\nPress enter to login");

    getch();
    login();
}
///////////////////////////////////login
void login(void)
{
    system("cls");

    char username[50];
    char password[50];

    int i, j, k;
    char ch;
    FILE *fp, *fu;
    struct pass u1;
    struct userpass u2;

    // Opening file of
    // user data
    fp = fopen("username.txt", "rb");

    if (fp == NULL)
    {
        printf("ERROR IN OPENING FILE");
    }

    printf(" ACCOUNT LOGIN ");

    printf("***********************************************");

    printf("==== LOG IN ====");

    printf("USERNAME.. ");
    scanf("%s", &username);

    printf("PASSWORD..");

    // Input the password
    for (i = 0; i < 50; i++)
    {
        ch = getch();
        if (ch != 13)
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }

        else
            break;
    }

    // Checking if username
    // exists in the file or not
    while (fread(&u1, sizeof(u1),
                 1, fp))
    {
        if (strcmp(username,
                   u1.username) == 0)
        {
            login_suc();
            show_det(username);
        }
    }

    // Closing the file
    fclose(fp);
}
void login_fail(void)
{
    int i;
    for (i = 0; i < 20000; i++)
    {
        i++;
        i--;
        break;
    }

    printf("\n\t\t\t\t...........data mismatched ^_^ try again...........");
}
/////////////////////////////////success
void login_suc(void)
{
    int i;
    FILE *fp;
    struct pass u1;
    system("cls");
    printf("PLZ WAIT A WHILE.....\t");
    printf("fetching details\n\n");
    for (i = 0; i < 20000; i++)
    {
        i++;
        i--;
    }

    printf("LOGIN SUCCESSFUL :-) :-) :-)..../n");
    printf("Press enter to continue");

    getch();
}

///////////////////////////////////details

void show_det(char username1[])
{
    system("cls");
    FILE *fp;
    int choice, i;
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

            printf("\nMOTHER's NAME..%s", u1.mothname);

            printf("\nMOBILE NUMBER..%s", u1.pnumber);

            printf("\nDATE OF BIRTH.. %d-%d-%d", u1.date, u1.month, u1.year);

            printf("\nADDRESS..%s", u1.address);
        }
    }

    fclose(fp);

    // Menu to perform different
    // actions by user
    printf(" \nHOME\n ");
    printf("******\n");
    printf(" 1....CHECK BALANCE\n");
    printf(" 2....ADD MONEY\n");
    printf(" 3....MENU\n");
    printf(" 4....LOG OUT\n\n");
    printf(" 5....EXIT\n\n");

    printf(" ENTER YOUR CHOICES..");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        checkbalance(username1);
        break;

    case 2:
        transfermoney();
        break;
    case 3:
        Menu();
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
    char ch2;
    int o;
    printf("1...STATERS");
    printf("2...MAIN COURSE");
    printf("3...DESERTS");
    printf("ENTER YOUR CHOICE");
    scanf("%d", &men_ch);

    switch (men_ch)
    {
    case 1:
        printf("here you go\n");
        printf("a.Vegetable gyoza --- Rs89/-");
        printf("\nenter ur choices according to pallate");
        scanf("%c", ch2);
        

        switch (ch2)
        {
        case 'a':
            printf("DO YOU WANT TO ORDER");
            printf("yes or no(1 for YES and 0 for NO");
            scanf("%d", &o);
            switch (o)
            {
            case 1:
                printf("thank you for order");
                break;

            case 2:
                printf("try another");
                break;
            }

            break;

        case 'b':
            break;

        case 'c':

            break;

        case 'd':
            break;
        }
        break;

    case 2:
        printf("");
        break;

    case 3:
        printf("");
        break;
    }
}

void transfermoney(void)
{
    int i, j;
    FILE *fm, *fp;
    struct pass u1;
    struct money m1;
    char usernamet[20];
    char usernamep[20];
    system("cls");

    // Opening file in read mode to
    // read user's username
    fp = fopen("username.txt", "rb");

    // Creating a another file
    // to write amount along with
    // username to which amount
    // is going to be transfered
    fm = fopen("mon.txt", "ab");

    printf("---- ADDING MONEY TO WALLET----\n");
    printf("========================");

    printf("FROM (your username).. ");
    scanf("%s", &usernamet);

    printf(" TO (name of wallet)..");
    scanf("%s", &usernamep);

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
    printf("ENTER THE AMOUNT TO BE ADDED..");
    scanf("%d", &m1.money1);

    // Writing to the file
    fwrite(&m1, sizeof(m1), 1, fm);

    printf(
        "--------------------------------------------------"
        "--------------------------------------------");

    printf(
        "--------------------------------------------------"
        "--------------------------------------------");

    printf("Adding amount, Please wait..");

    for (i = 0; i < 70; i++)
    {
        for (j = 0; j < 1200000; j++)
        {
            j++;
            j--;
        }
        printf("*");
    }

    printf("AMOUNT ADDED SUCCESSFULLY ....");
    getch();

    // Close the files
    fclose(fp);
    fclose(fm);

    // Function to return
    // to the home screen
    show_det(usernamet);
}

void checkbalance(char username2[])
{
    system("cls");
    FILE *fm;
    struct money m1;
    char ch;
    int i = 1, summoney = 0;

    // Opening amount file record
    fm = fopen("mon.txt", "rb");

    printf("==== BALANCE DASHBOARD ====");
    printf("***************************");
    printf("S no.\t");
    printf("TRANSACTION ID|t");
    printf("AMOUNT \t");

    // Reading username to
    // fetch the correct record
    while (fread(&m1, sizeof(m1), 1, fm))
    {
        if (strcmp(username2, m1.usernameto) == 0)
        {
            printf("%d", i);
            i++;
            printf("%s", m1.userpersonfrom);

            printf("%d", m1.money1);
            // Adding and
            // finding total money
            summoney = summoney + m1.money1;
        }
    }

    printf("TOTAL AMOUNT");

    printf("%d", summoney);

    getch();

    // Closing file after
    // reading it
    fclose(fm);
    show_det(username2);
}

void logout(void)
{
    int i, j;
    system("cls");
    printf("please wait, logging out");

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

    printf("press any key to continue..");

    getch();
}
