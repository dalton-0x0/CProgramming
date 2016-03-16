/*--------------------------------------------------------------*/ 
/* HOMEWORK: Midterm Exam, Question 6                           */ 
/*                                                              */ 
/* NAME:     Dalton Okechukwu                                   */ 
/*                                                              */ 
/* CLASS:    C Programming (INFO.90.267)                        */ 
/*                                                              */ 
/* DATE:     01-Mar-2016                                        */ 
/*                                                              */
/* DESCRIPTION:                                                 */
/* This program contains a main function and three other        */
/* functions that will return various attribute information     */
/* about an array of floating point numbers:                    */
/* sumArray - computes total sum of all array elements          */
/* avgArray - computes average of all array elements            */
/* minArray - computes the smallest number of the array elements*/
/*--------------------------------------------------------------*/
#include <stdio.h> 

/* declare function prototypes */ 
float sumArray (float theArray[], int size); /* sum of array elements */
float avgArray (float theArray[], int size); /* avg of array elements */
float minArray (float theArray[], int size); /* min of array elements */

/* define main function */
int main()
{
    /* declare array of floating point numbers */
    float theArray [] = {5, 2, 19, 4, 0.2, 6, 7, 28, 9, 10};

    /* print results by callling functions  */
	printf ("The sum of the Array elements is %.2f \n", sumArray(theArray, 10)); 
    printf ("The avg of the Array elements is %.2f \n", avgArray(theArray, 10));
    printf ("The min of the Array elements is %.2f \n", minArray(theArray, 10));
    return 0;
} /* end main */

//**************************************************************/ 
// Function: sumArray
// 
// Purpose: computes total sum of all array elements.
//
// Parameters: 
// theArray - an array of floating point numbers
// size - number of elements in the array
// 
// Returns: value of sum of the array elements
//**************************************************************/ 
float sumArray (float theArray[], int size) 
{ 
    static float sumTheArray = 0;   /* local static variable */

    int i;                          /* loop index */

    for (i=0; i < size; ++i)        /* loop through each element */
    {
    	sumTheArray += theArray[i]; /* build running total */
    }
    /* return running total to calling function */
    return (sumTheArray);           
} /* end function */

//**************************************************************/ 
// Function: avgArray
// 
// Purpose: computes the average of the array elements.
//
// Parameters: 
// theArray - an array of floating point numbers
// size - number of elements in the array
// 
// Returns: value of the average of the array elements.
//**************************************************************/ 
float avgArray (float theArray[], int size) 
{ 
    static float sumTheArray = 0;   /* local static variable */
    static float avgTheArray;       /* local static variable */
    int i;                          /* loop index */

    for (i=0; i < size; ++i)        /* loop through each element */
    {
    	sumTheArray += theArray[i]; /* build running total */

    	/* find average of running total */
    	avgTheArray = sumTheArray / (i+1);
    }
    /* return average to calling function */
    return (avgTheArray);          
} /* end function */

//**************************************************************/ 
// Function: minArray
// 
// Purpose: computes the array element with the minimum value.
//
// Parameters: 
// theArray - an array of floating point numbers
// size - number of elements in the array
// 
// Returns: value of the minimum array element
//**************************************************************/ 
float minArray (float theArray[], int size) 
{ 
    /* initialize local variable minTheArray. Assign value of the */
    /* first array element*/
    float minTheArray = theArray[0]; 
    int i;                              /* loop index */
    
    /* loop through each array element starting from the second */
    for (i=1; i < size; ++i)            
    {
    	if (theArray[i] < minTheArray)  /* check if this element < minTheArray */
    	{
    		minTheArray = theArray[i];  /* update minTheArray */
    	}
    	else
    	{
    		minTheArray = minTheArray; /* do nothing otherwise */
    	}
    }
    return (minTheArray); /* return minimum value */
} /* end function */



((i1>i2)?i1:i2) > ((i3>i4)?i3:i4)? ((i1>i2)?i1:i2):((i3>i4)?i3:i4);