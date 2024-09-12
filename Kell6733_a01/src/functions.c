/**
 * -------------------------------------
 * @file  functions.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2023-09-07
 *
 * -------------------------------------
 */

#include "functions.h"
#include <math.h>

// Your code here

double feet_to_acres(int square_feet) {
	// 1 acre = 43560 sq ft
	double square_footage = square_feet / FEET_PER_ACRE;
	return square_footage;
}

int mow_lawn(double width, double length, double speed) {
	// speed is in sq ft per minute
	double area = width * length;
	int time = area / speed;
	return time;
}

int date_convert(int date_number) {
	// date_number is in the format ddmmyyyy
	int day = date_number / 1000000;
	int month = (date_number / 10000) % 100;
	int year = date_number % 10000;
	int date = year * 10000 + month * 100 + day;

	return date;
}

int falling_time(int distance) {
	// distance = 0.5 * g * t^2
	// t = sqrt(2 * distance / g)
	int time = sqrt(2 * distance / GRAVITY_ACCEL);
	return time;
}

double hypotenuse(double side1, double side2) {
	//hypotenuse = sqrt(side1^2 + side2^2)
	double hyp = sqrt(side1 * side1 + side2 * side2);
	return hyp;
}

int sum_even(int n) {
	// sum of even numbers from 1 to n
	int sum = 0;
	for (int i = 2; i <= n; i += 2) {
		sum += i;
	}
	return sum;
}

double sum_partial_harmonic(int n) {
	// sum of the first n terms of the harmonic series
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += 1.0 / i;
	}
	return sum;
}

int population_growth(int start, double rate, int target) {
	int years = 0;
	// start * (1 + rate)^years = target
	while (start < target) {
		start *= 1 + rate / 100.0;
		years++;
	}
	return years;
}
