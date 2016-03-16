/*----------------------------------------------------*/ 
/* HOMEWORK: Assignment 4                             */ 
/*                                                    */ 
/* NAME:     Dalton Okechukwu                         */ 
/*                                                    */ 
/* CLASS:    C Programming (INFO.90.267)              */ 
/*                                                    */ 
/* DATE:     19-Feb-2016                              */ 
/*                                                    */
/* DESCRIPTION:                                       */
/* This program uses different functions to calculate */ 
/* employees' gross pay. It also calculates the       */
/* average and total: hours worked per week, overtime */ 
/* gross pay and unit wages.                          */
/*----------------------------------------------------*/

#include <stdio.h> 

/* Declare constants */
#define NUM_EMPL 5             /* Number of employees */
#define OVERTIME_RATE 1.5f     /* Overtime factor for pay calculations */
#define STD_WORK_WEEK 40.0f    /* Standard working week hours */
#define NO_OVERTIME 0.0f       /* This implies the employee recorded no overtime */
#define COL_WIDTH 5            /* Number of colums for the printed results */

/* Declare function prototypes */ 
float getHours (long clockNumber);
float calcOvertime (float hours);
float calcGross (float overtime, float hours, float wageRate);
float sumWageRate (float wageRate);
float sumHoursWorked (float hours);
float sumOvertime (float overtime);
float sumGrossPay (float gross);
float avgWageRate (float sumWages);
float avgHoursWorked (float sumHours);
float avgOvertime (float sumOver);
float avgGrossPay (float sumGross);
void printData (long int clockNumber[], float wageRate[], float hours[],
                float overtime[], float gross[], int size);
void printTotals (float sumWages, float sumHours, float sumOver, float sumGross);
void printAvgs (float avgWages, float avgHours, float avgOver, float avgGross);

int main() 
{ 
    long  int clockNumber[NUM_EMPL] = {98401,526488,765349,34645,127615}; /* unique ID */
    float gross[NUM_EMPL];     /* Gross pay */
    float hours[NUM_EMPL];     /* Hours worked in a given week */    
    float overtime[NUM_EMPL];  /* Overtime hours */
    float wageRate[NUM_EMPL] = {10.60,9.75,10.50,12.25,8.35}; /* hourly wage rate */	
	float sumWages;            /* Sum of wages per hour */
	float sumHours;            /* Sum of Hours worked in a given week */
	float sumOver;             /* Sum of overtime hours */
	float sumGross;            /* Sum of gross pay in a given week */
	float avgWages;            /* Average of wage rates */
	float avgHours;            /* Average hours worked */
	float avgOver;             /* Average overtime hours worked */
	float avgGross;	           /* Average gross pay for the week */
	int   i;                   /* Loop and array index */

    for (i = 0; i < NUM_EMPL; ++i)
    {
        hours[i] = getHours (clockNumber[i]); /* Calls user's input */        
		overtime[i] = calcOvertime (hours[i]); /* Calculates overtime */         
        gross[i] = calcGross (overtime[i], hours[i], wageRate[i]); /* calculates gross */ 
		sumWages = sumWageRate (wageRate[i]); /* Sums all wages */ 
		sumHours = sumHoursWorked (hours[i]); /* Sums all hours */ 
		sumOver = sumOvertime (overtime[i]); /* Sums overtime */ 
		sumGross = sumGrossPay (gross[i]); /* Sums gross pay*/ 
    }
	avgWages = avgWageRate (sumWages); /* Calculates avg wage */ 
    avgHours = avgHoursWorked (sumHours); /* Calculates avg hours */ 
    avgOver = avgOvertime (sumOver); /* Calculates avg overtime */ 
    avgGross = avgGrossPay (sumGross); /* Calculates avg gross */ 
    
	printf ("\n"); /* New line for output */
	printf ("Clock# \tWages \tHours \tOvTime \tGross\n"); /* Display table headings */
	printf ("------ \t------ \t------ \t------ \t------ \n"); /* Format display header */
    printData (clockNumber, wageRate, hours, overtime, gross, NUM_EMPL);  /* Prints by reference */
	printf ("------ \t------ \t------ \t------ \t------ \n"); /* Format display header*/
	printTotals (sumWages, sumHours, sumOver, sumGross); /* Function prints totals */
    printAvgs (avgWages, avgHours, avgOver, avgGross); /* Function prints averages */
	
    return (0); 
} 

//**************************************************************/ 
// Function: getHours 
// 
// Purpose: Obtains input from user, the number of hours worked 
// per employee and stores the result in an local variable 
// that is passed back to the calling function. 
// 
// Parameters: clockNumber - Employee clock number
// 
// Returns: hoursWorked - hours worked by the employee
//  
//**************************************************************/ 
float getHours (long int clockNumber) 
{ 

    float hoursWorked; /* hours worked in a given week */ 

    /* Get Hours for each employee */ 
    printf("\nEnter hours worked by emp # %06li: ", clockNumber); 
    scanf ("%f", &hoursWorked); 

    return (hoursWorked); 
} 

//**************************************************************/ 
// Function: calcOvertime 
// 
// Purpose: Calculates overtime hours worked per employee 
// 
// Parameters: hours - No. of hours worked per week per employee
// 
// Returns: overtime - Overtime hours for employee's compensation
//  
//**************************************************************/ 
float calcOvertime (float hours) 
{ 

    float overtime; /* Overtime hours per week */ 

    /* Check if hours worked are more than standard hours */ 
    if (hours > STD_WORK_WEEK)
		overtime = hours - STD_WORK_WEEK;
		
	else
		overtime = NO_OVERTIME;

    return (overtime); 
} 

//**************************************************************/ 
// Function: calcGross
// 
// Purpose: Calculates gross pay for each employee 
// 
// Parameters: 
// overtime - Hours outside normal work time
// hours - No. of hours worked per week per employee
// wageRate - unit pay per hour
// 
// Returns: gross - employee's gross pay
//  
//**************************************************************/ 

float calcGross (float overtime, float hours, float wageRate) 
{ 
	float gross; /* Gross pay per employee */
	if (overtime == 0)
		gross = wageRate * hours;
		
	else
		gross = (wageRate * STD_WORK_WEEK) + (wageRate * overtime * OVERTIME_RATE);
	
    return (gross); 
}

//**************************************************************/ 
// Function: sumWageRate
// 
// Purpose: Adds up all unit rates for wages 
// 
// Parameters: wageRate - unit pay per hour
// 
// Returns: sumWages - sum of all the unit wages
//  
//**************************************************************/ 
float sumWageRate (float wageRate) 
{
	static float sumWages;
	sumWages += wageRate;
	return (sumWages);
}

//**************************************************************/ 
// Function: sumHoursWorked  
// 
// Purpose: Adds up normal working hours for each employee
// 
// Parameters: hours - each employee's hours worked per week
//
// Returns: sumHours - sum of all the hours worked
//**************************************************************/ 
float sumHoursWorked (float hours) 
{
	static float sumHours;
	sumHours += hours;
	return (sumHours);
}

//**************************************************************/ 
// Function: sumOvertime 
// 
// Purpose: Adds up overtime hours for each employee
// 
// Parameters: overtime - the calculated overtime hours
//
// Returns: sumOver - sum of the overtime hours
//**************************************************************/ 
float sumOvertime (float overtime) 
{
	static float sumOver;
	sumOver += overtime;
	return (sumOver);
}

//**************************************************************/ 
// Function: sumGrossPay  
// 
// Purpose: Adds up gross pay for each employee
// 
// Parameters: gross - the employee's calculated gross
//
// Returns: sumGross - sum of the gross pay
//**************************************************************/ 
float sumGrossPay (float gross) 
{
	static float sumGross;
	sumGross += gross;
	return (sumGross);
}

//**************************************************************/ 
// Function: avgWageRate  
// 
// Purpose: Calculates the average wage rates being paid
// 
// Parameters: sumWages - the sum of all the unit rates
//
// Returns: avgWages - average wages
//**************************************************************/ 
float avgWageRate (float sumWages) 
{
	static float avgWages;
	avgWages = sumWages/NUM_EMPL;
	return (avgWages);
}

//**************************************************************/ 
// Function: avgHoursWorked  
// 
// Purpose: Calculates the average standard hours worked
// 
// Parameters: sumHours - the total hours worked
//
// Returns: avgHours - average hours
//**************************************************************/  
float avgHoursWorked (float sumHours) 
{
	static float avgHours;
	avgHours = sumHours/NUM_EMPL;
	return (avgHours);
}

//**************************************************************/ 
// Function: avgOvertime  
// 
// Purpose: Calculates the average hours worked during overtime
// 
// Parameters: sumOver - the total overtime hours
//
// Returns: avgOver - average overtime
//**************************************************************/ 
float avgOvertime (float sumOver) 
{
	static float avgOver;
	avgOver = sumOver/NUM_EMPL;
	return (avgOver);
}

//**************************************************************/ 
// Function: avgGrossPay  
// 
// Purpose: Calculates the average pay earned for the week
// 
// Parameters: sumGross - the total compensation paid
//
// Returns: avgGross  average gross pay due each employee
//**************************************************************/ 
float avgGrossPay (float sumGross) 
{
	static float avgGross;
	avgGross = sumGross/NUM_EMPL;
	return (avgGross);
}

//**************************************************************/ 
// Function: printData  
// 
// Purpose: Prints out all the employee information in a 
// nice and orderly table format.
// 
// Parameters: 
//
// clockNumber - Array of employee clock numbers
// wageRate - Array of employee wages per hour
// hrs - Array of number of hours worked by an employee
// overtime - Array of overtime hours for each employee
// gross - Array of gross pay calculations for each employee
// size - Number of employees to process  
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void printData (long int clockNumber[], float wageRate[], float hours[],
                float overtime[], float gross[], int size)
{ 
	int i;
	
    for(i = 0; i < NUM_EMPL; ++i) /*for each row*/
    {		
		printf ("\n");
		printf ("%06li ", clockNumber[i]); /*print employee ID for index i*/
		
		printf ("\t%6.2f ", wageRate[i]);  /*print hourly wage for index i*/
		
		printf ("\t%6.2f ", hours[i]); /*print hours worked for index i*/
		
		printf ("\t%6.2f ", overtime[i]);  /*print overtime for index i*/
		
		printf ("\t%6.2f ", gross[i]);  /*print grosspay for index i*/
		printf ("\n");
    }
} 

//**************************************************************/ 
// Function: printTotals
// 
// Purpose: Prints out sum of wages, hours worked, gross pay 
// earned and overtime worked
//
// Parameters: 
// sumWages - total weekly wages of employees
// sumHours - total hours worked for the week
// sumOver - total overtime worked during the week
// sumGross - total money earned per employee
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void printTotals (float sumWages, float sumHours, float sumOver, float sumGross)
{
	/* Print totals */
	printf ("Tot: \t%6.2f \t%6.1f \t%6.1f \t%7.2f \n", sumWages, sumHours, sumOver, sumGross);
	
}

//**************************************************************/ 
// Function: printAvgs 
// 
// Purpose: Prints out average wages, hours worked, gross pay 
// earned and overtime worked
//
// Parameters: 
// avgWages - average weekly wages of employees
// avgHours - average hours worked for the week
// avgOver - average overtime worked during the week
// avgGross - average money earned per employee
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void printAvgs (float avgWages, float avgHours, float avgOver, float avgGross)
{
	/* Print averages*/
	printf ("Avg: \t%6.2f \t%6.1f \t%6.1f \t%7.2f \n", avgWages, avgHours, avgOver, avgGross);
}