#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int ATM_Transaction();
void Again();
int pin=0,Wpin=0,Amount_Withdraw,Amount_Deposit,Another_Transaction;
double balance=10000;

int main()
{
    double p,i;
    system("cls");
    do
    {
        printf("********* ABC BANK *********\n");
        printf("Enter Your PIN / Secreat number\n");
        /*for(i=0;i<=3;i++) {p=getch();pin=(int)pin+(int)pow(p,i);}*/
        scanf("%d",&pin);
        if(pin!=1234)
        {
            if(Wpin<3)
            {
                Wpin++;
                printf("Please enter correct pin %d chance remain", 3-Wpin);
            }
            else
            {
                exit(0);
            }

        }
        else
        {
            ATM_Transaction();
        }
    }
    while(Wpin<3);

    return 0;

}

int ATM_Transaction()
{
    int choice;
    system("cls");
    printf("Select any option\n");
    printf("1. Balance Enquiry \n");
    printf("2. Cash Withdraw \n");
    printf("3. Deposit Cash \n");
    printf("4. Exit \n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        system("cls");
        printf("Your Balance is %2lf\n",balance);
        printf("If u want another transaction then\nPress 1 for again\nPress 2 for exit\n");
        scanf("%d",&Another_Transaction);
        Again();
    break;

    case 2:
        system("cls");
        printf("Enter Withdraw Amount\n");
        scanf("%d",&Amount_Withdraw);
        if(Amount_Withdraw<=balance)
        {printf("Your transaction is completed\nCollect Your Cash"); balance=balance-Amount_Withdraw;Again(); }
        else{printf("Insificient Balance\n");Again();}
    break;

    case 3:
        system("cls");
        printf("Enter Deposit Amount\n");
        scanf("%d",&Amount_Deposit);
        balance=balance+Amount_Deposit;
        printf("Your transaction is completed\nYour Cash is Deposited\n");
        Again();

    break;

    case 4:
        system("cls");
        exit(0);

    default:
        system("cls");
        printf("You enter wrong choice\n");
    exit(0);
    }
}

void Again()
{
    if(Another_Transaction==1){ATM_Transaction();}
        else if(Another_Transaction==2){exit(0);}
        else{printf("You enter wrong choice\n");exit(0);}
}
