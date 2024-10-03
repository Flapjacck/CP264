/**
 * -------------------------------------
 * @file  movie.c
 * movie Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-09-28
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
	//pointers to the strings in the struct so we can copy the strings
	target->year = source->year;
	target->genre = source->genre;
	target->rating = source->rating;

}

int movie_compare(const movie_struct *source, const movie_struct *target) {

	// your code here
	// Compare the titles of the two movies
	int title_comparison = strcmp(source->title, target->title);

	// If the titles are the same, compare the years
	if (title_comparison == 0) {
		return source->year - target->year;
	}

	// Otherwise, return the result of the title comparison
	return title_comparison;

}

void movie_print(const movie_struct *source) {

	// your code here
	// Print the title, year, director, rating and genre of the movie
	assert(source != NULL);

	printf("Title:    %s\n", source->title);
	printf("Year:     %d\n", source->year);
	printf("Director: %s\n", source->director);
	printf("Genres:   %s\n", GENRES[source->genre]);
	printf("Rating:   %.1f\n", source->rating);

}

char* movie_key(char *str, size_t max_length, movie_struct *source) {

	// your code here
	if (str == NULL || source == NULL) {
		return NULL;
	}

	// Format the string as "title, year"
	snprintf(str, max_length, "%s, %d", source->title, source->year);

	return str;

}

void genres_menu() {

	// your code here
	int i;
	for (i = 0; i < GENRES_COUNT; i++) {
		printf("%d. %s\n", i, GENRES[i]);
	}

}
