#include <stdio.h>


int size;


void sortInc(int *arr);
void swap(int *a , int *b);


void main()
{
    //Prompt user to enter Array
    printf("Enter Array size : ");
    do//To get proper input validating the input by user(here- size)
    {
        scanf("%d" , &size );
    }
    while (size<=0);
    int arr[ size ];


    //Array input...
    printf("Array size : %d\n" , size );
    printf("Enter Array Elements one by one or all at once with space in between : \n");
    for(int i = 0; i < size ; i++)
    {
        scanf("%d" , &arr[i] );
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
