//********************************************************************************************************************
//
//	FINAL:          Question 8, Baseball player stats
//
//	NAME:           Jesse Chamberlain
//
//	CLASS:          C Programming, Fall 2015
//
//	DATE:           11/09/15
//
//  DESCRIPTION:    This program prompts the user for player stats. It then calculates the totals, ratios and averages.
//
//********************************************************************************************************************

#include <stdio.h>
#include <stdlib.h>             // for malloc
#include <string.h>
#include <ctype.h>

struct stats
{
    char first_name [15];       // Player First Name
    char last_name [15];        // Player last Name
    double bb;                  // Number of Walks
    double so;                  // Strike Outs
    double hp;                  // Hit by Pitch
    double sf;                  // Sac Flys
    double sngl;                // Singles
    double dbl;                 // Doubles
    double trpl;                // Triples
    double hr;                  // Home Runs
    double ab;                  // Number of At Bats
    double t_bases;             // Total Bases
    double b_avg;               // Batting Average
    double hr_ratio;            // Home Run Ratio
    double so_ratio;            // Strike Out Ratio
    double ob_prct;             // On Base Percentage
    double s_avg;               // Slugging Average
    
    struct stats *next;
};

double total_bases (struct stats * data_ptr);
double batting_avg (struct stats * data_ptr);
double home_run_ratio (struct stats * data_ptr);
double strike_out_ratio (struct stats * data_ptr);
double on_base_percentage (struct stats * data_ptr);
double slugging_avg (struct stats data []);
void calc_data (struct stats data []);
void get_data (struct stats data []);
void print_data (struct stats data []);
void print_header ();
void print_footer ();
void print_player (struct stats data []);

int main()
{
    
    char answer[1000];          // See if the user wants to add more players
    int more_data = 1;          // Flag to check if another player is to be processed
    char value;                 // Gets the first character of answer
    
    struct stats *current_ptr,  // Pointer to current node
    *head_ptr;                  // Always points to first node
    
    // Set up storage for first node
    head_ptr = (struct stats *) malloc (sizeof(struct stats));
    current_ptr = head_ptr;
    
    while (more_data)
    {
        // Call Function to prompt and retreive player data
        get_data (current_ptr);
        
        // Call Function to calculate player data
        calc_data (current_ptr);
        
        // Ask user if they want to add another player
        printf("\nWould you like to add another player? (y/n): ");
        scanf("%s", answer);
        
        if ((value = toupper(answer[0])) != 'Y')
        {
            current_ptr->next = (struct stats *) NULL;
            more_data = 0;
            
        }  // if
        
        else
        {
            // Set the next pointer of the current node to point to the new node
            current_ptr->next = (struct stats *) malloc (sizeof(struct stats));
            
            // Move the current node pointer to the new node
            current_ptr = current_ptr->next;
            
        } // else
        
    } // while
    
    // Call Function to print data
    print_data (head_ptr);
    
}

//********************************************************************************************************************
//
// FUNCTION:        total_bases
//
// PURPOSE:         Processes total bases based of single, double, triple and home run hits.
//
// PARAMETERS:
//                  data_ptr - An array of structures containing player stats.
//                  total - Holds number of bases acheived.
//
// RETURNS:         total
//
//********************************************************************************************************************

double total_bases (struct stats * data_ptr)
{
    double total;
    
    total = (data_ptr -> sngl + (2 * data_ptr -> dbl) + (3 * data_ptr -> trpl) + (4 * data_ptr -> hr));
    
    return (total);
    
} // total_bases

//********************************************************************************************************************
//
// FUNCTION:        batting_avg
//
// PURPOSE:         Processes batting average.
//
// PARAMETERS:
//                  data_ptr - An array of structures containing player stats.
//                  avg - Holds batting average.
//
// RETURNS:         avg
//
//********************************************************************************************************************

double batting_avg (struct stats * data_ptr)
{
    double avg;
    
    avg = (data_ptr -> sngl + data_ptr -> dbl + data_ptr -> trpl + data_ptr -> hr)/data_ptr -> ab;
    
    return (avg);
    
} // batting_avg

//********************************************************************************************************************
//
// FUNCTION:        home_run_ratio
//
// PURPOSE:         Processes Home Run Ratio.
//
// PARAMETERS:
//                  data_ptr - An array of structures containing player stats.
//                  avg - Holds Home Run Ratio.
//
// RETURNS:         avg
//
//********************************************************************************************************************

double home_run_ratio (struct stats * data_ptr)
{
    double avg;
    
    avg = data_ptr->hr/data_ptr->ab;
    
    return (avg);
    
} // home_run_ratio

//********************************************************************************************************************
//
// FUNCTION:        strike_out_ratio
//
// PURPOSE:         Processes Strike Out Ratio.
//
// PARAMETERS:
//                  data_ptr - An array of structures containing player stats.
//                  avg - Holds Strike Out Ratio.
//
// RETURNS:         avg
//
//********************************************************************************************************************

double strike_out_ratio (struct stats * data_ptr)
{
    double avg;

    avg = data_ptr->so/data_ptr->ab;
    
    return (avg);
    
} // strike_out_ratio

//********************************************************************************************************************
//
// FUNCTION:        on_base_percentage
//
// PURPOSE:         Processes On Base Percentage.
//
// PARAMETERS:
//                  data_ptr - An array of structures containing player stats.
//                  ob_pct - Holds On Base Percentage.
//
// RETURNS:         ob_pct
//
//********************************************************************************************************************

double on_base_percentage (struct stats * data_ptr)
{
    double ob_pct;
    
    ob_pct = ((data_ptr->sngl + data_ptr->dbl + data_ptr->trpl + data_ptr->hr) + data_ptr->bb + data_ptr->hp)/(data_ptr->ab + data_ptr->bb + data_ptr->hp + data_ptr->sf);
    
    return (ob_pct);
    
} // on_base_percentage

//********************************************************************************************************************
//
// FUNCTION:        slugging_avg
//
// PURPOSE:         Processes Slugging Average.
//
// PARAMETERS:
//                  data_ptr - An array of structures containing player stats.
//                  avg - Holds Slugging Average.
//
// RETURNS:         avg
//
//********************************************************************************************************************

double slugging_avg (struct stats * data_ptr)
{
    double avg;
    
    avg = (data_ptr -> sngl + (2 * data_ptr -> dbl) + (3 * data_ptr -> trpl) + (4 * data_ptr -> hr))/data_ptr->ab;
    
    return (avg);
    
} // slugging_avg

//********************************************************************************************************************
//
// FUNCTION:        calc_data
//
// PURPOSE:         Sends stats out to individual calculators and sends the answers back to the structure via pointers.
//
// PARAMETERS:
//                  data_ptr - An array of structures containing player stats.
//
// RETURNS:         Nothing
//
//********************************************************************************************************************

void calc_data (struct stats * data_ptr)
{
    data_ptr->t_bases = total_bases (data_ptr);
    data_ptr->b_avg = batting_avg (data_ptr);
    data_ptr->hr_ratio = home_run_ratio (data_ptr);
    data_ptr->so_ratio = strike_out_ratio (data_ptr);
    data_ptr->ob_prct = on_base_percentage (data_ptr);
    data_ptr->s_avg = slugging_avg (data_ptr);
    
} // calc_data

//********************************************************************************************************************
//
// FUNCTION:        get_data
//
// PURPOSE:         Prompts for player stats and sends the answers back to the structure via pointers.
//
// PARAMETERS:
//                  data_ptr - An array of structures containing player stats.
//
// RETURNS:         Nothing
//
//********************************************************************************************************************

void get_data (struct stats * data_ptr)
{
    // Prompt for Player Name
    printf("\nEnter player first & last name: ");
    scanf("%s" "%s", data_ptr -> first_name, data_ptr -> last_name);
    
    // Prompt for Number of Walks
    printf("\nEnter Number of Walks: ");
    scanf("%lf", & data_ptr -> bb);
    
    // Prompt for Strike Outs
    printf("\nEnter Strike Outs: ");
    scanf("%lf", & data_ptr -> so);
    
    // Prompt for Hit by Pitch
    printf("\nEnter Hit by Pitch: ");
    scanf("%lf", & data_ptr -> hp);
    
    // Prompt for Sac Flys
    printf("\nEnter Sac Flys: ");
    scanf("%lf", & data_ptr -> sf);
    
    // Prompt for Singles
    printf("\nEnter Singles: ");
    scanf("%lf", & data_ptr -> sngl);
    
    // Prompt for Doubles
    printf("\nEnter Doubles: ");
    scanf("%lf", & data_ptr -> dbl);
    
    // Prompt for Triples
    printf("\nEnter Triples: ");
    scanf("%lf", & data_ptr -> trpl);
    
    // Prompt for Home Runs
    printf("\nEnter Home Runs: ");
    scanf("%lf", & data_ptr -> hr);
    
    // Prompt for Number of At Bats
    printf("\nEnter Number of At Bats: ");
    scanf("%lf", & data_ptr -> ab);
    
} // get_data

//********************************************************************************************************************
//
// FUNCTION:        print_header
//
// PURPOSE:         Prints out header in alignment in data table format.
//
// RETURNS:         Nothing (void)
//
//********************************************************************************************************************

void print_header ()
{
    
    printf ("\t----------------------------------------------------------------------------------------------------------\n");
    printf ("\tPlayer Name                     \t bb| so| hp| sf|sgl|dbl|tpl| hr| ab| tb|   ba|  hrr|  sor|  obp|   sa|\n");
    printf ("\t----------------------------------------------------------------------------------------------------------\n");
    
} // print_header

//********************************************************************************************************************
//
// FUNCTION:        print_player
//
// PURPOSE:         This function will print the contents of a linked list.  It will traverse the list from beginning
//                  to the end, printing the contents at each node. Prints to screen in a table format the following
//                  stats about a player:
//
//                  Player First Name, Player Last Name, Number of Walks, Strike Outs, Hit by Pitch, Sac Flys, Singles,
//                  Doubles, Triples, Home Runs, Number of At Bats, Total Bases, Batting Average, Home Run Ratio,
//                  Strike Out Ratio, On Base Percentage, Slugging Average.
//
// PARAMETERS:
//                  data_ptr - An array of structures containing player stats.
//                  i - Loop counter.
//
// RETURNS:         Nothing (void)
//
//********************************************************************************************************************

void print_player (struct stats * data)
{
    struct stats *data_ptr;         // tmp pointer value to current node
    int i = 0;                      // counts the nodes printed
    
    // Start at beginning of list and print out each value
    // loop until data_ptr points to null
    for(data_ptr = data; data_ptr ; data_ptr = data_ptr->next)
    {
        i++;
        
        printf("\t%-15s %-15s \t%3.0f|%3.0f|%3.0f|%3.0f|%3.0f|%3.0f|%3.0f|%3.0f|%3.0f|%3.0f|%.3f|%.3f|%.3f|%.3f|%.3f|\n",
               data_ptr -> first_name, data_ptr -> last_name, data_ptr -> bb, data_ptr -> so, data_ptr -> hp, data_ptr -> sf, data_ptr -> sngl, data_ptr -> dbl, data_ptr -> trpl, data_ptr -> hr, data_ptr -> ab, data_ptr ->t_bases, data_ptr -> b_avg, data_ptr -> hr_ratio, data_ptr -> so_ratio, data_ptr -> ob_prct, data_ptr -> s_avg);
        
    } // for
    
} // print_employee

//********************************************************************************************************************
//
// FUNCTION:        print_footer
//
// PURPOSE:         Prints out footer in alignment in data table format.
//
// RETURNS:         Nothing (void)
//
//********************************************************************************************************************

void print_footer ()
{
    
    printf ("\t----------------------------------------------------------------------------------------------------------\n");
    
} // print_footer

//********************************************************************************************************************
//
// FUNCTION:        print_data
//
// DESCRIPTION:     Calls functions to print to screen.
//
// PARAMETERS:
//                  data_ptr - An array of structures containing player stats.
//
// OUTPUTS:         None
//
// CALLS:           print_header, print_player, print footer
//
//********************************************************************************************************************

void print_data(struct stats * data)
{
    // Function call to obtain header and print to screen
    print_header ();
    
    // Function call to obtain employee data and print to screen
    print_player (data);
    
    // Function call to obtain footer and print to screen
    print_footer();
    
} // print_data