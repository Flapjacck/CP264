/**
 * -------------------------------------
 * @file  movie_utilities.c
 * Assignment 2 movie_utilities Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "movie_utilities.h"

void get_movie(movie_struct *source) {

	// your code here
	// Prompt the user for the movie's title, director, year, and genre
	printf("Title: ");
	scanf("%s", source->title);

	printf("Year: ");
	scanf("%d", &(source->year));

	printf("Director: ");
	scanf("%s", source->director);

	genres_menu();
	printf("Genre: ");
	scanf("%d", &(source->genre));

	printf("Rating: ");
	scanf("%f", &(source->rating));
}
void read_movie(movie_struct *source, const char *line) {

	// your code here
	// Read the movie's title, year, director, rating, and genre from the line
	sscanf(line, "%[^|]|%d|%[^|]|%f|%d", source->title, &(source->year),
			source->director, &(source->rating), &(source->genre));

}

void read_movies(movie_array_struct *movies, FILE *fp) {

	// your code here
	// Read all the movies from the file and store them in the movies array
	char line[MOVIES_INIT];
	movies->capacity = MOVIES_INIT;

	while (fgets(line, MOVIES_INIT, fp) != NULL) {
		read_movie(&movies->items[movies->count], line);
		movies->count++;
	}

}
