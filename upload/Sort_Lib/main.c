/********************************************************
 * Author 	: Eldemery									*
 * Version	: V03										*
 * Data		: 7 Jan 2020								*
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "static_sorting.h"

/*
    this is a test code for static_sorting_library
    using code blocks IDE
*/

int main()
{
        /*this is the array being sorted of size predefined */
    int Local_int_TestArray[5];

        /*calculating the size of array by dividing the size of whole array on size of single element*/
    int size = (sizeof(Local_int_TestArray)/sizeof(Local_int_TestArray[0]));

    scan_arr(Local_int_TestArray,size);             /*scan array from user*/

    //Bubble_sort_pointer(Local_int_TestArray,size);
    selection_sort(Local_int_TestArray,size);
    //insertion_sort(a,size);
    //quik_sort(&a,0,size-1);

     print_arr(Local_int_TestArray,size);

    return 0;

}
