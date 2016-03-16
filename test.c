//**************************************************************/ 
// Function: x_to_the_n
// 
// Purpose: raises an integer to a positive integer power.
//
// Parameters: 
// x - integer to be exponentiated
// n - integer exponent
// 
// Returns: result of exponentiation.
//**************************************************************/ 
int x_to_the_n (int x, int n)
{
	long int result = x; /* assign x to local variable */

	int i;               /* initialize loop index */

	/* loop through (n-1) times */ 
	/* if n = 1, this loop doesn't run, result is returned */
	for (i = 1; i <= (n-1); ++i) 
	{
		result *= x;     /* multiply by x and assign back to result */ 
	}
	return (result);     /* return result to calling function */ 
} /* end function */

/* define structures within the global structure 'starfleet_officers' */
struct name
{
	char title[5];          /* officer's title: Mr, Mrs, Dr, Prof, etc. */
	char first_name[10];    /* officer's first name */
	char mid_name[10];      /* officer's middle name or initial */
	char last_name[10];     /* officer's last name */
	char suffix_name[5];    /* officer's suffix: Jr, Sr, III, etc. */
};

struct date
{
	char short_date[8];     /* written as mm/dd/yyyy */
	/* below provides option for long date */
	char month[8];          /* enter month */
	int day;                /* enter day as an integer */
	int year;               /* enter year as an integer */
};

struct date sdate[2];       /* declare array of structure of type 'struct date' with 2 elements */

struct address
{
	char street_name[50];   /* street name */
	char city_name[20];     /* city name */
	char state_name[20];    /* state name */
	char zip_code[10];      /* zip code */
	char planet_name[20];   /* planet name */
};

/* define global structure template called 'starfleet_officers' */
struct starfleet_officers 
{
	struct name sname;           /* structure variable of type 'struct name' */
	sdate[0];                    /* ref first element of array of structures of type 'struct date' */
                                 /* this element holds the officer's date of birth */
	struct address saddress;     /* structure variable of type 'struct address' */
	char rank[30];               /* officer's rank */
	char nickname[10];           /* officer's nickname */
	long int id_number;          /* officer's ID number */
	float wage;                  /* officer's hourly pay */
	char fav_quote[30];          /* officer's favorite saying */
	float star_date;             /* officer's starting stardate */
	char marital_status[10];     /* officer's marital status */
	sdate[1];                    /* another element of array of structures of type 'struct date' */
                                 /* this element holds the officer's graduation date */
};

/* declare array of structures of type 'struct starfleet_officers'*/
/* the structure variable 'officer_data' holds each officer's info       */
/* the size of the array is set at 100 but can be increased              */

struct starfleet_officers officer_data[100];