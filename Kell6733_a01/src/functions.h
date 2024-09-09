/**
 * -------------------------------------
 * @file  functions.h
 * Assignment 1 Functions Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-09-07
 *
 * -------------------------------------
 * DO NOT CHANGE
 */
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Constants.
#define FEET_PER_ACRE 43560.0
#define GRAVITY_ACCEL 9.8   // m/s^2

// Prototypes.

/**
 * Converts square footage to acres.
 * Uses the FEET_PER_ACRE constant.
 *
 * @param square_feet - Area in square feet.
 * @return Square_footage in acres.
 */
double feet_to_acres(int square_feet);

/**
 * Determines how long it takes to mow a rectangular lawn.
 *
 * @param width - width of a lawn in metres.
 * @param length - length of a lawn in metres.
 * @param speed - square metres cut per minute.
 * @return Time required to mow the lawn in minutes.
 */
int mow_lawn(double width, double length, double speed);

/**
 * Converts a date from a date number in the format DDMMYYYY
 * to date number in the format YYYYMMDD.
 *
 * @param date_number - a date number in the format DDMMYYYY.
 * @return a date number in the format YYYYMMDD.
 */
int date_convert(int date_number);

/**
 * Calculates time an object takes to fall a certain distance due to gravity.
 * Uses the GRAVITY_ACCEL constant.
 *
 * @param distance - distance object has fallen in metres.
 * @return time object takes to fall in seconds.
 */
int falling_time(int distance);

/**
 * Calculates the hypotenuse of a right triangle given two other sides.
 *
 * @param side1 - length of first side of a right triangle (>0).
 * @param side2 - length of second side of a right triangle (>0).
 * @return The hypotenuse.
 */
double hypotenuse(double side1, double side2);

/**
 * Sums and returns all even numbers from 2 to n (inclusive).
 *
 * @param n - an integer (> 0).
 * @return The sum.
 */
int sum_even(int n);

/**
 * Sums and returns the total of a partial harmonic series.
 * This series is the sum of all terms 1/i, where i ranges
 * from 1 to n (inclusive).
 * i.e. 1 + 1/2 + 1/3 + ... + 1/n
 *
 * @param n - an integer (> 0).
 * @return The sum.
 */
double sum_partial_harmonic(int n);

/**
 * Calculates the number of years to reach a target population.
 *
 * @param start - starting population (>0).
 * @param rate - percent rate of growth.
 * @param target - target population.
 * @return Years to reach target population.
 */
int population_growth(int start, double rate, int target);

#endif /* FUNCTIONS_H_ */
