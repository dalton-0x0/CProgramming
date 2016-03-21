#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* Define constants */
#define NUM_EMPL 5             /* Number of employees */
#define OVERTIME_RATE 1.5f     /* Overtime factor for pay calculations */
#define STD_WORK_WEEK 40.0f    /* Standard working week hours */
#define NO_OVERTIME 0.0f       /* This implies the employee recorded no overtime */
#define COL_WIDTH 5            /* Number of colums for the printed results */


/* Define global structures */
struct employee
{
	char firstName [10];     /* Employee first name */
	char lastName [10];      /* Employee last name */
	long  int clockNumber;   /* Employee unique ID */
	float wageRate;          /* Hourly wage rate */
	float hours;             /* Hours worked in a given week */
	float overtime;          /* Overtime hours */
	float gross;             /* Gross pay */
	
	struct employee *next;
};

struct empStats
{
	float wageStat;
	float hourStat;
	float overtimeStat;
	float grossStat;
	
	struct empStats *next;
};
struct employee *empData();
float calcOvertime (float hours);
float calcGross (float wageRate, float hours, float overtime);
void printData (struct employee *emp1);
void printStats (struct empStats *stats1);
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
struct employee *empData()
{
	char   answer[80];       /* to see if the user wants to add more employees */
    int    moreData = 1;    /* flag to check if another employee is to be processed */
    char   value;            /* gets the first character of answer */
	
	struct employee *currentPointer,
					*headPointer;
	/* Set up storage for first node */
	headPointer = (struct employee *) malloc (sizeof(struct employee));
	currentPointer = headPointer;
	
	while (moreData)
	{
		printf("\nEnter employee's first and last name: ");
		scanf("%s %s", &currentPointer->firstName, &currentPointer->lastName);
		
		printf("\nEnter %s %s's clock number (ID number): ", &currentPointer->firstName, 
		&currentPointer->lastName);
		scanf("%li", &currentPointer->clockNumber);
		
		printf("\nEnter %s %s's hourly wage: ", &currentPointer->firstName, 
		&currentPointer->lastName);
		scanf("%f", &currentPointer->wageRate);
		
		printf("\nEnter hours worked by %s %s: ", &currentPointer->firstName, 
		&currentPointer->lastName);
		scanf("%f", &currentPointer->hours);
		
		currentPointer->overtime = calcOvertime(currentPointer->overtime);
		currentPointer->gross = calcGross(currentPointer->wageRate, 
										currentPointer->hours,
										currentPointer->overtime);
		
		
		/* Ask user if they want to add another employee */
		printf("Would you like to add another employee? (y/n): ");
		scanf("%s", answer);
		
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
	} /* end while */
	return(headPointer);
} /* end function */
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
float calcOvertime (float hours) 
{
	float overtime;
	if (hours > STD_WORK_WEEK)
	{
		overtime = (hours - STD_WORK_WEEK);
	}
		
	else
	{
		overtime = 0.0;
	}
	return (overtime);
	//printf("\n");
} /* end function */
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
float calcGross (float wageRate, float hours, float overtime) 
{ 
	float gross;
	if (overtime == NO_OVERTIME)
	{
		gross = wageRate * hours;
	}
	else
	{
		gross = (wageRate * STD_WORK_WEEK) 
			+ (wageRate * overtime * OVERTIME_RATE);
	}
	return(gross);
	printf("\n");
} /* end function */
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
void printData (struct employee *emp1)
{ 
	struct employee *tmp;     /* tmp pointer value to current node */
	int i=0;                    /* counts the nodes printed          */
	char name [20];
		/* Format display header */
	printf ("--------------------------------------------------------------------- \n");
	/* Display table headings */
	printf ("%-15s %s \t%s \t%s \t%s \t%s \n", 
	"Name", "Clock#", "Wages", "Hours", "OTime", "Gross");
	/* Format display header */
	printf ("--------------------------------------------------------------------- \n");
	/* Prints employee data */
	for(tmp = emp1; tmp ; tmp = tmp->next) /*for each row*/
    {
		i++;
		strcpy(name, tmp->firstName);
		strcat(name, " ");
		strcat(name, tmp->lastName);
		printf ("%-15s %06li \t%-5.2f \t%-5.1f \t%5.1f \t%8.2f \n", 
		name,
		tmp->clockNumber,  /*print employee ID for pointer address*/
		tmp->wageRate,     /*print hourly wage for pointer address*/
		tmp->hours,        /*print hours worked for pointer address*/
		tmp->overtime,     /*print overtime for pointer address*/
		tmp->gross);       /*print gross pay for pointer address*/
    }
	/* Format bottom display header*/
	printf ("--------------------------------------------------------------------- \n");
	//printf("Total Number of Employees = %i \n", i);
} /* end function */
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
void printStats (struct empStats *stats1)
{ 
	struct employee *tmp;     /* tmp pointer value to current node */
	int i=0;                    /* counts the nodes printed          */
	/* Prints employee data */
	for(tmp = stats1; tmp ; tmp = tmp->next) /*for each row*/
    {
		i++;
		printf ("\t \t \t%-5.2f \t%-5.1f \t%5.1f \t%8.2f \n", 
		tmp->clockNumber,  /*print employee ID for pointer address*/
		tmp->wageRate,     /*print hourly wage for pointer address*/
		tmp->hours,        /*print hours worked for pointer address*/
		tmp->overtime,     /*print overtime for pointer address*/
		tmp->gross);       /*print gross pay for pointer address*/
    }
	/* Format bottom display header*/
	printf ("--------------------------------------------------------------------- \n");
	printf("Total Number of Employees = %i \n", i);
} /* end function */
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
int main ()
{ 
    struct employee *empPointer;   /* pointer to first node of employees */
	struct empStats *statsPointer;     /* pointer to first node of stats */
 
	/* Note: no moving pointer set up for either list in main, because all traversing done in */
	/* other member functions (get_employees and compile_stats)                               */
 
	/* Set up storage for first node */
    empPointer = empData();
	//stats_ptr = compile_stats(empl_ptr);
 
 
    /* Optional - Call Challenge Functions to determine totals, min, max, and averages */
 
    /* print out listing of all employee id's and wages that were entered */
    printData(empPointer);
	printStats(statsPointer);
 
    printf("\n\nEnd of program\n");
    return (0);
}
