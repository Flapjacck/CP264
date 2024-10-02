/**
 * -------------------------------------
 * @file  movie.h
 * movie Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef MOVIE_H_
#define MOVIE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Constants
#define MIN_RATING 0
#define MAX_RATING 10
#define FIRST_YEAR 1888
#define MAX_STRING 80

// Reference to GENRES array.
extern const char *const GENRES[];
extern const int GENRES_COUNT;

// movie data structure
typedef struct {
    char title[MAX_STRING];
    char director[MAX_STRING];
    int year;
    int genre;
    float rating;
} movie_struct;

/**
 * Initializes a movie object.
 *
 * @param source - pointer to a movie structure
 * @param title - title string, size MAX_STRING
 * @param year - year of release
 * @param director - director string, size MAX_STRING
 * @param genre - index representing movie genres
 * @param rating - rating of 0 - 10 from IMDB
 */
void movie_init(movie_struct *source, const char *title, int year, const char *director, int genre, float rating);

/**
 * Copies contents of one movie to another.
 *
 * @param source - pointer to movie to copy from
 * @param target - pointer to movie to copy to
 */
void movie_copy(const movie_struct *source, movie_struct *target);

/**
 * Compares two movies. Movies are compared first by title, then by year.
 *
 * @param source - pointer to movie structure
 * @param target - pointer to movie structure
 * @return - 0 if source == target, < 0 if source < target, > 0 if source > target.
 */
int movie_compare(const movie_struct *source, const movie_struct *target);

/**
 * Prints the contents of a movie formatted as:
 *
 * Title:    title of movie
 * Year:     year of movie
 * Director: director of movie
 * Genres:   genre of movie
 * @param source - pointer to movie structure
 */
void movie_print(const movie_struct *source);

/**
 * Creates a formatted string of movie key data.
 * Consists of the movie title and year in the format
 * "title, year".
 *
 * @param str - pointer to string
 * @param max_length - maximum length of str; should be at least
 * max length of title string + room for year
 * @param source - pointer to movie structure
 * @return - pointer to str parameter
 */
char* movie_key(char *str, size_t max_length, movie_struct *source);

/**
 * Prints all genres in the GENRES array. Use for input menus
 * as in get_movie().
 */
void genres_menu();

#endif /* MOVIE_H_ */
