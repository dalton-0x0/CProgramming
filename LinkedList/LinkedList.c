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

float get_overtime(float hours);
float get_gross(float wage, float hours, float overtime);
struct employee *get_employees();
void print_list(struct employee *emp1);

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
struct employee *get_employees()
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
	return (head_ptr);
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
			printf("%-15s %06i \t%-5.2f \t%-5.1f \t%4.1f \t%6.2f \n", 
			name, 
			tmp_emp->id_number,
			tmp_emp->wage, 
			tmp_emp->hours, 
			tmp_emp->overtime, 
			tmp_emp->gross);
        }
		printf("--------------------------------------------------------\n");

        printf("\nTotal Number of Employees = %d\n", i);
 
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
	//struct stats *stats_ptr;     /* pointer to first node of stats */
 
	/* Note: no moving pointer set up for either list in main, because all traversing done in */
	/* other member functions (get_employees and compile_stats)                               */
 
	/* Set up storage for first node */
    empl_ptr = get_employees();
	//stats_ptr = compile_stats(empl_ptr);
 
 
    /* Optional - Call Challenge Functions to determine totals, min, max, and averages */
 
    /* print out listing of all employee id's and wages that were entered */
    print_list(empl_ptr);
	//print_stat (stats_ptr);
 
    printf("\nEnd of program\n");
    return (0);
}