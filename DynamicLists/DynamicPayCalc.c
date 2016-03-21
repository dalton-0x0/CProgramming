#include <stdio.h>
#include <stdlib.h>   /* for malloc */
#include <ctype.h>
#include <string.h>
 
#define WEEKLY_HOURS 40.0f  /* total hours before overtime */
#define OT_RATE 1.5f        /* pay multiplier after overtime */
 
struct employee
{
	char  first_name [10];
	char last_name  [10];
	int id_number;
	float wage;
	float hours;
	float overtime;
	float gross;
	struct employee *next;
};

struct empSum
{
	float sumWage;
	float sumHours;
	float sumOvertime;
	float sumGross;
	struct empSum *next;
};

struct empAvg
{
	float avgWage;
	float avgHours;
	float avgOvertime;
	float avgGross;
	struct empAvg *next;
};

struct empMin
{
	float minWage;
	float minHours;
	float minOvertime;
	float minGross;
	struct empMin *next;
};

struct empMax
{
	float maxWage;
	float maxHours;
	float maxOvertime;
	float maxGross;
	struct empMax *next;
};

float get_overtime(float hours);
float get_gross(float wage, float hours, float overtime);
void print_list(struct employee *emp1);
void calcSumsAvgs(struct employee *emp1);
void calcMinsMaxs(struct employee *emp1);

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  get_overtime                                                     */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the number of hours over         */
/*               WEEKLY_HOURS, our constant holding the max total hours before */
/*               overtime kicks in.                                            */
/*                                                                             */
/* PARAMETERS:   hours - total hours worked in one week                        */
/*                                                                             */
/* OUTPUTS:      float - hours of overtime worked                              */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
float get_overtime(float hours)
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
/*                                                                             */
/* FUNCTION:  get_gross                                                        */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the total gross pay for one      */
/*               employee based on their previously entered and calculated     */
/*               wage, hours and overtime.                                     */
/*                                                                             */
/* PARAMETERS:   wage - hourly wage (before overtime)                          */
/*               hours - total hours worked in one week                        */
/*               overtime - hours of overtime worked in one week               */
/*                                                                             */
/* OUTPUTS:      float - hours of overtime worked                              */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
float get_gross(float wage, float hours, float overtime)
{
	float gross; /* value for return */
	if (overtime == 0.0)
	{
		gross = wage * hours;
	}
	else
	{
		gross = (wage * WEEKLY_HOURS) + (wage * overtime * OT_RATE);
	}
	
	return (gross);
}
 
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  print_list                                                       */
/*                                                                             */
/* DESCRIPTION:  This function will print the contents of a linked list of     */
/*               employees.  It will traverse the list from beginning to the   */
/*               end, printing the contents at each node.  It will also print  */
/*               a list of compiled stats regarding the employees.             */
/*                                                                             */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list of employees                  */
/*               stat1 - pointer to a linked list of stats                     */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void print_list(struct employee *emp1)
{
	struct employee *tmp_emp;    /* tmp pointer value to current employee node */
	
	int i = 0;                   /* counts the employee nodes printed          */
		
	char name [20];              /* string to hold full name for each employee */
 
	/* Start a beginning of list and print out each value               */
	/* loop until tmp_emp points to null (remember null is 0 or false)  */
	printf("--------------------------------------------------------\n");
	printf ("%-15s %s \t%s \t%s \t%s \t%s \n", 
	"Name", 
	"Clock#", 
	"Wages", 
	"Hours", 
	"OTime", 
	"Gross");
	printf("--------------------------------------------------------\n");
	for(tmp_emp = emp1; tmp_emp ; tmp_emp = tmp_emp->next)
	{
		i++;
		strcpy(name, tmp_emp -> first_name);
		strcat(name, " ");
		strcat(name, tmp_emp -> last_name);
		printf("%-15s %06i \t%-5.2f \t%-6.1f \t%4.1f \t%7.2f \n", 
		name, 
		tmp_emp->id_number,
		tmp_emp->wage, 
		tmp_emp->hours, 
		tmp_emp->overtime, 
		tmp_emp->gross);
	}
	printf("--------------------------------------------------------\n");
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  calcSumsAvgs                                                     */
/*                                                                             */
/* DESCRIPTION:  This function will print the contents of a linked list of     */
/*               employees.  It will traverse the list from beginning to the   */
/*               end, printing the contents at each node.  It will also print  */
/*               a list of compiled stats regarding the employees.             */
/*                                                                             */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list of employees                  */
/*               stat1 - pointer to a linked list of stats                     */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void calcSumsAvgs(struct employee *emp1)
{
	struct employee *tmp_emp; 
	//struct empSum *tmp_sum;    /* tmp pointer value to current employee node */
		
	int i = 0;                   /* counts the employee nodes printed          */
		
	//char name [20];              /* string to hold full name for each employee */
 
	/* Start a beginning of list and print out each value               */
	/* loop until tmp_emp points to null (remember null is 0 or false)  */
	struct empSum sumData = {0, 0, 0, 0};
	struct empSum *tmp_sum;
	tmp_sum = &sumData;

	for(tmp_emp = emp1; tmp_emp ; tmp_emp = tmp_emp->next)
	{
		i++;
		//tmp_sum->wage;
		tmp_sum->sumWage += tmp_emp->wage;
		tmp_sum->sumHours += tmp_emp->hours;
		tmp_sum->sumOvertime += tmp_emp->overtime;
		tmp_sum->sumGross += tmp_emp->gross;
	}
	printf("%-15s \t%-5.2f \t%-6.1f \t%4.1f \t%7.2f \n", 
	"Total: ", 
	tmp_sum->sumWage,
	tmp_sum->sumHours,
	tmp_sum->sumOvertime,
	tmp_sum->sumGross);
	
	struct empAvg avgData = {0, 0, 0, 0};
	struct empAvg *tmp_avg;
	tmp_avg = &avgData;
	
	tmp_avg->avgWage = tmp_sum->sumWage/i;
	tmp_avg->avgHours = tmp_sum->sumHours/i;
	tmp_avg->avgOvertime = tmp_sum->sumOvertime/i;
	tmp_avg->avgGross = tmp_sum->sumGross/i;
	
	printf("%-15s \t%-5.2f \t%-6.1f \t%4.1f \t%7.2f \n", 
	"Average: ", 
	tmp_avg->avgWage,
	tmp_avg->avgHours,
	tmp_avg->avgOvertime,
	tmp_avg->avgGross);
	printf("--------------------------------------------------------\n");
	//printf("Total Number of Employees = %i\n", i);
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  calcSumsAvgs                                                     */
/*                                                                             */
/* DESCRIPTION:  This function will print the contents of a linked list of     */
/*               employees.  It will traverse the list from beginning to the   */
/*               end, printing the contents at each node.  It will also print  */
/*               a list of compiled stats regarding the employees.             */
/*                                                                             */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list of employees                  */
/*               stat1 - pointer to a linked list of stats                     */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void calcMinsMaxs(struct employee *emp1)
{
	struct employee *tmp_emp; 
	//struct empSum *tmp_sum;    /* tmp pointer value to current employee node */
		
	int i = 0;                   /* counts the employee nodes printed          */
		
	//char name [20];              /* string to hold full name for each employee */
 
	/* Start a beginning of list and print out each value               */
	/* loop until tmp_emp points to null (remember null is 0 or false)  */
	tmp_emp = emp1;
	struct empMin minData = {tmp_emp->wage, tmp_emp->hours, tmp_emp->overtime, tmp_emp->gross};
	struct empMin *tmp_min;
	tmp_min = &minData;

	for(tmp_emp = emp1; tmp_emp ; tmp_emp = tmp_emp->next)
	{
		i++;
		//tmp_sum->wage;
		tmp_min->minWage = (tmp_min->minWage < tmp_emp->wage) ? tmp_min->minWage : tmp_emp->wage;
		tmp_min->minHours = (tmp_min->minHours < tmp_emp->hours) ? tmp_min->minHours : tmp_emp->hours;
		tmp_min->minOvertime = (tmp_min->minOvertime < tmp_emp->overtime) ? tmp_min->minOvertime : tmp_emp->overtime;
		tmp_min->minGross = (tmp_min->minGross < tmp_emp->gross) ? tmp_min->minGross : tmp_emp->gross;
	}
	printf("%-15s \t%-5.2f \t%-6.1f \t%4.1f \t%7.2f \n", 
	"Minimum: ", 
	tmp_min->minWage,
	tmp_min->minHours,
	tmp_min->minOvertime,
	tmp_min->minGross);
	
	
	/* Calculate maximums */
	struct empMax maxData = {0, 0, 0, 0};
	struct empMax *tmp_max;
	tmp_max = &maxData;
	int n = 0;
	for(tmp_emp = emp1; tmp_emp ; tmp_emp = tmp_emp->next)
	{
		n++;
		//tmp_sum->wage;
		tmp_max->maxWage = (tmp_max->maxWage > tmp_emp->wage) ? tmp_max->maxWage : tmp_emp->wage;
		tmp_max->maxHours = (tmp_max->maxHours > tmp_emp->hours) ? tmp_max->maxHours : tmp_emp->hours;
		tmp_max->maxOvertime = (tmp_max->maxOvertime > tmp_emp->overtime) ? tmp_max->maxOvertime : tmp_emp->overtime;
		tmp_max->maxGross = (tmp_max->maxGross > tmp_emp->gross) ? tmp_max->maxGross : tmp_emp->gross;
	}
	printf("%-15s \t%-5.2f \t%-6.1f \t%4.1f \t%7.2f \n", 
	"Maximum: ", 
	tmp_max->maxWage,
	tmp_max->maxHours,
	tmp_max->maxOvertime,
	tmp_max->maxGross);
	printf("--------------------------------------------------------\n");
	printf("Total Number of Employees = %i\n", i);
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  main                                                             */
/*                                                                             */
/* DESCRIPTION:  This function will prompt the user for information regarding  */
/*               all the employees to be considered and create a linked list   */
/*               of employee structures to contain that data.  It will also    */
/*               call get_overtime and get_gross to place each data point into */
/*               the linked list at the appropriate node.                      */
/*                                                                             */
/* PARAMETERS:   None                                                          */
/*                                                                             */
/* OUTPUTS:      employee pointer - pointer to first node of new linked list   */
/*                                                                             */
/* CALLS:        get_overtime, get_gross                                       */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
int main()
{
	char   answer[5];       /* to see if the user wants to add more employees */
    char   value;            /* gets the first character of answer */
    int    more_data = 1;    /* flag to check if another employee is to be processed */
 
    struct employee *current_ptr,   /* pointer to current node */
                    *head_ptr;      /* always points to first node */
 
	/* Set up storage for first node */
    head_ptr = (struct employee *) malloc (sizeof(struct employee));
    current_ptr = head_ptr;
 
    while (more_data)
    {
		/* Read in Employee first and last name */
        printf("\nEnter employee's first and last name: ");
        scanf("%s %s", & current_ptr -> first_name, & current_ptr -> last_name);
 
		/* Read in Employee ID and Hourly Wage */
        printf("\nEnter %s %s's ID: ", & current_ptr -> first_name, & current_ptr -> last_name);
        scanf("%i", & current_ptr -> id_number);
 
        printf("\nEnter %s %s's wage: ", & current_ptr -> first_name, & current_ptr -> last_name);
        scanf("%f", & current_ptr -> wage);
 
        printf("\nEnter %s %s's weekly hours: ", & current_ptr -> first_name, & current_ptr -> last_name);
        scanf("%f", & current_ptr -> hours);
 
        current_ptr -> overtime = get_overtime(current_ptr -> hours);
		current_ptr -> gross = get_gross(current_ptr -> wage, current_ptr -> hours,
								current_ptr -> overtime);
 
        printf("\nWould you like to add another employee? (y/n): ");
        scanf("%s", answer);
 
        /* Ask user if they want to add another employee */
        if ((value = toupper(answer[0])) != 'Y')
        {
			current_ptr->next = (struct employee *) NULL;
			more_data = 0; 
        }
        else
        {
			/* set the next pointer of the current node to point to the new node */
			current_ptr->next = (struct employee *) malloc (sizeof(struct employee));
			/* move the current node pointer to the new node */
			current_ptr = current_ptr->next;
		}
    } /* while */
	
	print_list(head_ptr);
	
	calcSumsAvgs(head_ptr);
	
	calcMinsMaxs(head_ptr);
	
	printf(">>>>>End of Program, Thank You<<<<<\n");
	return (0);
}