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
 * @date 11/11/2020 
 *
 */


#include <stddef.h>
#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/* Add other Implementation File Code Here */
void sort_array(unsigned char *array, int size){
  int i,j,aux;
  for(i=0; i<size; i++){
    for(j=0; j<(size-1); j++){
      if(*(array+j) >  *(array+j+1)){
        aux = *(array+j);
        *(array+j) = *(array+j+1);
        *(array+j+1) = aux; 
      } 
    } 
  }
}

unsigned char find_minimum(unsigned char *array){
  return (*array);
}

unsigned char find_maximum(unsigned char *array, int size){
  return (*(array+(size-1)));
}

float find_mean(unsigned char *array, int size){
  int i, total = 0;
  for(i=0; i<size; i++)
    total = total + *(array+i);

  return (total/size);
}

unsigned char find_median(unsigned char *array, int size){
  return (*(array + ((size/2)-1)));
}

void print_array(unsigned char *array, int size){
  int i;
  #if !defined (VERBOSE) && defined (HOST)
  #undef PRINTF
  #define PRINTF(...)
  #endif
  PRINTF("The array is:\n[");
  for(i=0; i<size; i++)
    PRINTF("%d ",*(array+i));
  PRINTF("]\n");
  #if defined (VERBOSE) && defined (HOST)
  #undef PRINTF
  #define PRINTF(...) printf(__VA_ARGS__)
  #endif
}


void print_statistics(unsigned char *array, int size){
  sort_array(array,size);
  printf("\n\nThe minimum value is: %d", find_minimum(array));
  printf("\n\nThe maximum value is: %d", find_maximum(array,size));
  printf("\n\nThe mean is: %.2f", find_mean(array,size));
  printf("\n\nThe median value is: %d", find_median(array,size));
  
  printf("\n\nThe array sorting from the largest to smallest");

  int i;
  printf("\n[");
  for(i=0; i<size;i++){
    printf("%d ",*(array+(size-1)-i));
  }
  printf("]");
}
