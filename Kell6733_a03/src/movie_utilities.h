/**
 * -------------------------------------
 * @file  movie_utilities.h
 * movie_utilities Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef MOVIE_UTILITIES_H_
#define MOVIE_UTILITIES_H_

#include "movie.h"

#define MOVIES_INIT 24

// movies data structure
typedef struct {
    int capacity;                    // current capacity of the movies array.
    int count;                       // count of movies in array.
    movie_struct items[MOVIES_INIT]; // array of data items.
} movie_array_struct;

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

/**
 * Reads the contents of a file of movie strings into an array. Must update capacity field
 * to MOVIES_INIT, and count field to number of movies actually read. count cannot
 * exceed capacity.
 *
 * @param movies - data structure to store multiple movies
 * @param fp - pointer to a file of movie data
 */
void read_movies(movie_array_struct *movies, FILE *fp);

#endif /* MOVIE_UTILITIES_H_ */
