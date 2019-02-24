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
 * @file  Module of the code
 * @brief function declarations to include in header
 *
 * it defines 7 functions which are used in statistical analysis
 *
 * @author Mahmoud Saad
 * @date   October 10, 2018
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */
void print_array (unsigned char array[], int length);
/**
 * @brief prints array
 *
 * prints each element with spaces in between
 *
 * @param array[]         the array itself
 * @param length          length of array
 * @param
 * @param
 *
 * @return
 */

/* Add Your Declarations and Function Comments here */
float find_median (unsigned char array[], int length);
/**
 * @brief finds median
 *
 * sorts elements and if odd number picks the middle if even, divide the 2 middle elements to get median
 *
 * @param array[]         the array itself
 * @param length          length of array
 * @param
 * @param
 *
 * @return returns median
 */

/* Add Your Declarations and Function Comments here */
float find_mean (unsigned char array[], int count);
/**
 * @brief finds mean
 *
 * adds all elements and dividies by their number
 *
 * @param array[]         the array itself
 * @param length          length of array
 * @param
 * @param
 *
 * @return mean
 */

/* Add Your Declarations and Function Comments here */
int find_maximum (unsigned char numbers[], int length);
/**
 * @brief finds maximum
 *
 * stores first value in varable then replace it with any higher value
 *
 * @param array[]         the array itself
 * @param length          length of array
 * @param
 * @param
 *
 * @return maximum
 */

/* Add Your Declarations and Function Comments here */
int find_minimum (unsigned char numbers[], int length);
/**
 * @brief finds minimum
 *
 * stores first value in vaiable then replaces it with any lower value
 *
 * @param array[]         the array itself
 * @param length          length of array
 * @param
 * @param
 *
 * @return minimum
 */

/* Add Your Declarations and Function Comments here */
int sort_array ( unsigned char array[], int length);
/**
 * @brief sorts array
 *
 * <Add Extended Description Here>
 *
 * @param array[]         the array itself
 * @param length          length of array
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

/* Add Your Declarations and Function Comments here */
void print_statistics(int mean, int maximum, int minimum, int median);
/**
 * @brief sorts array
 *
 * <Add Extended Description Here>
 *
 * @param array[]         the array itself
 * @param length          length of array
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */


#endif /* __STATS_H__ */

