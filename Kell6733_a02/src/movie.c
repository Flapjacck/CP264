/**
 * -------------------------------------
 * @file  movie.c
 * Assignment 2 movie Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-09-13
 *
 * -------------------------------------
 */
#include "movie.h"

// Array of strings for movie genres.
const char *const GENRES[] = { "science fiction", "fantasy", "drama", "romance",
		"comedy", "zombie", "action", "historical", "horror", "war", "mystery" };

// Calculates size of GENRES array.
const int GENRES_COUNT = sizeof GENRES / sizeof *GENRES;

void movie_init(movie_struct *source, const char *title, int year,
		const char *director, int genre, float rating) {
	assert(year >= FIRST_YEAR);
	assert(rating >= MIN_RATING && rating <= MAX_RATING);

	// your code here
	strncpy(source->title, title, MAX_STRING);
	source->year = year;
	strncpy(source->director, director, MAX_STRING);
	source->genre = genre;
	source->rating = rating;

}

void movie_copy(const movie_struct *source, movie_struct *target) {

	// your code here
	// Copy each field from the source to the target
	strcpy(target->title, source->title);
	strcpy(target->director, source->director);
	target->year = source->year;
	target->genre = source->genre;
	target->rating = source->rating;

}

int movie_compare(const movie_struct *source, const movie_struct *target) {

	// your code here

}

void movie_print(const movie_struct *source) {

	// your code here

}

char* movie_key(char *str, size_t max_length, movie_struct *source) {

	// your code here

}

void genres_menu() {

	// your code here
	int i;
	for (i = 0; i < GENRES_COUNT; i++) {
		printf("%d. %s\n", i + 1, GENRES[i]);
	}

}
