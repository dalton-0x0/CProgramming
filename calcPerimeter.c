//**************************************************************/ 
// Function: calcPerimeter
// 
// Purpose: Calculates the perimeter of a trapezoid when given the 
// the two base lengths and length of the two legs as input arguments. 
// Stores the result in a local variable that is passed back 
// to the calling function. 
// Area = average of the two base lengths times the altitude.
//
// Parameters: 
// baseA - length of one of the parallel sides
// baseB - length of the other parallel side
// legA - length of one of the non-parallel sides
// legB - length of the other non-parallel side
// 
// Returns: periTrapezoid - perimeter of the specified trapezoid
//**************************************************************/ 
float calcArea (float baseA, float baseB, float legA, float legB) 
{ 
    float periTrapezoid; /* local variable for storage */
    
    /* calculate perimeter using formula */
    periTrapezoid = (baseA + baseB + legA + legB);

    return (periTrapezoid); /* return area */
} /* end function */