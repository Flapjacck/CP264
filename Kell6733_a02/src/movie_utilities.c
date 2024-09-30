/**
 * -------------------------------------
 * @file  movie_utilities.c
 * Assignment 2 movie_utilities Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-09-13
 *
 * -------------------------------------
 */
#include "movie_utilities.h"

void get_movie(movie_struct *source) {

	// your code here
	// Prompt the user for the movie's title, director, year, and genre
	printf("Enter movie title: ");
	scanf("%s", source->title);

	printf("Enter movie director: ");
	scanf("%s", source->director);

	printf("Enter movie year: ");
	scanf("%d", &(source->year));

	printf("Enter movie genre: ");
	scanf("%d", &(source->genre));

	printf("Enter movie rating: ");
	scanf("%f", &(source->rating));
}

void read_movie(movie_struct *source, const char *line) {

	// your code here
	// Read the movie's title, year, director, rating, and genre from the line
	sscanf(line, "%[^|]|%d|%[^|]|%f|%d", source->title, &(source->year),
			source->director, &(source->rating), &(source->genre));

}
