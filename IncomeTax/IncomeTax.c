/*********************************************************
 * Author: Filip Matic
 * Title: IncomeTax.c 
 * Description: Calculates income tax based on user entered
 * income value. Note, there are not real tax values, 
 * this code is meant for demonstration purposes. 
 *********************************************************/
#include <stdio.h>
int main(void)

{
// Declare variables
double Salary;
double Tax;

printf("Enter income:");
scanf("%lf", &Salary);

	if (Salary<20000)
	{
	Tax=Salary*(.15);
	printf("Tax amount: %lf\n", Tax);
	}

	if (Salary>20000 && Salary<35000)
	{
	Tax=(.15)*(20000)+((Salary-20000)*(.20));
	printf("Tax amount: %lf\n:", Tax);	
	}

	if (Salary>35000 && Salary<50000)
	{
	Tax=(.15)*(20000)+(.20)*(15000)+((Salary-35000)*(.25));
	printf("Tax amount: %lf\n:", Tax);
	}

	if (Salary>50000 && Salary<100000)
	{
	Tax=(.15)*(20000)+(.20)*(15000)+(.25)*(15000)+((Salary-50000)*(.30));
	printf("Tax amount: %lf\n:", Tax);
	}

	if (Salary>100000)
	{
	Tax=(.15)*(20000)+(.20)*(15000)+(.25)*(15000)+(.30)*(50000)+((Salary-100000)*(.35));
	printf("Tax amount: %lf\n:", Tax);
	}  
	return 0;
}
