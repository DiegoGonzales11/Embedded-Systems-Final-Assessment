/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief This program give you some tools
 *         to analyze a data set
 *
 * Here you should get some important parameters from the
 * data set:
 *  -maximum
 *  -minimum
 *  -mean
 *  -median
 * 
 *
 * @author Pool Diego Gonzales Loayza
 * @date 26/06/2020 
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Show on screen some parameters from the data set
 *
 * This function takes as an input a unsigned char pointer
 * from the array and also an integer number. It will print
 * the median, mean, maximum and minumum values from the
 * given array. Also, the function print all the array but 
 * with the values from the largest to the smallest
 *
 * @param array    It's a pointer from the data set 
 * @param size     It's the length of the data set
 *
 * @return The function returns nothing
 */
void print_statistics(unsigned char *array, int size);

/**
 * @brief Show on screen all the values from the data set
 *
 * This function takes as an input a unsigned char pointer
 * from the array and also an integer number. It will print
 * all the values from the data set
 *
 * @param array    It's a pointer from the data set 
 * @param size     It's the length of the data set
 *
 * @return The function returns nothing
 */
void print_array(unsigned char *array, int size);

/**
 * @brief Sort all the elements from the data set
 *
 * This function takes as an input a unsigned char pointer
 * from the array and also an integer number. It will sort 
 * all the elements from low to high
 *
 * @param array    It's a pointer from the data set 
 * @param size     It's the length of the data set
 *
 * @return The function returns nothing
 */
void sort_array(unsigned char *array, int size);

/**
 * @brief Give the minimum value from the data set
 *
 * This function takes as an input a unsigned char pointer
 * from the array. It will return
 * the minimum value from the data set
 *
 * @param array    It's a pointer from the data set 
 *
 * @return The function return an unsigned char
 */
unsigned char find_minimum(unsigned char *array);

/**
 * @brief Give the maximum value from the data set
 *
 * This function takes as an input a unsigned char pointer
 * from the array and also an integer number. It will return
 * the maximum value from the data set
 *
 * @param array    It's a pointer from the data set 
 * @param size     It's the length of the data set
 *
 * @return The function return an unsigned char
 */
unsigned char find_maximum(unsigned char *array, int size);
 
/**
 * @brief Give the mean value from the data set
 *
 * This function takes as an input a unsigned char pointer
 * from the array and also an integer number. It will return
 * the mean value from the data set
 *
 * @param array    It's a pointer from the data set 
 * @param size     It's the length of the data set
 *
 * @return The function return a float number
 */
float find_mean(unsigned char *array, int size);

/**
 * @brief Give the median value from the data set
 *
 * This function takes as an input a unsigned char pointer
 * from the array and also an integer number. It will return
 * the median value from the data set
 *
 * @param array    It's a pointer from the data set 
 * @param size     It's the length of the data set
 *
 * @return The function return an unsigned char
 */
unsigned char find_median(unsigned char *array, int size);

#endif /* __STATS_H__ */
