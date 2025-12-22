
/********************************************************
 * Author 	: Eldemery									*
 * Version	: V01										*
 * Data		: 7 Jan 2020								*
 *******************************************************/



#include <stdio.h>
#include "static_sorting.h"




/** Bubble_sort()/Bubble_sort_pointer()
 * sorting using bubble algorithm
 * @Algo     by comparing the value on selected element with the rest of the elements
 *           then repeating the process with all the elements in the array
 * 	O(n^2)
 * @param  {integer *}  arr[]  Pointer to the first number in array need to be sort
 * @param  {integer}    size   The size of the array
 * @return {void}
 */

void Bubble_sort(int arr[],int size)
{
	int i;
    for( i=0 ; i<size;i++)
    {
    	int j;
        for( j = i+1 ; j<size ; j++)
        {
            if(arr[j]<arr[i])
            {
				//swapping 2 variables using xoring
                arr[i]=arr[i]^arr[j];
                arr[j]=arr[i]^arr[j];
                arr[i]=arr[i]^arr[j];
            }
        }
    }
}
//this is the same function as Bubble_sort() but with pointers (for illustration only)
void Bubble_sort_pointer(int *arr,int size)
{
	int i;
    for( i=0 ; i<size;i++)
    {
    	int j;
        for( j = i+1 ; j<size ; j++)
        {
            if(*(arr+j)<*(arr+i))
            {
				//swapping 2 variables using xoring
               *(arr+i)=*(arr+i)^*(arr+j);
               *(arr+j)=*(arr+i)^*(arr+j);
               *(arr+i)=*(arr+i)^*(arr+j);
            }
        }
    }
}

/** selection_sort()
 * sorting using selection algorithm
 * @Algo    by selecting a min value after looping on all list
 *          then if min not the same with last sorted item it swaps
 *  O(n^2)
 * @param  {integer *}  arr[]  Pointer to the first number in array need to be sort
 * @param  {integer}    size   The size of the array
 * @return {void}
 */

void selection_sort(int arr[],int size)
{
    int min=0;
	int i;
    for( i=0 ; i<size;i++)
    {
    	int j;
    	min=i;
        for( j = i+1 ; j<size ; j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min != i)
        {
            arr[min]=arr[min]^arr[i];
            arr[i]=arr[min]^arr[i];
            arr[min]=arr[min]^arr[i];
        }

    }
}

/** insertion_sort()
 * sorting using insertion algorithm
 * @Algo    by selecting a min value after looping on all list
 *          then if min not the same with last sorted item it swaps
 *  O(n^2)
 * @param  {integer *}  arr[]  Pointer to the first number in array need to be sort
 * @param  {integer}    size   The size of the array
 * @return {void}
 */
void insertion_sort(int arr[],int size)
{
    int sorted=1;
    int i;
    for( i=1 ; i<size;i++)
    {
        sorted=i;
        int j;
        for( j = i ; j>=0 ; j--)
        {
            if(arr[j]>arr[sorted])
            {
                arr[sorted]=arr[sorted]^arr[j];
                arr[j]=arr[sorted]^arr[j];
                arr[sorted]=arr[sorted]^arr[j];
                sorted--;
            }
        }
    }

}

int partation(int arr[], int start, int end)
{
    int pivot=arr[(end+start)/2];
    int i=-1;
    int j;
    for(j=start;j<=end-1;j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            arr[i]=arr[i]^arr[j];
            arr[j]=arr[i]^arr[j];
            arr[i]=arr[i]^arr[j];
        }
    }
    arr[i+1]=arr[i+1]^arr[end];
    arr[end]=arr[i+1]^arr[end];
    arr[i+1]=arr[i+1]^arr[end];


    //printf("\n\n%d",i+1);
    return (i+1);
}
void quik_sort(int arr[] , int start , int end)
{
    if(end>start)
    {
        int pivo = partation(arr,0,6);
        quik_sort(arr,start ,pivo-1);
        quik_sort(arr,pivo+1 , end);
    }
}


//-------------------------------------------------------

void print_arr(int arr[],int size)
{
	int i;
	printf("the sorted list is :");
     for( i=0 ; i<size;i++)
    {
        printf(" %d" , arr[i]);
    }
}

void scan_arr(int arr[],int size)
{
    int i;
	for( i=0;i<size;i++)
    {
        printf("enter n# %d  :",i);
        scanf("%d",&arr[i]);
    }

}

