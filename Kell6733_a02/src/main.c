/*
 -------------------------------------------------------
 File:    main.c
 Project: movie
 file description
 -------------------------------------------------------
 Author:  David Brown
 ID:      999999999
 Email:   dbrown@wlu.ca
 Version: 2017-06-20
 -------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "movie.h"
#include "movie_utilities.h"

#define SEP "-------------------------------------------\n"
#define YEAR 1998
#define GENRE 0
#define RATING 7.8
#define SIZE 20
#define MOVIES_CAPACITY 24

const char *TITLE = "Dark City";
const char *DIRECTOR = "Alex Proyas";
const char *MOVIE = "Zulu|1964|Cy Endfield|7.8|9";
const char *TEST_FILE = "movies.txt";

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    printf("Test: genres_menu()\n\n");
    genres_menu();
    printf(SEP);
    printf("Test: movie_init(&source, \"%s\", %d, \"%s\", %d, %.1f)\n\n", TITLE, YEAR, DIRECTOR, GENRE, RATING);
    movie_struct source;
    movie_init(&source, TITLE, YEAR, DIRECTOR, GENRE, RATING);
    printf("Test: movie_print(source):\n\n");
    movie_print(&source);
    printf(SEP);
    printf("Test: movie_copy(&source, &target):\n\n");
    movie_struct target;
    movie_copy(&source, &target);
    printf(SEP);
    printf("Test: movie_print(&target):\n\n");
    movie_print(&target);
    printf(SEP);
    printf("Test: read_movie(&source, \"%s\"):\n\n", MOVIE);
    read_movie(&source, MOVIE);
    printf("Test: movie_print(&source):\n\n");
    movie_print(&source);
    printf(SEP);
    printf("Test: result = movie_compare(&source, &source):\n");
    int result = movie_compare(&source, &source);
    printf("result: %d\n", result);
    printf("Test: result = movie_compare(&source, &target):\n");
    result = movie_compare(&source, &target);
    printf("result: %d\n", result);
    printf("Test: result = movie_compare(&target, &source):\n");
    result = movie_compare(&target, &source);
    printf("result: %d\n", result);

    printf(SEP);
    printf("Test: movie_key(&source):\n\n");
    char string[MAX_STRING + 8];
    movie_key(string, MAX_STRING + 7, &source);
    printf("%s\n", string);
    printf(SEP);
    printf("Test: get_movie(&source):\n\n");
    get_movie(&source);
    printf("\n");
    movie_print(&source);
    printf(SEP);
    printf("Test: result = movie_compare(&source, &target):\n");
    result = movie_compare(&source, &target);
    printf("result: %d\n", result);

    return (0);
}
