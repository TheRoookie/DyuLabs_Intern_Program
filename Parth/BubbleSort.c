#include <stdio.h>
#include <stdbool.h>


#define NUM_MAX 50000
int arr[ NUM_MAX ];


void sortInc(int *arr);
void swap(int *a , int *b);


void main()
{
    
    for(int i = 0; i < NUM_MAX ; i++)
    {
        //arr[i] = NUM_MAX - i ;
        arr[i] = rand() % 2001 ;
    }
    sortInc(arr);
    printf("From Left : \n");
    for(int i = 0; i < 5 ; i++)
    {
        printf("%d\n" , arr[i] );
    }
    printf("From Right : \n");
    for(int i = NUM_MAX; i > NUM_MAX - 5 ; i--)
    {
        printf("%d\n" , arr[i] );
    }

}
void sortInc(int *arr)
{
    
    int *tem ;
    tem=arr;
    for (int i = 0; i < NUM_MAX; i++)
    {
        for (int j = 0 ; j < NUM_MAX-i ; j++)
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
void swap(int *a , int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
