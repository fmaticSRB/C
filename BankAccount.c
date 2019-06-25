/*********************************************************
 * Author: Filip Matic
 * Title: BankAccount.c 
 * Description: Allows the user to enter amount of money in
 * both checking and savings account. User can then make
 * a deposit, a transfer, or withdraw. 
 * 
 * Note: User can only make one action. More actions will be
 * added over time.
 *********************************************************/
#include <stdio.h>
int main(void)

{

double Checking;
double Savings;
int Choice;
double Deposit;
double Withdraw;
double Transfer;

printf("Enter checking account starting balance:");
scanf("%lf", &Checking);

printf("Enter saving account starting balance:");
scanf("%lf", &Savings);

printf("1 = Deposit into Savings\n2 = Transfer from Savings into Checking\n3 = Withdraw from Checking\n");

printf("Enter your choice of transactions:");
scanf("%d", &Choice);

	if ( Choice==1 )
	{
		printf("Enter deposit amount:");
		scanf("%lf", &Deposit);
		if (Deposit<0)
		{
			printf("The entered amount is not appropriate for the selected task\n");
		}
		else
		{
			Savings=Savings+Deposit;
			printf("New savings account balance: %lf\n", Savings);
			printf("New checking account balance: %lf\n", Checking);
		}
	}
	
	if ( Choice==2 )
	{
		printf("Enter transfer amount:");
    	scanf("%lf", &Transfer);
		if (Transfer>Savings || Transfer<0)
		{
			printf("The entered amount is not appropriate for the selected task\n");
        }
		else
        {
            Savings=Savings-Transfer;
			Checking=Checking+Transfer;
			printf("New savings account balance: %lf\n", Savings);
			printf("New checking account balance: %lf\n", Checking);
		}
	}

	if ( Choice==3 )
	{
		printf("Enter withdraw amuont:");
		scanf("%lf", &Withdraw);
		if (Withdraw>Checking || Withdraw<0)
		{
			printf("The entered amount is not appropriate for the selected task\n");
		}
		else
		{
			Checking=Checking-Withdraw;
			printf("New savings account balance: %lf\n", Savings);
			printf("New checking account balance: %lf\n", Checking);
		}
	}

	if ( Choice>4 )
	{
		printf("Entered selection is not available\n");
	}  
}
  