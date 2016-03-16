/*----------------------------------------------------*/ 
/* HOMEWORK: Assignment 1                             */ 
/*                                                    */ 
/* NAME:     Dalton Okechukwu                         */ 
/*                                                    */ 
/* CLASS:    C Programming (INFO.90.267)              */ 
/*                                                    */ 
/* DATE:     27-Jan-2016                              */ 
/*                                                    */
/* DESCRIPTION:                                       */
/* This program will prompt for number of employees   */ 
/* whose gross pay will be calculated. It uses a 'for'*/ 
/* loop going from the first loop index to the target */ 
/* number of iterations.                              */ 
/*----------------------------------------------------*/

#include <stdio.h>

int main()
{
    int clockNumber;         /*employee clock number*/
	float wageRate;          /*employee wage rate per hour*/
	float numberOfHours;     /*number of hours worked per week*/
	int loopCount;           /*number of test data*/
	int loopIndex;           /*index of each loop*/
	float grossPay;          /*how much the employee is entitled to*/
	
	
	printf ("***Employee Pay Calculator***\n");
	/*prompt user for number of data sets available*/ 
    printf ("Enter number of employees to process: \n");
	scanf ("%i", &loopCount);
	
	for (loopIndex = 1; loopIndex <= loopCount; ++loopIndex)
	{
		/*prompt user for employee clock number*/ 
		printf ("Enter employee clock number: \n");
		scanf ("%i", &clockNumber);
	
		/*prompt user for employee wage rate*/ 
		printf ("Enter hourly wage rate: \n");
		scanf ("%f", &wageRate);
	
		/*prompt user for number of hours worked this week*/ 
		printf ("Enter number of hours worked: \n");
		scanf ("%f", &numberOfHours);
		
		/*calculate employee gross pay*/
		grossPay = wageRate * numberOfHours;
		
		printf ("\t-----------------------------\n"); /*format output header*/
		printf ("\tClock#   Wage   Hours   Gross\n");       /*display header*/
		printf ("\t-----------------------------\n"); /*format output header*/
		printf ("\t%06i %6.2f %6.1f %6.2f \n", clockNumber, wageRate, numberOfHours, grossPay); /*print results to screen*/
		printf ("\n");
	}
	
    return (0); /*success*/
}               /*end main*/