#pragma once

enum class error_code: int
{
    negativeNumError
};

float calcSqrt(float num); // calc sqrt of a number
void takeInputAndCalc(); // take an input from the user and use the calcSqrt func to calc its sqrt