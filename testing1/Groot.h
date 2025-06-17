#pragma once

enum class error_code : int
{
    negativeNumError
};

// calc sqrt of a number
float calcSqrt(float num); 

// take an input from the user and use the calcSqrt func to calc its sqrt
void takeInputAndCalcSqrt();