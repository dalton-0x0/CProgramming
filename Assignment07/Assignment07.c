#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*----------------------------------------------------*/ 
/* HOMEWORK: Assignment 7                             */ 
/*                                                    */ 
/* NAME:     Dalton Okechukwu                         */ 
/*                                                    */ 
/* CLASS:    C Programming (INFO.90.267)              */ 
/*                                                    */ 
/* DATE:     14-Mar-2016                              */ 
/*                                                    */
/* DESCRIPTION:                                       */
/* This program uses different functions to calculate */ 
/* employees' gross pay using pointers to an array of */
/* structures. It also calculates the average and     */ 
/* total: hours worked per week, overtime, gross pay  */
/* and wages.                                         */
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
/* function to get input*/
void getHours (struct employee *employeeDataPointer, int size);
/* function to calc overtime */      
void calcOvertime (struct employee *employeeDataPointer, int size);
/* function to calc gross*/
void calcGross (struct employee *employeeDataPointer, int size);
/* printing function*/
void printData (struct employee *employeeDataPointer, int size);
/* function to calculate totals and averages */
void calcSumsAvgs (struct employee *employeeDataPointer, int size);
/* function to calculate minimum values */
void calcMins (struct employee *employeeDataPointer, int size);
/* function to calculate maximum values */
void calcMaxs (struct employee *employeeDataPointer, int size);

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
	
	struct employee *employeeDataPointer;
	employeeDataPointer = employeeData;
	
	getHours(employeeDataPointer, NUM_EMPL);
	calcOvertime(employeeDataPointer, NUM_EMPL);
	calcGross(employeeDataPointer, NUM_EMPL);
	/* Format display header */
	printf ("------------------------------------------------------- \n");
	/* Display table headings */
	printf ("%-15s %s \t%s \t%s \t%s \t%s \n", 
	"Name", "Clock#", "Wages", "Hours", "OTime", "Gross");
	/* Format display header */
	printf ("------------------------------------------------------- \n");
	/* Prints employee data by reference */
	printData (employeeDataPointer, NUM_EMPL);
	/* Format display header*/
	printf ("------------------------------------------------------- \n");
	/* Function calcs and prints totals & averages */
	calcSumsAvgs (employeeDataPointer, NUM_EMPL);
	/* Function calcs and prints min values */
	calcMins (employeeDataPointer, NUM_EMPL); 
	/* Function calcs and prints max values */
	calcMaxs (employeeDataPointer, NUM_EMPL); 
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
// employeeDataPointer - pointer to array of structure employee 
// size - equals number of employees 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void getHours (struct employee *employeeDataPointer, int size) 
{
    int i;                       /* Loop index */
	//int size = 5;
     
	for (i = 0; i < size; ++i)   /* Get Hours for each employee */
	{
		printf("\nEnter hours worked by emp # %06li: ", employeeDataPointer -> clockNumber); 
		scanf ("%f", &employeeDataPointer->hours);
		++employeeDataPointer;
	}
} /* end function */

//**************************************************************/ 
// Function: calcOvertime 
// 
// Purpose: Calculates overtime hours worked per employee.
// 
// Parameters: 
// employeeDataPointer - pointer to array of structure employee 
// size - equals number of employees 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void calcOvertime (struct employee *employeeDataPointer, int size) 
{
	int i;                            /* Loop index */
	     
	for (i = 0; i < size; ++i)    /* Get Hours for each employee */
	{
		/* Check if hours worked are more than standard hours */
		if ((employeeDataPointer->hours) > STD_WORK_WEEK)
		{
			(employeeDataPointer->overtime) = (employeeDataPointer->hours) - STD_WORK_WEEK;
		}
		
		else
		{
			(employeeDataPointer->overtime) = NO_OVERTIME;
		}
		++employeeDataPointer;
	}
	printf("\n");
} /* end function */

//**************************************************************/ 
// Function: calcGross
// 
// Purpose: Calculates gross pay for each employee.
// 
// Parameters: 
// employeeDataPointer - pointer to array of structure employee  
// size - equals number of employees 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void calcGross (struct employee *employeeDataPointer, int size) 
{ 
	int i;                            /* Loop index */
	     
	for (i = 0; i < size; ++i)        /* Get Hours for each employee */
	{
	/* Check if hours worked are more than standard hours */
		if ((employeeDataPointer->overtime) == 0)
		{
			(employeeDataPointer->gross) = 
			(employeeDataPointer->wageRate) * (employeeDataPointer->hours);
		}		
		else
		{
			employeeDataPointer->gross = 
			(employeeDataPointer->wageRate * STD_WORK_WEEK) 
			+ (employeeDataPointer->wageRate * employeeDataPointer->overtime * OVERTIME_RATE);
		}
		++employeeDataPointer;
	}
	printf("\n");
} /* end function */

//**************************************************************/ 
// Function: printData  
// 
// Purpose: Prints out employee primary data.
// 
// Parameters:
// employeeDataPointer - pointer to array of structure employee 
// size - equals number of employees 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void printData (struct employee *employeeDataPointer, int size)
{ 
	int i;                    /* Loop index */
	
    for(i = 0; i < size; ++i) /*for each row*/
    {
		printf ("%-15s %06li \t%5.2f \t%5.1f \t%4.1f \t%7.2f \n", 
		employeeDataPointer -> name,         /*print employee name for pointer address*/
		employeeDataPointer -> clockNumber,  /*print employee ID for pointer address*/
		employeeDataPointer -> wageRate,     /*print hourly wage for pointer address*/
		employeeDataPointer -> hours,        /*print hours worked for pointer address*/
		employeeDataPointer -> overtime,     /*print overtime for pointer address*/
		employeeDataPointer -> gross);       /*print gross pay for pointer address*/
		++employeeDataPointer;               /*move to next employee */
    };
} /* end function */

//**************************************************************/ 
// Function: calcSumAvgs
// 
// Purpose: Computes and prints out sum and averages of wages,   
// hours worked, gross pay earned and overtime worked.
//
// Parameters: 
// employeeDataPointer - pointer to array of structure employee 
// size - equals number of employees 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void calcSumsAvgs (struct employee *employeeDataPointer, int size)
{
	struct empStats sumData = {0, 0, 0, 0}; /* initialization of sumData variable */
	struct empStats avgData = {0, 0, 0, 0}; /* initialization of avgData variable */
	
	struct empStats *sumDataPointer;
	sumDataPointer = &sumData;
	struct empStats *avgDataPointer;
	avgDataPointer = &avgData;
	
	int i;                    /* Loop index */
	
	for (i = 0; i < size; ++i)
	{
		/* running total hours */
		sumDataPointer->sumHours += employeeDataPointer->hours; 
		/* running total wages */
		sumDataPointer->sumWages += employeeDataPointer->wageRate;
		/* running total overtime */
		sumDataPointer->sumOver += employeeDataPointer->overtime;
		/* running total gross */
		sumDataPointer->sumGross += employeeDataPointer->gross;
		++employeeDataPointer;
	}
	avgDataPointer->avgHours = sumDataPointer->sumHours/size;  /* average hours */
	avgDataPointer->avgWages = sumDataPointer->sumWages/size;  /* average wages */
	avgDataPointer->avgOver = sumDataPointer->sumOver/size;    /* average overtime */
	avgDataPointer->avgGross = sumDataPointer->sumGross/size;  /* average gross */
	
	/* Print totals */
	printf ("%-15s \t%5.2f \t%5.1f \t%4.1f \t%7.2f \n", 
	"Total:",
	sumDataPointer->sumWages, 
	sumDataPointer->sumHours, 
	sumDataPointer->sumOver, 
	sumDataPointer->sumGross);
	printf ("%-15s \t%5.2f \t%5.1f \t%4.1f \t%7.2f \n", 
	"Average:",
	avgDataPointer->avgWages, 
	avgDataPointer->avgHours, 
	avgDataPointer->avgOver, 
	avgDataPointer->avgGross);
} /* end function */

//**************************************************************/ 
// Function: calcMins
// 
// Purpose: Computes and prints out minimum wage,   
// hours worked, gross pay earned and overtime worked.
//
// Parameters: 
// employeeDataPointer - pointer to array of structure employee  
// size - equals number of employees 
//
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void calcMins (struct employee *employeeDataPointer, int size)
{
	struct empStats minData = {0, 0, 0, 0}; /* initialization of minData variable */
	struct empStats *minDataPointer;
	minDataPointer = &minData;
	
	float minTheWages = employeeDataPointer->wageRate;    /* local variable to hold min wage */
	float minTheHours = employeeDataPointer->hours;       /* local variable to hold min hour */
	float minTheOvertime = employeeDataPointer->overtime; /* local variable to hold min overtime */
	float minTheGross = employeeDataPointer->gross;       /* local variable to hold min  gross pay*/
	int i;                                           /* Loop index */
	for (i = 0; i < size; ++i)
	{
		if (employeeDataPointer->wageRate < minTheWages)  /* check if less than min */
		{
			minTheWages = employeeDataPointer->wageRate;  /* update */
		}
			if (employeeDataPointer->hours < minTheHours) /* check if less than min */
			{
				minTheHours = employeeDataPointer->hours; /* update */
			}
				if (employeeDataPointer->overtime < minTheOvertime) /* check if less than min */
				{
					minTheOvertime = employeeDataPointer->overtime; /* update */
				}
					if (employeeDataPointer->gross < minTheGross)   /* check if less than min */
					{
						minTheGross = employeeDataPointer->gross;   /* update */
					}
	++employeeDataPointer;
	}
	/* re-assign variables for readability */
	minDataPointer->minWages = minTheWages;          /* Minimum employee wages*/
	minDataPointer->minHours = minTheHours;          /* Minimum hours worked */
	minDataPointer->minOver = minTheOvertime;        /* Minimum overtime hours worked */
	minDataPointer->minGross = minTheGross;          /* Minimum gross pay for the week */
	
	/* Print minimums */
	printf ("%-15s \t%5.2f \t%5.1f \t%4.1f \t%7.2f \n", 
	"Minimum:",
	minDataPointer->minWages, 
	minDataPointer->minHours, 
	minDataPointer->minOver, 
	minDataPointer->minGross);
} /* end function */

//**************************************************************/ 
// Function: calcMaxs 
// 
// Purpose: Computes and prints out maximum wage,   
// hours worked, gross pay earned and overtime worked.
//
// Parameters: 
// employeeDataPointer - pointer to array of structure employee  
// size - equals number of employees 
//
// Returns: Nothing (call by reference)
//  
//**************************************************************/
void calcMaxs (struct employee *employeeDataPointer, int size)
{
	/* Compute maximums */
	struct empStats maxData = {0, 0, 0, 0}; /* initialization of maxData variable */
	struct empStats *maxDataPointer;
	maxDataPointer = &maxData;
	
	float maxTheWages = employeeDataPointer->wageRate;
	float maxTheHours = employeeDataPointer->hours;
	float maxTheOvertime = employeeDataPointer->overtime;
	float maxTheGross = employeeDataPointer->gross;
	int i;
	for (i = 0; i < size; ++i)
	{
		if (employeeDataPointer->wageRate > maxTheWages)   /* check if greater than max */
		{
			maxTheWages = employeeDataPointer->wageRate;   /* update */
		}
			if (employeeDataPointer->hours > maxTheHours)  /* check if greater than max */
			{
				maxTheHours = employeeDataPointer->hours;  /* update */
			}
				if (employeeDataPointer->overtime > maxTheOvertime)  /* check if greater than max */
				{
					maxTheOvertime = employeeDataPointer->overtime;  /* update */
				}
					if (employeeDataPointer->gross > maxTheGross)    /* check if greater than max */
					{
						maxTheGross = employeeDataPointer->gross;    /* update */
					}
	++employeeDataPointer;
	}
	maxDataPointer->maxWages = maxTheWages;          /* Maximum employee wages*/
	maxDataPointer->maxHours = maxTheHours;          /* Maximum hours worked */
	maxDataPointer->maxOver = maxTheOvertime;        /* Maximum overtime hours worked */
	maxDataPointer->maxGross = maxTheGross;          /* Maximum gross pay for the week */
	
	/* Print maximums */
	printf ("%-15s \t%5.2f \t%5.1f \t%4.1f \t%7.2f \n", 
	"Maximum:",
	maxDataPointer->maxWages, 
	maxDataPointer->maxHours,
	maxDataPointer->maxOver, 
	maxDataPointer->maxGross);
}