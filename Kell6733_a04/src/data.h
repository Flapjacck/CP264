/**
 * -------------------------------------
 * @file  data.h
 * data Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 * UPDATE COMMENTS AS APPROPRIATE
 */
#ifndef DATA_H_
#define DATA_H_

#define BOOL_TO_STR(bool_var) (bool_var) ? "true" : "false"

#include "int_data.h"

// defines 'data_type' as an alias to some other type.
typedef int data_type;

#define data_copy(x, y) int_copy(x, y)
#define data_print(x) int_print(x)
#define data_compare(x, y) int_compare(x, y)
#define data_string(x, y, z) int_string(x, y, z)

/*
 #include "movie.h"

 // defines 'data_type' as an alias to some other type.
 typedef movie_struct data_type;

 #define data_copy(x, y) movie_copy(x, y)
 #define data_print(x) movie_print(x)
 #define data_compare(x, y) movie_compare(x, y)
 */

#endif /* DATA_H_ */
