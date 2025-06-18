#pragma once

enum class error_codes : int
{
	nonPositiveNumber
};

// checks if an int is a prime number
bool isPrime(int num);

// prints if the number is prime using the isPrime function
void printIsNumberPrime(int num);