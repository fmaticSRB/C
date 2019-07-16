/*********************************************************
 * Author: Filip Matic
 * Title: CoinValuex.c 
 * Description: Calculates total value of coins and dollars
 * that the user has. User enters amount of each coin and 
 * will be given total dollar value. 
 *********************************************************/
#include <stdio.h>

int main(void)
{
// Declare variables
int dollars;
int change;
int quarters;
int dimes;
int nickels;
int pennies;
int total_dollars;
int total_cents;

// Prompt user to enter amount of each coin specified
printf("Enter number of dollars:");
scanf("%d", &dollars);

printf("Enter number of quarters:");
scanf("%d", &quarters);

printf("Enter number of dimes:");
scanf("%d", &dimes);

printf("Enter number of nickels:");
scanf("%d", &nickels);

printf("Enter number of pennies:");
scanf("%d", &pennies);

// Calculate total amount of cents
total_cents=(100*dollars)+(25*quarters)+(10*dimes)+(5*nickels)+(1*pennies);

// Calculate amount of dollars and cents
dollars=total_cents/100;
change=total_cents%100;

// Display results to user
printf("The total value of your coins is %d dollars and %d cents\n", dollars, change);

return (0);
}

