#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*----------------------------------------------------*/ 
/* HOMEWORK: Assignment 6                             */ 
/*                                                    */ 
/* NAME:     Dalton Okechukwu                         */ 
/*                                                    */ 
/* CLASS:    C Programming (INFO.90.267)              */ 
/*                                                    */ 
/* DATE:     07-Mar-2016                              */ 
/*                                                    */
/* DESCRIPTION:                                       */
/* This program uses different functions to calculate */ 
/* employees' gross pay using an array of structures. */
/* It also calculates the average and total: hours    */ 
/* worked per week, overtime, gross pay and wages.    */
/*----------------------------------------------------*/

/* Define constants */
#define NUM_EMPL 5             /* Number of employees */
#define OVERTIME_RATE 1.5f     /* Overtime factor for pay calculations */
#define STD_WORK_WEEK 40.0f    /* Standard working week hours */
#define NO_OVERTIME 0.0f       /* This implies the employee recorded no overtime */
#define COL_WIDTH 5            /* Number of colums for the printed results */


/* Define global structures */
struct employee
{
	char name [20];          /* Employee full name */
	long  int clockNumber;   /* Employee unique ID */
	float wageRate;          /* Hourly wage rate */
	float hours;             /* Hours worked in a given week */
	float overtime;          /* Overtime hours */
	float gross;             /* Gross pay */
};

struct empStats
{
	float sumWages;          /* Sum of wages per hour */
	float sumHours;          /* Sum of Hours worked in a given week */
	float sumOver;           /* Sum of overtime hours in a week*/
	float sumGross;          /* Sum of gross pay in a given week */

	float avgWages;          /* Average employee wages*/
	float avgHours;          /* Average hours worked */
	float avgOver;           /* Average overtime hours worked */
	float avgGross;          /* Average gross pay for the week */

	float minWages;          /* Minimum employee wages*/
	float minHours;          /* Minimum hours worked */
	float minOver;           /* Minimum overtime hours worked */
	float minGross;          /* Minimum gross pay for the week */
	
	float maxWages;          /* Maximum employee wages*/
	float maxHours;          /* Maximum hours worked */
	float maxOver;           /* Maximum overtime hours worked */
	float maxGross;          /* Maximum gross pay for the week */
};

/* Declare function prototypes */ 
void getHours (struct employee employeeData[], int size);      /* function to get input*/
void calcOvertime (struct employee employeeData[], int size);  /* function to calc OT*/
void calcGross (struct employee employeeData[], int size);     /* function to calc gross*/
void printData (struct employee employeeData[], int size);     /* printing function*/
void calcSumsAvgs (struct employee employeeData[], int size);  /* function to calc total & avg */
void calcMinsMaxs (struct employee employeeData[], int size);  /* function to calc min & max */

int main() 
{ 
    /* Local structure variable declaration and initialization */
	struct employee employeeData[NUM_EMPL] = {
		{"Connie Cobol", 98401, 10.60},
		{"Mary Apl", 526488, 9.75},
		{"Frank Fortran", 765349, 10.50},
		{"Jeff Ada", 34645, 12.25},
		{"Anton Pascal", 127615, 10.00},
	};
	
	getHours(employeeData, NUM_EMPL);
	calcOvertime(employeeData, NUM_EMPL);
	calcGross(employeeData, NUM_EMPL);
	
	printf ("------------------------------------------------------- \n"); /* Format display header */
	printf ("Name \t \tClock# \t Wages \t Hours \t OTime \t Gross\n"); /* Display table headings */
	printf ("------------------------------------------------------- \n"); /* Format display header */
	printData (employeeData, NUM_EMPL);  /* Prints employee data by reference */
	printf ("------------------------------------------------------- \n"); /* Format display header*/
	calcSumsAvgs (employeeData, NUM_EMPL); /* Function calcs and prints totals & averages */
    calcMinsMaxs (employeeData, NUM_EMPL); /* Function calcs and prints min & max values */
	return (0);
} /* end main */

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
} /* end function */

//**************************************************************/ 
// Function: calcOvertime 
// 
// Purpose: Calculates overtime hours worked per employee.
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
} /* end function */

//**************************************************************/ 
// Function: calcGross
// 
// Purpose: Calculates gross pay for each employee.
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
	     
	for (i = 0; i < size; ++i)        /* Get Hours for each employee */
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
} /* end function */

//**************************************************************/ 
// Function: printData  
// 
// Purpose: Prints out employee primary data.
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
	int i;                    /* Loop index */
	
    for(i = 0; i < size; ++i) /*for each row*/
    {
		printf ("%s ", employeeData[i].name); /*print employee name for index i*/
		printf ("\t%06li ", employeeData[i].clockNumber); /*print employee ID for index i*/
		printf ("\t%6.2f ", employeeData[i].wageRate);  /*print hourly wage for index i*/
		printf ("\t%6.1f ", employeeData[i].hours); /*print hours worked for index i*/
		printf ("\t%6.1f ", employeeData[i].overtime);  /*print overtime for index i*/
		printf ("\t%7.2f \n", employeeData[i].gross);  /*print grosspay for index i*/
    }
} /* end function */

//**************************************************************/ 
// Function: calcSumAvgs
// 
// Purpose: Computes and prints out sum and averages of wages,   
// hours worked, gross pay earned and overtime worked.
//
// Parameters: 
// employeeData[] - array of structure employee 
// size - equals number of employees 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void calcSumsAvgs (struct employee employeeData[], int size)
{
	struct empStats sumData = {0, 0, 0, 0}; /* initialization of sumData variable */
	struct empStats avgData = {0, 0, 0, 0}; /* initialization of avgData variable */
	int i;                    /* Loop index */
	
	for (i = 0; i < size; ++i)
	{
		sumData.sumHours += employeeData[i].hours;    /* running total hours */
		sumData.sumWages += employeeData[i].wageRate; /* running total wages */
		sumData.sumOver += employeeData[i].overtime;  /* running total overtime */
		sumData.sumGross += employeeData[i].gross;    /* running total gross */
	}
	avgData.avgHours = sumData.sumHours/size;  /* average hours */
	avgData.avgWages = sumData.sumWages/size;  /* average wages */
	avgData.avgOver = sumData.sumOver/size;    /* average overtime */
	avgData.avgGross = sumData.sumGross/size;  /* average gross */
	
	/* Print totals */
	printf ("Total: \t \t \t%6.2f \t%6.1f \t%6.1f \t%7.2f \n", 
	sumData.sumWages, sumData.sumHours, sumData.sumOver, sumData.sumGross);
	printf ("Average: \t \t%6.2f \t%6.1f \t%6.1f \t%7.2f \n", 
	avgData.avgWages, avgData.avgHours, avgData.avgOver, avgData.avgGross);
} /* end function */

//**************************************************************/ 
// Function: calcMinsMaxs 
// 
// Purpose: Computes and prints out minimum and maximum wage,   
// hours worked, gross pay earned and overtime worked.
//
// Parameters: 
// employeeData[] - array of structure employee 
// size - equals number of employees 
//
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void calcMinsMaxs (struct employee employeeData[], int size)
{
	struct empStats minData = {0, 0, 0, 0}; /* initialization of minData variable */
	struct empStats maxData = {0, 0, 0, 0}; /* initialization of maxData variable */
	float minTheWages = employeeData[0].wageRate;    /* local variable to hold min wage */
	float minTheHours = employeeData[0].hours;       /* local variable to hold min hour */
	float minTheOvertime = employeeData[0].overtime; /* local variable to hold min overtime */
	float minTheGross = employeeData[0].gross;       /* local variable to hold min  gross pay*/
	int i;                                           /* Loop index */
	for (i = 0; i < size; ++i)
	{
		if (employeeData[i].wageRate < minTheWages)  /* check if less than min */
		{
			minTheWages = employeeData[i].wageRate;  /* update */
		}
			if (employeeData[i].hours < minTheHours) /* check if less than min */
			{
				minTheHours = employeeData[i].hours; /* update */
			}
				if (employeeData[i].overtime < minTheOvertime) /* check if less than min */
				{
					minTheOvertime = employeeData[i].overtime; /* update */
				}
					if (employeeData[i].gross < minTheGross)   /* check if less than min */
					{
						minTheGross = employeeData[i].gross;   /* update */
					}
	}
	float maxTheWages = 0;
	float maxTheHours = 0;
	float maxTheOvertime = 0;
	float maxTheGross = 0;
	for (i = 0; i < size; ++i)
	{
		if (employeeData[i].wageRate > maxTheWages)   /* check if less than max */
		{
			maxTheWages = employeeData[i].wageRate;   /* update */
		}
			if (employeeData[i].hours > maxTheHours)  /* check if less than max */
			{
				maxTheHours = employeeData[i].hours;  /* update */
			}
				if (employeeData[i].overtime > maxTheOvertime)  /* check if less than max */
				{
					maxTheOvertime = employeeData[i].overtime;  /* update */
				}
					if (employeeData[i].gross > maxTheGross)    /* check if less than max */
					{
						maxTheGross = employeeData[i].gross;    /* update */
					}
	}
	/* re-assign variables for readability */
	minData.minWages = minTheWages;          /* Minimum employee wages*/
	minData.minHours = minTheHours;          /* Minimum hours worked */
	minData.minOver = minTheOvertime;        /* Minimum overtime hours worked */
	minData.minGross = minTheGross;          /* Minimum gross pay for the week */
	
	maxData.maxWages = maxTheWages;          /* Maximum employee wages*/
	maxData.maxHours = maxTheHours;          /* Maximum hours worked */
	maxData.maxOver = maxTheOvertime;        /* Maximum overtime hours worked */
	maxData.maxGross = maxTheGross;          /* Maximum gross pay for the week */
	/* Print minimums */
	printf ("Minimum: \t \t%6.2f \t%6.1f \t%6.1f \t%7.2f \n", 
	minData.minWages, minData.minHours, minData.minOver, minData.minGross);
	/* Print maximums */
	printf ("Maximum: \t \t%6.2f \t%6.1f \t%6.1f \t%7.2f \n", 
	maxData.maxWages, maxData.maxHours, maxData.maxOver, maxData.maxGross);
} /* end function */