
#include "static_sorting.h"


void main()
{
    int a[MAX_SIZE];
    int flag=0;
    int size = (sizeof(a)/sizeof(a[0]));
    for(int i=0;i<MAX_SIZE;i++)
    {
        scanf("%d",&a[i]);
    }

    Bubble_sort_pointer(&a,size);
    //insertion_sort(&a,size);
    //quik_sort(&a,0,size-1);
    print_arr(&a,size);


}
