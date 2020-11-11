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



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_array(test,SIZE);
  print_statistics(test,SIZE);
  printf("\n\n");
}

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
  printf("The array is:\n[");
  for(i=0; i<size; i++)
    printf("%d ",*(array+i));

  printf("]");
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
