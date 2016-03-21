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
 
/* While a linked list of stats might not be the most efficient way to accomplish */
/* this particular task, it can be made to the do the job and is an interesting   */
/* exercise for practice purposes. It also let me create entirely my own linked   */
/* list to try and make functional. Actually considered whether to use the same   */
/* structure as employee for stats; could be done with only a mild alteration to  */
/* the printing format, but elected to use a different struct for the practice.   */
struct stats
{
	char  name[10];
	float wage;
	float hours;
	float overtime;
	float gross;
	struct stats *next;
};
 
void print_list(struct employee *emp1, struct stats *stat1);
struct employee * get_employees();
float get_overtime(float hours);
float get_gross(float wage, float hours, float overtime);
struct stats * compile_stats(struct employee *emp1);
 
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
	if (hours > WEEKLY_HOURS)
	{
		return (hours - WEEKLY_HOURS);
	}
	else
	{
		return 0.0;
	}
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
	gross = wage * hours;
	gross += wage * overtime * (OT_RATE - 1); /* OT_RATE - 1 so as to not double hours */
	return gross;
}
 
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  get_employees                                                    */
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
struct employee * get_employees()
{
	char   answer[80];       /* to see if the user wants to add more employees */
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
	return head_ptr;
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
void print_list(struct employee *emp1, struct stats *stat1)
{
        struct employee *tmp_emp;    /* tmp pointer value to current employee node */
		struct stats *tmp_stat;      /* tmp pointer value to current stats node    */
        int i = 0;                   /* counts the employee nodes printed          */
		char name [21];              /* string to hold full name for each employee */
 
        /* Start a beginning of list and print out each value               */
        /* loop until tmp_emp points to null (remember null is 0 or false)  */
		printf("----------------------------------------------------------------\n");
		printf("Name            Clock#   Wage   Hours    OT     Gross\n");
		printf("----------------------------------------------------------------\n");
        for(tmp_emp = emp1; tmp_emp ; tmp_emp = tmp_emp->next)
        {
            i++;
			strcpy(name, tmp_emp -> first_name);
			strcat(name, " ");
			strcat(name, tmp_emp -> last_name);
			printf("%20s %06d  %8.2f %7.1f %7.1f %10.2f", name, tmp_emp->id_number,
					tmp_emp->wage, tmp_emp->hours, tmp_emp->overtime, tmp_emp->gross);
        }
 
        printf("\n\nTotal Number of Employees = %d\n", i);
 
}
 
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* FUNCTION:  compile_stats                                                   */
/*                                                                            */
/* DESCRIPTION:  This function takes a linke list of employees and compiles   */
/*               several statistics about them, including averages, totals,   */
/*               minimum and maximum for each float field.                    */
/*                                                                            */
/* PARAMETERS:   emp1 - pointer to first node of employee list                */
/*                                                                            */
/* OUTPUTS:      stats pointer - pointer to new list of compiled stats        */
/*                                                                            */
/* CALLS:                                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
struct stats * compile_stats(struct employee *emp1)
{
    int    more_data = 1;    /* flag to check if another employee is to be processed */
	int    count = 0;        /* counter for loop, for average */
 
    struct stats *current_ptr,   /* pointer to current node */
                 *head_ptr;      /* always points to first node */
 
	/* Set up storage for first node */
    head_ptr = (struct stats *) malloc (sizeof(struct stats));
	current_ptr = head_ptr;
	strcpy (current_ptr -> name, "Total:");
 
	current_ptr -> next = (struct stats *) malloc (sizeof(struct stats));
	current_ptr = current_ptr -> next;
	strcpy (current_ptr -> name, "Average:");
 
	current_ptr -> next = (struct stats *) malloc (sizeof(struct stats));
	current_ptr = current_ptr -> next;
	strcpy (current_ptr -> name, "Maximum: ");
	current_ptr -> wage = emp1 -> wage;  /* initializes max with non-junk data */
	current_ptr -> hours = emp1 -> hours;
	current_ptr -> overtime = emp1 -> overtime;
	current_ptr -> gross = emp1 -> gross;
 
	current_ptr -> next = (struct stats *) malloc (sizeof(struct stats));
	current_ptr = current_ptr -> next;
	strcpy (current_ptr -> name, "Minimum: ");
	current_ptr -> wage = emp1 -> wage;  /* initializes min with non-junk data */
	current_ptr -> hours = emp1 -> hours;
	current_ptr -> overtime = emp1 -> overtime;
	current_ptr -> gross = emp1 -> gross;
 
    while (more_data)
    {
		current_ptr = head_ptr;
		count++;
		current_ptr -> wage += emp1 -> wage;
		current_ptr -> hours += emp1 -> hours;
		current_ptr -> overtime += emp1 -> overtime;
		current_ptr -> gross += emp1 -> gross;
 
		current_ptr = (current_ptr -> next) -> next; /* Skipping average, to maximum */
 
		/* set current stats to higher of what is presently in stats list or the current iteration */
		/* of the employee list for each of wage, hours, gross and overtime                        */
		current_ptr -> wage = (current_ptr -> wage > emp1 -> wage) ? current_ptr -> wage : emp1 -> wage;
		current_ptr -> hours = (current_ptr -> hours > emp1 -> hours) ? current_ptr -> hours : emp1 -> hours;
		current_ptr -> gross = (current_ptr -> gross > emp1 -> gross) ? current_ptr -> gross : emp1 -> gross;
		current_ptr -> overtime = (current_ptr -> overtime > emp1 -> overtime) ? current_ptr -> overtime : 
									emp1 -> overtime;
 
		current_ptr = current_ptr -> next; /* Advancing to minimum */
 
		/* set current stats to lesser of what is presently in stats list or the current iteration */
		/* of the employee list for each of wage, hours, gross and overtime                        */
		current_ptr -> wage = (current_ptr -> wage < emp1 -> wage) ? current_ptr -> wage : emp1 -> wage;
		current_ptr -> hours = (current_ptr -> hours < emp1 -> hours) ? current_ptr -> hours : emp1 -> hours;
		current_ptr -> gross = (current_ptr -> gross < emp1 -> gross) ? current_ptr -> gross : emp1 -> gross;
		current_ptr -> overtime = (current_ptr -> overtime < emp1 -> overtime) ? current_ptr -> overtime : 
									emp1 -> overtime;
 
		if (emp1 -> next == (struct employee *) NULL)
		{
			more_data = 0;
		}
		else
		{
			emp1 = emp1 -> next;
		}
	}
	current_ptr = head_ptr -> next; /* finish with the average stats */
	current_ptr -> wage /= count;
	current_ptr -> hours /= count;
	current_ptr -> gross /= count;
	current_ptr -> overtime /= count;
	return head_ptr;
}
 
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* FUNCTION:  main                                                            */
/*                                                                            */
/* DESCRIPTION:  This function will prompt the user for an employee           */
/*               id and wage until the user indicates they are finished.      */
/*               At that point, a list of id and wages will be                */
/*               generated.                                                   */
/*                                                                            */
/* PARAMETERS:   None                                                         */
/*                                                                            */
/* OUTPUTS:      None                                                         */
/*                                                                            */
/* CALLS:        print_list, get_employees, compile_stats                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int main ()
{ 
    struct employee *empl_ptr;   /* pointer to first node of employees */
	struct stats *stats_ptr;     /* pointer to first node of stats */
 
	/* Note: no moving pointer set up for either list in main, because all traversing done in */
	/* other member functions (get_employees and compile_stats)                               */
 
	/* Set up storage for first node */
    empl_ptr = get_employees();
	stats_ptr = compile_stats(empl_ptr);
 
 
    /* Optional - Call Challenge Functions to determine totals, min, max, and averages */
 
    /* print out listing of all employee id's and wages that were entered */
    print_list(empl_ptr, stats_ptr);
 
    printf("\n\nEnd of program\n");
    return (0);
}