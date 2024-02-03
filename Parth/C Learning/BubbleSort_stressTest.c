#include <stdio.h>


int size;


void sortInc(int *arr);
void swap(int *a , int *b);


void main()
{
    size = 698017;
    int arr[ size ];

    
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = size - i ;
    }


    //Invoking Sorting Function
    sortInc(arr);


    //Printing the sorted Array
    printf("\nSorted Array :  ");
    for(int i = 0; i < size ; i++)
    {
        printf("%d " , arr[i] );
    }

    printf("\n\n");

}

//Pass an array address and this will sort the Array itself
void sortInc(int *arr)
{
    
    int *tem ;
    tem=arr;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0 ; j < size-i ; j++)
        {
            
            if( *arr > *(arr + 1) )
            {
                swap(arr , (arr+1));
            }
            arr++;
        }
        arr=tem; 
    }
}

//To Swap 2 integers
void swap(int *a , int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
