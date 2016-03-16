/*----------------------------------------------------*/ 
/* HOMEWORK: Assignment 5                             */ 
/*                                                    */ 
/* NAME:     Dalton Okechukwu                         */ 
/*                                                    */ 
/* CLASS:    C Programming (INFO.90.267)              */ 
/*                                                    */ 
/* DATE:     26-Feb-2016                              */ 
/*                                                    */
/* DESCRIPTION:                                       */
/* This program uses different functions to calculate */ 
/* employees' gross pay using an array of structures. */
/* It also calculates the average and total: hours    */ 
/* worked per week, overtime, gross pay and wages.    */
/*----------------------------------------------------*/

#include <stdio.h> 

/* Define constants */
#define NUM_EMPL 5             /* Number of employees */
#define OVERTIME_RATE 1.5f     /* Overtime factor for pay calculations */
#define STD_WORK_WEEK 40.0f    /* Standard working week hours */
#define NO_OVERTIME 0.0f       /* This implies the employee recorded no overtime */
#define COL_WIDTH 5            /* Number of colums for the printed results */


/* Define global structures */
struct employee
{
	long  int clockNumber;   /* Employee unique ID */
	float wageRate;          /* Hourly wage rate */
	float hours;             /* Hours worked in a given week */
	float overtime;          /* Overtime hours */
	float gross;             /* Gross pay */
};

struct summations
{
	float sumWages;          /* Sum of wages per hour */
	float sumHours;          /* Sum of Hours worked in a given week */
	float sumOver;           /* Sum of overtime hours in a week*/
	float sumGross;          /* Sum of gross pay in a given week */
};

struct averages
{
	float avgWages;          /* Average employee wages*/
	float avgHours;          /* Average hours worked */
	float avgOver;           /* Average overtime hours worked */
	float avgGross;          /* Average gross pay for the week */
};

/* Declare function prototypes */ 
void getHours (struct employee employeeData[], int size);
void calcOvertime (struct employee employeeData[], int size);
void calcGross (struct employee employeeData[], int size);
void calcSum (struct employee employeeData[], int size);
void calcAvg (struct summations sumData);

void printData (struct employee employeeData[], int size);
void printSums (struct summations sumData);
void printAvgs (struct averages avgData);

int main() 
{ 
    /* Local structure variable declaration and initialization */
	struct employee employeeData[NUM_EMPL] = {
		{98401, 10.60},
		{526488, 9.75},
		{765349, 10.50},
		{34645, 12.25},
		{127615, 8.35},
	};
	
	struct summations sumData; /* local variable */
	
	struct averages avgData;   /* local variable */
	
	getHours(employeeData, NUM_EMPL);
	calcOvertime(employeeData, NUM_EMPL);
	calcGross(employeeData, NUM_EMPL);
	int i;
	for (i = 0; i < NUM_EMPL; ++i)
	{
		sumData.sumHours += employeeData[i].hours;
		avgData.avgHours = sumData.sumHours/NUM_EMPL;
		
		sumData.sumWages += employeeData[i].wageRate;
		avgData.avgWages = sumData.sumWages/NUM_EMPL;
		
		sumData.sumOver += employeeData[i].overtime;
		avgData.avgOver = sumData.sumOver/NUM_EMPL;
		
		sumData.sumGross += employeeData[i].gross;
		avgData.avgGross = sumData.sumGross/NUM_EMPL;
	}
	//calcSum(employeeData, NUM_EMPL);
	//calcAvg(sumData); 
	
	printf ("\n"); /* New line for output */
	printf ("Clock# \tWages \tHours \tOvTime \tGross\n"); /* Display table headings */
	printf ("------ \t------ \t------ \t------ \t------ \n"); /* Format display header */
	printData (employeeData, NUM_EMPL);  /* Prints by reference */
	printf ("------ \t------ \t------ \t------ \t------ \n"); /* Format display header*/
	printSums (sumData); /* Function prints totals */
    printAvgs (avgData); /* Function prints averages */
	
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
void getHours (struct employee employeeData[], int size) 
{
    int i;                            /* Loop index */
	//int size = 5;
     
	for (i = 0; i < size; ++i)    /* Get Hours for each employee */
	{
		printf("\nEnter hours worked by emp # %06li: ", employeeData[i].clockNumber); 
		scanf ("%f", &employeeData[i].hours);
	}
	printf("\n\n"); 
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
void calcOvertime (struct employee employeeData[], int size) 
{
	int i;                            /* Loop index */
	//int size = 5;
     
	for (i = 0; i < size; ++i)    /* Get Hours for each employee */
	{
		/* Check if hours worked are more than standard hours */
		if (employeeData[i].hours > STD_WORK_WEEK)
		{
			employeeData[i].overtime = employeeData[i].hours - STD_WORK_WEEK;
		}
		
		else
		{
			employeeData[i].overtime = NO_OVERTIME;
		}
	}
	printf("\n\n"); 
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

void calcGross (struct employee employeeData[], int size) 
{ 
	int i;                            /* Loop index */
	//int size = 5;
     
	for (i = 0; i < size; ++i)    /* Get Hours for each employee */
	{
	/* Check if hours worked are more than standard hours */
		if (employeeData[i].overtime == 0)
		{
			employeeData[i].gross = employeeData[i].wageRate * employeeData[i].hours;
		}
		
		else
		{
			employeeData[i].gross = (employeeData[i].wageRate * STD_WORK_WEEK) 
			+ (employeeData[i].wageRate * employeeData[i].overtime * OVERTIME_RATE);
		}
	}
	printf("\n");	
}

//**************************************************************/ 
// Function: calcSum
// 
// Purpose: Adds up all unit rates for wages 
// 
// Parameters: wageRate - unit pay per hour
// 
// Returns: sumWages - sum of all the unit wages
//  
//**************************************************************/ 

//void calcSum (struct employee employeeData[], int size) 
//{
	//struct summations sumData; /* local variable */;
	//int i;                            /* Loop index */
	//int size = 5;
	//for (i = 0; i < size; ++i)    /* Get Hours for each employee */
	//{
		//sumData.sumHours += employeeData[i].hours;
		//sumData.sumWages += employeeData[i].wageRate;
		
		//sumData.sumOver += employeeData[i].overtime;
		//sumData.sumGross += employeeData[i].gross;
	//}
//}

//**************************************************************/ 
// Function: calcAvg  
// 
// Purpose: Calculates the average wage rates being paid
// 
// Parameters: sumWages - the sum of all the unit rates
//
// Returns: avgWages - average wages
//**************************************************************/ 
//void calcAvg (struct summations sumData) 
//{
	//struct averages avgData; /* local variable */;

	//avgData.avgWages = sumData.sumWages/NUM_EMPL;
	//avgData.avgHours = sumData.sumHours/NUM_EMPL;
	//avgData.avgOver = sumData.sumOver/NUM_EMPL;
	//avgData.avgGross = sumData.sumGross/NUM_EMPL;	
//}

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
void printData (struct employee employeeData[], int size)
{ 
	int i;
	
	//int size = 5;
	
    for(i = 0; i < size; ++i) /*for each row*/
    {		
		printf ("\n");
		printf ("%06li ", employeeData[i].clockNumber); /*print employee ID for index i*/
		
		printf ("\t%6.2f ", employeeData[i].wageRate);  /*print hourly wage for index i*/
		
		printf ("\t%6.2f ", employeeData[i].hours); /*print hours worked for index i*/
		
		printf ("\t%6.2f ", employeeData[i].overtime);  /*print overtime for index i*/
		
		printf ("\t%6.2f ", employeeData[i].gross);  /*print grosspay for index i*/
		printf ("\n");
    }
} 

//**************************************************************/ 
// Function: printSum
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
void printSums (struct summations sumData)
{
	/* Print totals */
	printf ("Tot: \t%6.2f \t%6.1f \t%6.1f \t%7.2f \n", 
	sumData.sumWages, sumData.sumHours, sumData.sumOver, sumData.sumGross);
	
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
void printAvgs (struct averages avgData)
{
	/* Print averages*/
	printf ("Avg: \t%6.2f \t%6.1f \t%6.1f \t%7.2f \n", 
	avgData.avgWages, avgData.avgHours, avgData.avgOver, avgData.avgGross);
}