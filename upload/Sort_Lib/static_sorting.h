/********************************************************
 * Author 	: Eldemery										*
 * Version	: V01										*
 * Data		: 7 Jan 2020								*
 *******************************************************/

/*
*   Static sorting
*   this is a lib used to sort an array of a predefined length
*   using different sorting methods
*   -bubble sorting
*   -selection sorting
*   -insertion sorting
*   -quick sorting
*/

#ifndef 	_STATIC_SORTING_H
#define 	_STATIC_SORTING_H


#define MAX_SIZE 7


void Bubble_sort_pointer(int *arr,int size);
void selection_sort(int arr[],int size);
void insertion_sort(int arr[],int size);
void Bubble_sort(int arr[],int size);
int partation(int arr[], int start, int end);
void quik_sort(int arr[] , int start , int end);

void print_arr(int arr[],int size);
void scan_arr(int arr[],int size);

#endif   //_STATIC_SORTING
