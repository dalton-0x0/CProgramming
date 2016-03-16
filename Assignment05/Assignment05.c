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
void getHours (struct employee employeeData[], int size);      /* function to get input*/
void calcOvertime (struct employee employeeData[], int size);  /* function to calc OT*/
void calcGross (struct employee employeeData[], int size);     /* function to calc gross*/

void printData (struct employee employeeData[], int size);     /* printing function*/
void printSums (struct summations sumData);                    /* printing function*/
void printAvgs (struct averages avgData);                      /* printing function*/

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
	
	struct summations sumData = {0}; /* initialization of structure summations variable */
	
	struct averages avgData = {0};   /* initialization of structure averages variable */
	
	getHours(employeeData, NUM_EMPL);
	calcOvertime(employeeData, NUM_EMPL);
	calcGross(employeeData, NUM_EMPL);
	
	/* Optional Challenge - Calculate Sum and Averages */
	int i;
	
	for (i = 0; i < NUM_EMPL; ++i)
	{
		sumData.sumHours += employeeData[i].hours;    /* running total hours */
		sumData.sumWages += employeeData[i].wageRate; /* running total wages */
		sumData.sumOver += employeeData[i].overtime;  /* running total overtime */
		sumData.sumGross += employeeData[i].gross;    /* running total gross */
	}
	avgData.avgHours = sumData.sumHours/NUM_EMPL;  /* average hours */
	avgData.avgWages = sumData.sumWages/NUM_EMPL;  /* average wages */
	avgData.avgOver = sumData.sumOver/NUM_EMPL;    /* average overtime */
	avgData.avgGross = sumData.sumGross/NUM_EMPL;  /* average gross */
	
	printf ("\n"); /* New line for output */
	printf ("Clock# \tWages \tHours \tOvTime \tGross\n"); /* Display table headings */
	printf ("------ \t------ \t------ \t------ \t------ \n"); /* Format display header */
	printData (employeeData, NUM_EMPL);  /* Prints by reference */
	printf ("------ \t------ \t------ \t------ \t------ \n"); /* Format display header*/
	printSums (sumData); /* Function prints totals */
    printAvgs (avgData); /* Function prints averages */
    
	return (0);          /* end main */
} 

//**************************************************************/ 
// Function: getHours 
// 
// Purpose: Obtains input from user, the number of hours worked 
// per employee and stores the result in an local variable 
// that is passed back to the calling function. 
// 
// Parameters: 
// employeeData[] - array of structure employee 
// size - equals number of employees 
// 
// Returns: Nothing (call by reference)
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
	printf("\n"); 
} 

//**************************************************************/ 
// Function: calcOvertime 
// 
// Purpose: Calculates overtime hours worked per employee 
// 
// Parameters: 
// employeeData[] - array of structure employee 
// size - equals number of employees 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void calcOvertime (struct employee employeeData[], int size) 
{
	int i;                            /* Loop index */
	     
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
	printf("\n");
} 

//**************************************************************/ 
// Function: calcGross
// 
// Purpose: Calculates gross pay for each employee 
// 
// Parameters: 
// employeeData[] - array of structure employee 
// size - equals number of employees 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void calcGross (struct employee employeeData[], int size) 
{ 
	int i;                            /* Loop index */
	     
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
// Function: printData  
// 
// Purpose: Prints out all the employee information in a 
// nice and orderly table format.
// 
// Parameters:
// employeeData[] - array of structure employee 
// size - equals number of employees 
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
// sumData - structure variable of sums
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
// avgData - structure variable of averages
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