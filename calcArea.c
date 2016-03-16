//**************************************************************/ 
// Function: calcArea 
// 
// Purpose: Calculates the area of a trapezoid when given the 
// the two base lengths and altitude as input arguments. Stores  
// the result in a local variable that is passed back to the  
// calling function.
// Area = average of the two base lengths times the altitude.
//
// Parameters: 
// baseA - length of one of the parallel sides
// baseB - length of the other parallel side
// altitude - distance (at right angles) from one base to the other
// 
// Returns: areaTrapezoid - area of the specified trapezoid
//**************************************************************/ 
float calcArea (float baseA, float baseB, float altitude) 
{ 
    float areaTrapezoid; /* local variable for storage */
    
    /* calculate area using formula */
    areaTrapezoid = ((baseA + baseB) / 2) * altitude;

    return (areaTrapezoid); /* return area */
} /* end function */