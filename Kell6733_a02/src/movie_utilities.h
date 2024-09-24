/**
 * -------------------------------------
 * @file  movie_utilities.h
 * Assignment 2 movie_utilities Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-09-13
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef MOVIE_UTILITIES_H_
#define MOVIE_UTILITIES_H_

#include "movie.h"

/**
 * Initializes a movie structure from a line of formatted string data.
 *
 * @param source - pointer to a movie structure
 * @param line - delimited string of movie data.
 */
void read_movie(movie_struct *source, const char *line);

/**
 * Reads a movie object from the keyboard.
 *
 * @param source - pointer to a movie structure
 */
void get_movie(movie_struct *source);

#endif /* MOVIE_UTILITIES_H_ */
