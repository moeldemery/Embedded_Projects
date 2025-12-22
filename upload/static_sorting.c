
/********************************************************
 * Author 	: Eldemery										*
 * Version	: V01										*
 * Data		: 7 Jan 2020								*
 *******************************************************/



#include <stdio.h>
#include "static_sorting.h"







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
               *(arr+i)=*(arr+i)^*(arr+j);
               *(arr+j)=*(arr+i)^*(arr+j);
               *(arr+i)=*(arr+i)^*(arr+j);
            }
        }
    }
}

void selection_sort(int arr[],int size)
{
    int min=0;
	int i;
    for( i=0 ; i<size;i++)
    {
    	int j;
        for( j = 0 ; j<size ; j--)
        {
            if(j>min)
            {
                min=j;
            }
        }
        arr[min]=arr[min]^arr[i];
        arr[i]=arr[min]^arr[i];
        arr[min]=arr[min]^arr[i];
    }
}
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
                arr[i]=arr[i]^arr[j];
                arr[j]=arr[i]^arr[j];
                arr[i]=arr[i]^arr[j];
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
        int pivo = partation(&arr,0,6);
        //quik_sort(&arr,start ,pivo-1);
        //quik_sort(&arr,pivo+1 , end);
    }
}

void print_arr(int arr[],int size)
{
	int i;
     for( i=0 ; i<size;i++)
    {
        printf(" %d" , arr[i]);
    }
}
