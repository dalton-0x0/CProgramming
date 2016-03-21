/*----------------------------------------------------*/ 
/* HOMEWORK: Assignment 8                             */ 
/*                                                    */ 
/* NAME:     Dalton Okechukwu                         */ 
/*                                                    */ 
/* CLASS:    C Programming (INFO.90.267)              */ 
/*                                                    */ 
/* DATE:     19-Mar-2016                              */ 
/*                                                    */
/* DESCRIPTION:                                       */
/* This program uses different functions to calculate */ 
/* employees' gross pay using pointers to an array of */
/* structures. It also calculates the average and     */ 
/* total: hours worked per week, overtime, gross pay  */
/* and wages.                                         */
/*----------------------------------------------------*/

/* Define constants */
#include <stdio.h>
#include <stdlib.h>   /* for malloc */
#include <ctype.h>    /* for toupper */
#include <string.h>
 
#define WEEKLY_HOURS 40.0f  /* total hours before overtime */
#define OT_RATE 1.5f        /* pay multiplier after overtime */

/* Define global structures */
struct employee
{
	char firstName [10];
	char lastName  [10];
	int clockNumber;        /* Employee unique ID */
	float wageRate;         /* Hourly wage rate */
	float hours;            /* Hours worked in a given week */
	float overtime;         /* Overtime hours */
	float gross;            /* Gross pay */
	struct employee *next;
};

/* struct for sums */
struct empSum
{
	float sumWage;
	float sumHours;
	float sumOvertime;
	float sumGross;
	struct empSum *next;
};

/* struct for averages */
struct empAvg
{
	float avgWage;
	float avgHours;
	float avgOvertime;
	float avgGross;
	struct empAvg *next;
};

/* struct for minimums */
struct empMin
{
	float minWage;
	float minHours;
	float minOvertime;
	float minGross;
	struct empMin *next;
};

/* struct for maximums */
struct empMax
{
	float maxWage;
	float maxHours;
	float maxOvertime;
	float maxGross;
	struct empMax *next;
};

/* Declare function prototypes */ 
float calcOvertime(float hours);  /* see function description below */ 
float calcGross(float wageRate, float hours, float overtime); /* see function description below */
void printLinkedLists(struct employee *emp1); /* see function description below */
void calcSumsAvgs(struct employee *emp1); /* see function description below */
void calcMinsMaxs(struct employee *emp1); /* see function description below */

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     calcOvertime                                                  */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the amount of overtime hours     */
/*               accrued weekly.                                               */
/*                                                                             */
/* PARAMETERS:   hours - total hours worked in one week                        */
/*                                                                             */
/* OUTPUTS:      float - hours of overtime worked                              */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
float calcOvertime(float hours)
{
	float overtime;
	if (hours > WEEKLY_HOURS)
	{
		overtime = (hours - WEEKLY_HOURS);
	}
	else
	{
		overtime = 0.0;
	}
	return (overtime);
}
 
/*-----------------------------------------------------------------------------*/
/* FUNCTION:     calcGross                                                     */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the total (gross) pay for each   */
/*               employee based on their previously entered and calculated     */
/*               wageRate, hours and overtime.                                 */
/*                                                                             */
/* PARAMETERS:   wageRate - hourly wageRate                                    */
/*               hours    - hours worked in one week                           */
/*               overtime - hours of overtime worked in one week               */
/*                                                                             */
/* OUTPUTS:      float - gross amount of money earned by employee              */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
float calcGross(float wageRate, float hours, float overtime)
{
	float gross; /* value for return */
	if (overtime == 0.0)
	{
		gross = wageRate * hours;
	}
	else
	{
		gross = (wageRate * WEEKLY_HOURS) + (wageRate * overtime * OT_RATE);
	}
	
	return (gross);
}
 
/*-----------------------------------------------------------------------------*/
/* FUNCTION:     printLinkedLists                                                 */
/*                                                                             */
/* DESCRIPTION:  This function will print the contents of a linked list of     */
/*               employees.  It will traverse the list from beginning to the   */
/*               end, printing the contents at each node.  It will also print  */
/*               a list of compiled stats regarding the employees.             */
/*                                                                             */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list of employees                  */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*-----------------------------------------------------------------------------*/
void printLinkedLists(struct employee *emp1)
{
	struct employee *tempEmp;    /* tmp pointer value to current employee node */
	
	int i = 0;                   /* counts the employee nodes printed          */
		
	char name [20];              /* string to hold full name for each employee */
 
	/* Start a beginning of list and print out each value               */
	/* loop until tempEmp points to null (remember null is 0 or false)  */
	printf("--------------------------------------------------------\n");
	printf ("%-15s %s \t%s \t%s \t%s \t%s \n", 
	"Name", 
	"Clock#", 
	"Wages", 
	"Hours", 
	"OTime", 
	"Gross");
	printf("--------------------------------------------------------\n");
	for(tempEmp = emp1; tempEmp ; tempEmp = tempEmp->next)
	{
		i++;
		strcpy(name, tempEmp -> firstName);
		strcat(name, " ");
		strcat(name, tempEmp -> lastName);
		printf("%-15s %06li \t%5.2f \t%5.1f \t%4.1f \t%7.2f \n", 
		name, 
		tempEmp->clockNumber,
		tempEmp->wageRate, 
		tempEmp->hours, 
		tempEmp->overtime, 
		tempEmp->gross);
	}
	printf("--------------------------------------------------------\n");
}

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     calcSumsAvgs                                                  */
/*                                                                             */
/* DESCRIPTION:  Computes and prints out sum and averages of wages,            */
/*               hours worked, gross pay earned and overtime worked.           */
/*                                                                             */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list of employees                  */
/*               stat1 - pointer to a linked list of stats                     */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*-----------------------------------------------------------------------------*/
void calcSumsAvgs(struct employee *emp1)
{
	struct employee *tempEmp; 
	//struct empSum *tempSum;    /* tmp pointer value to current employee node */
		
	int i = 0;                   /* counts the employee nodes printed          */
		
	//char name [20];              /* string to hold full name for each employee */
 
	/* Start a beginning of list and print out each value               */
	/* loop until tempEmp points to null (remember null is 0 or false)  */
	struct empSum sumData = {0, 0, 0, 0}; /*initialize sumData */
	struct empSum *tempSum;
	tempSum = &sumData;

	for(tempEmp = emp1; tempEmp ; tempEmp = tempEmp->next)
	{
		i++;
		//tempSum->wageRate;
		tempSum->sumWage += tempEmp->wageRate;
		tempSum->sumHours += tempEmp->hours;
		tempSum->sumOvertime += tempEmp->overtime;
		tempSum->sumGross += tempEmp->gross;
	}
	printf("%-15s \t\t%5.2f \t%5.1f \t%4.1f \t%7.2f \n", 
	"Total: ", 
	tempSum->sumWage,
	tempSum->sumHours,
	tempSum->sumOvertime,
	tempSum->sumGross);
	
	struct empAvg avgData = {0, 0, 0, 0}; /*initialize avgData */
	struct empAvg *tempAvg;
	tempAvg = &avgData;
	
	tempAvg->avgWage = tempSum->sumWage/i;
	tempAvg->avgHours = tempSum->sumHours/i;
	tempAvg->avgOvertime = tempSum->sumOvertime/i;
	tempAvg->avgGross = tempSum->sumGross/i;
	
	printf("%-15s \t\t%5.2f \t%5.1f \t%4.1f \t%7.2f \n", 
	"Average: ", 
	tempAvg->avgWage,
	tempAvg->avgHours,
	tempAvg->avgOvertime,
	tempAvg->avgGross);
	printf("--------------------------------------------------------\n");
	//printf("Total Number of Employees = %i\n", i);
}

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     calcMinsMaxs                                                  */
/*                                                                             */
/* DESCRIPTION:  This function will print the minimum and maximum wage,        */
/*               hours, overtime and gross pay.                                */
/*                                                                             */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list of employees                  */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*-----------------------------------------------------------------------------*/
void calcMinsMaxs(struct employee *emp1)
{
	struct employee *tempEmp;    /* tmp pointer value to current employee node */
	
	int i = 0;                   /* counts the employee nodes printed          */
 
	/* Start a beginning of list and print out each value               */
	/* loop until tempEmp points to null (remember null is 0 or false)  */
	tempEmp = emp1;
	struct empMin minData = {tempEmp->wageRate, tempEmp->hours, 
							tempEmp->overtime, tempEmp->gross}; /*initialize minData */
	struct empMin *tempMin;
	tempMin = &minData;

	for(tempEmp = emp1; tempEmp ; tempEmp = tempEmp->next)
	{
		i++;
		tempMin->minWage = (tempMin->minWage < tempEmp->wageRate) 
							? tempMin->minWage : tempEmp->wageRate;
		tempMin->minHours = (tempMin->minHours < tempEmp->hours) 
							? tempMin->minHours : tempEmp->hours;
		tempMin->minOvertime = (tempMin->minOvertime < tempEmp->overtime) 
							? tempMin->minOvertime : tempEmp->overtime;
		tempMin->minGross = (tempMin->minGross < tempEmp->gross) 
							? tempMin->minGross : tempEmp->gross;
	}
	printf("%-15s \t\t%5.2f \t%5.1f \t%4.1f \t%7.2f \n", 
	"Minimum: ", 
	tempMin->minWage,
	tempMin->minHours,
	tempMin->minOvertime,
	tempMin->minGross);
	
	
	/* Calculate maximums */
	struct empMax maxData = {0, 0, 0, 0}; /*initialize maxData */
	struct empMax *tempMax;
	tempMax = &maxData;
	int n = 0;
	for(tempEmp = emp1; tempEmp ; tempEmp = tempEmp->next)
	{
		n++;
		tempMax->maxWage = (tempMax->maxWage > tempEmp->wageRate) 
							? tempMax->maxWage : tempEmp->wageRate;
		tempMax->maxHours = (tempMax->maxHours > tempEmp->hours) 
							? tempMax->maxHours : tempEmp->hours;
		tempMax->maxOvertime = (tempMax->maxOvertime > tempEmp->overtime) 
							? tempMax->maxOvertime : tempEmp->overtime;
		tempMax->maxGross = (tempMax->maxGross > tempEmp->gross) 
							? tempMax->maxGross : tempEmp->gross;
	}
	printf("%-15s \t\t%5.2f \t%5.1f \t%4.1f \t%7.2f \n", 
	"Maximum: ", 
	tempMax->maxWage,
	tempMax->maxHours,
	tempMax->maxOvertime,
	tempMax->maxGross);
	printf("--------------------------------------------------------\n");
	printf("Total Number of Employees = %i\n", i);
}

/*-----------------------------------------------------------------------------*/
/* FUNCTION:     main                                                          */
/*                                                                             */
/* DESCRIPTION:  This function will prompt the user for information regarding  */
/*               all the employees to be considered and create a linked list   */
/*               of employee structures to contain that data.  It will also    */
/*               call calcOvertime and calcGross to place each data point into */
/*               the linked list at the appropriate node.                      */
/*                                                                             */
/* PARAMETERS:   None                                                          */
/*                                                                             */
/* OUTPUTS:      employee pointer - pointer to first node of new linked list   */
/*                                                                             */
/* CALLS:        printLinkedLists, calcOvertime, calcGross                     */
/*-----------------------------------------------------------------------------*/
int main()
{
	char   answer[5];       /* to see if the user wants to add more employees */
    char   value;            /* gets the first character of answer */
    int    moreData = 1;    /* flag to check if another employee is to be processed */
 
    struct employee *currentPointer,   /* pointer to current node */
                    *headPointer;      /* always points to first node */
 
	/* Set up storage for first node */
    headPointer = (struct employee *) malloc (sizeof(struct employee));
    currentPointer = headPointer;
 
    while (moreData)
    {
		/* Read in Employee first and last name */
        printf("\nEnter employee's first and last name: ");
        scanf("%s %s", &currentPointer->firstName, &currentPointer->lastName);
 
		/* Read in Employee ID */
        printf("\nEnter %s %s's ID: ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%i", &currentPointer->clockNumber);
		/* Read in Employee Hourly Wage */
        printf("\nEnter %s %s's wageRate: ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->wageRate);
		/* Read in Employee hours worked */
        printf("\nEnter %s %s's weekly hours: ", &currentPointer->firstName, &currentPointer->lastName);
        scanf("%f", &currentPointer->hours);
 
		/* cal function to calculate overtime */
        currentPointer->overtime = calcOvertime(currentPointer->hours);
		
		/* cal function to calculate gross */
		currentPointer->gross = calcGross(currentPointer->wageRate, currentPointer->hours,
								currentPointer->overtime);
 
        printf("\nWould you like to add another employee? (y/n): \n");
        scanf("%s", answer);
 
        /* Ask user if they want to add another employee */
        if ((value = toupper(answer[0])) != 'Y')
        {
			currentPointer->next = (struct employee *) NULL;
			moreData = 0; 
        }
        else
        {
			/* set the next pointer of the current node to point to the new node */
			currentPointer->next = (struct employee *) malloc (sizeof(struct employee));
			/* move the current node pointer to the new node */
			currentPointer = currentPointer->next;
		}
    } /* while */
	
	
	printLinkedLists(headPointer);
	
	calcSumsAvgs(headPointer);
	
	calcMinsMaxs(headPointer);
	
	printf("End of Program, Thank You\n");
	return (0);
}