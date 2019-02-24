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
 * @file Statistical analysis
 * @brief Does some analysis on databases
 *
 * <Add Extended Description Here>
 *
 * @author Mahmoud Saad
 * @date   October 4th, 2018
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)




int main2() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int   maximum, minimum, mean, median;

  /* Statistics and Printing Functions Go Here */
  printf("The original array is:\n\n");
  print_array(test, SIZE);
  sort_array(test, SIZE);
  printf("\nThe sorted array is:\n\n");
  print_array(test, SIZE);
  mean    = find_mean    (test, SIZE);
  median  = find_median  (test, SIZE);
  maximum = find_maximum (test, SIZE);
  minimum = find_minimum (test, SIZE);
  print_statistics(mean, maximum, minimum, median);

 return 0;


}

/* Add other Implementation File Code Here */

void print_array (unsigned char array[], int length){
#ifdef VERBOSE
	int i;
	for(i = 0; i < length; i++){
		PRINTF("%d ", array[i]);
	}
    PRINTF("\n");
#endif
};

float find_median (unsigned char array[], int length){

	float median=0;

    // if number of elements are even
    if(length%2 == 0)
        median = (array[(length-1)/2] + array[length/2])/2.0;
    // if number of elements are odd
    else
        median = array[length/2];

    return median;

};

float find_mean (unsigned char array[], int count){
  int i;
  int sum =0 ;

  for(i = 0; i < count; ++i){

    sum += array[i];

  }
  int avg = sum /count;
  return (avg);
};

int find_maximum (unsigned char numbers[], int length){
    int max = 0, i = 0 ;
    while ( i < length ){
    if ( i == 0 ) {
      max = numbers[0];    // Must initialize to values in set, not zero
    }


    if ( numbers[i] >= max){
      max = numbers[i];
    }
    i++;
    }

    return(max);
    };

int find_minimum (unsigned char numbers[], int length){
    int min = 0, i = 0;
    while ( i < length ){
    if ( i == 0 ) {
      min = numbers[0];    // Move to second item and start comparisons
    }

    if ( numbers[i] <= min){
      min = numbers[i];
    }
    i++;
    }


    return (min);
    };

int sort_array ( unsigned char array[], int length){
	int i, j, a;
    for (i = 0; i < length; ++i)
    {
        for (j = i + 1; j < length; ++j)
        {
            if (array[i] < array[j])
            {
                a = array[i];
                array[i] = array[j];
                array[j] = a;
            }
        }
    }
return 0;
};

void print_statistics(int mean, int maximum, int minimum, int median){
  printf( "\nThe average is: %d\n", mean );
  printf( "\nThe maximum is: %d\n", maximum  );
  printf( "\nThe minimum is: %d\n", minimum  );
  printf( "\nThe median is: %d\n", median  );

};
