/*----------------------------------------------------*/ 
/* HOMEWORK: Assignment 2                             */ 
/*                                                    */ 
/* NAME:     Dalton Okechukwu                         */ 
/*                                                    */ 
/* CLASS:    C Programming (INFO.90.267)              */ 
/*                                                    */ 
/* DATE:     04-Feb-2016                              */ 
/*                                                    */
/* DESCRIPTION:                                       */
/* This program will prompt for number of employees   */ 
/* whose gross pay will then be calculated. Uses a    */ 
/* 'for' loop going from the first loop index to the  */ 
/* target number of iterations. Uses conditional      */
/* expressions to compute overtime.                   */
/*----------------------------------------------------*/

#include <stdio.h>

/*define constants*/
#define STD_HOURS		40.0
#define OT_FACTOR		1.5
#define NO_OVERTIME		0.0

int main()
{
    int clockNumber;         /*employee clock number*/
	float wageRate;          /*employee wage rate per hour*/
	float numberOfHours;     /*number of hours worked per week*/
	int loopCount;           /*number of test data*/
	int loopIndex;           /*index of each loop*/
	float grossPay;          /*how much the employee is entitled to*/
	float overTime;          /*how much overtime by employee*/
	
	printf ("***Employee Gross Pay Calculator***\n"); /*print program header*/ 
	
	/*prompt user for number of data sets available*/
    printf ("Enter number of employees to process: \n");  
	scanf ("%i", &loopCount);
	
	/*initiate loop for number of employees*/
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
		
		if (numberOfHours > STD_HOURS)
		{
			/*calculate overtime hours*/
			overTime = numberOfHours - STD_HOURS; 
			/*calculate employee gross pay*/
			grossPay = (STD_HOURS * wageRate) + (overTime * wageRate * OT_FACTOR); 
		}
		else
		{
			/*calculate overtime hours*/
			overTime = NO_OVERTIME;
			/*calculate employee gross pay*/
			grossPay = wageRate * numberOfHours;
		}
		printf ("----------------------------------------\n"); /*format output header*/
		printf ("Clock# \tWage \tHours \tOT \tGross\n"); /*display header*/
		printf ("----------------------------------------\n"); /*format output header*/
		
		/*print results to screen*/
		printf ("%06i \t%5.2f \t%4.1f \t%4.1f \t%6.2f\n", clockNumber, wageRate, 
		numberOfHours, overTime, grossPay); 
		printf ("\n"); /*new line*/
	}
	
    return (0); /*success*/
}               /*end main*/