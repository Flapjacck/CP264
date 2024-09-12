/**
 * -------------------------------------
 * @file  main.c
 * Assignment 1 Main Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2023-09-07
 *
 * -------------------------------------
 */
#include <stdlib.h>
#include <stdio.h>

#include "functions.h"

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);

	// Your code here
	//Example of feet_to_acres
	double square_feet = 100000.0;  // example value
	double acres = feet_to_acres(square_feet);
	printf("Square footage: %.2f sq ft is equivalent to %.2f acres\n",
			square_feet, acres);

	//example of mow_lawn
	double width = 10.0;  // example value
	double length = 10.0;  // example value
	double speed = 5.0;  // example value
	int time = mow_lawn(width, length, speed);
	printf(
			"It will take %.2d minutes to mow a %.2f x %.2f lawn at %.2f sq ft per minute\n",
			time, width, length, speed);

	//example of date_convert
	int date_number = 25101962;  // example value
	int date = date_convert(date_number);
	printf("The converted date is: %d\n", date);

	//example of falling_time
	int distance = 50;  // example value
	int time_falling = falling_time(distance);
	printf("It will take %.2d seconds for an object to fall %.2d meters\n",
			time_falling, distance);

	//example of hypotenuse
	double side1 = 3.0;  // example value
	double side2 = 4.0;  // example value
	double hyp = hypotenuse(side1, side2);
	printf(
			"The hypotenuse of a right triangle with sides %.2f and %.2f is %.2f\n",
			side1, side2, hyp);

	//example of sum_even
	int n = 100;  // example value
	int sum = sum_even(n);
	printf("The sum of even numbers from 1 to %d is %d\n", n, sum);

	//example of sum_partial_harmonic
	int k = 4;  // example value
	double sum_partial = sum_partial_harmonic(k);
	printf("The sum of the first %d terms of the harmonic series is %f\n", k,
			sum_partial);

	//example of population_growth
	int start = 10;  // example value
	double rate = 10;  // example value
	int target = 100;  // example value
	int years = population_growth(start, rate, target);
	printf(
			"It will take %d year(s) for a population of %d to grow to %d with a growth rate of %.2f\n",
			years, start, target, rate);

	return 0;
}
