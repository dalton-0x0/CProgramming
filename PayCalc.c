#include <stdio.h>

/*define constants to use*/ 
#define SIZE 5            /*number of employees to be processed*/
#define STD_HOURS 40.0    /*standard work hours*/
#define OT_FACTOR 1.5     /*multiplying factor for overtime pay*/
#define NO_OVERTIME 0.0   /*zero overtime within standard hours*/
#define COL_WIDTH 5.0     /*number of headings in header row*/

int main(int argc, char **argv)
{
	/*initialize employee clock number*/
	long int clockNumber [SIZE]  = {98401, 526488, 765349, 34645, 127615}; 
	int i;                       /*index of each loop or array data*/
	
	/*initialize employee wage rate per hour*/
	float wageRate [SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35};	
	float workHours[SIZE];       /*number of hours worked per week*/
	float grossPay [SIZE];       /*how much the employee is entitled to*/
	float overTime [SIZE];       /*how much overtime hours earned by employee*/
	float sumWage;				 /*wages of all employees*/
	float sumHours;				 /*hours worked by all employees*/
	float sumOverTime;			 /*overtime worked by all employees*/
	float sumGrossPay;			 /*compensation earned by all employees*/
	float avgWage;				 /*average wage*/
	float avgHours;				 /*average hours worked*/
	float avgOverTime;			 /*average overtime*/
	float avgGrossPay;			 /*average gross pay*/
	
	sumWage = 0;                 /*initialize the sum of wages*/
	sumHours = 0;                /*initialize the sum of hours*/
	sumOverTime = 0;             /*initialize the sum of overtime*/
	sumGrossPay = 0;             /*initialize the sum of gross pay */

/* Process each employee one at a time */
	for (i = 0; i < SIZE; ++i)
	{
		/*promt user for input*/
		printf ("Enter hours worked by %06li: \n", clockNumber[i]);
		
		scanf ("%f", &workHours[i]);
		
		sumHours += workHours[i]; /*running total hours*/
		
		sumWage += wageRate[i]; /*running total wages*/
		
		if (workHours[i] > STD_HOURS)
		{
			/*calculate overtime hours*/
			overTime[i] = workHours[i] - STD_HOURS;
			sumOverTime += overTime[i]; /*running total overtime*/
			/*calculate employee gross pay*/
			grossPay[i] = (STD_HOURS * wageRate[i]) + (overTime[i] * wageRate[i] * OT_FACTOR);
		}
		else
		{
			/*calculate overtime hours*/
			overTime[i] = NO_OVERTIME;
			sumOverTime += overTime[i];
			/*calculate employee gross pay*/
			grossPay[i] = wageRate[i] * workHours[i];
		}
		sumGrossPay += grossPay[i]; /*running total gross pay*/
	}

	avgWage = sumWage/SIZE;         /*claculate average wage*/
	avgHours = sumHours/SIZE;       /*claculate average hours*/
	avgOverTime = sumOverTime/SIZE; /*claculate average overtime*/
	avgGrossPay = sumGrossPay/SIZE; /*claculate average pay*/

	printf ("Clock# \tWages \tHours \tOvTime \tGross\n"); /*display table headers*/
	printf ("------ \t------ \t------ \t------ \t------ \n"); /*format output header*/

/*access each employee and print to screen*/
    for(i = 0; i < SIZE; ++i) /*for each row*/
    {
		printf ("\n");
		printf ("%06li ", clockNumber[i]); /*print employee ID for index i*/
		
		printf ("\t%6.2f ", wageRate[i]);  /*print hourly wage for index i*/
		
		printf ("\t%6.2f ", workHours[i]); /*print hours worked for index i*/
		
		printf ("\t%6.2f ", overTime[i]);  /*print overtime for index i*/
		
		printf ("\t%6.2f ", grossPay[i]);  /*print grosspay for index i*/
		printf ("\n");
    }
	
	printf ("------ \t------ \t------ \t------ \t------ \n"); /*format header*/
	/*print totals*/
	printf ("Tot: \t%6.2f \t%6.1f \t%6.1f \t%7.2f \n", sumWage, sumHours, sumOverTime, sumGrossPay);
	/*print averages*/
	printf ("Avg: \t%6.2f \t%6.1f \t%6.1f \t%7.2f \n", avgWage, avgHours, avgOverTime, avgGrossPay);
	
    return(0); /*success*/
}              /*end main*/