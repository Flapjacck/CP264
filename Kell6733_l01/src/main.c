/**
 * -------------------------------------
 * @file  main.c
 * Lab 2 Main Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-05
 *
 * -------------------------------------
 */
#include "functions.h"

/**
 * Test the various parameter handling functions.
 *
 * @param argc - size of argv
 * @param argv - array of strings passed on command line
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);
    parameters(argc, argv);
    return EXIT_SUCCESS;
}
