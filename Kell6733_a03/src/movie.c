/**
 * -------------------------------------
 * @file  movie.c
 * movie Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "movie.h"

// Array of strings for movie genres.
const char *const GENRES[] = {"science fiction", "fantasy", "drama", "romance", "comedy", "zombie", "action",
        "historical", "horror", "war", "mystery"};

// Calculates size of GENRES array.
const int GENRES_COUNT = sizeof GENRES / sizeof *GENRES;

void movie_init(movie_struct *source, const char *title, int year, const char *director, int genre, float rating) {
    assert(year >= FIRST_YEAR);
    assert(rating >= MIN_RATING && rating <= MAX_RATING);

    // your code here

}

void movie_copy(const movie_struct *source, movie_struct *target) {

    // your code here

}

int movie_compare(const movie_struct *source, const movie_struct *target) {

    // your code here

    return 0;
}

void movie_print(const movie_struct *source) {

    // your code here

}

char* movie_key(char *str, size_t max_length, movie_struct *source) {

    // your code here

    return str;
}

void genres_menu() {

    // your code here

}
