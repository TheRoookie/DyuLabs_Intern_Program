#include <stdio.h>



void bubble_Sort(int *arr);
void printArray(int *array ,int size);


void bubble_Sort(int *arr , int size)
{
    int temp;
    for (int i = 0; i < size -1 ; i++)
    {
        for (int j = i+1; j < size ; j++)
        {
            
            if( arr[i] > arr[j] )
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j]= temp;

            }
            
        }
        
    }
}


void printArray(int* array, int size)
{
    for(int i=0; i<size ;i++)
    {
        printf("%d ",array[i]);
    }
}


void main()
{
    int size;
    
    //prompt user to enter Array
    printf("Enter Array size : ");

    //to get valid size(non-negetive and greater than zero)
    do
    {
        scanf("%d" , &size );
    }
    while (size<=0);
    
    int arr[ size ];
    
    //taking array input
    printf("Array size : %d\n" , size );
    printf("Enter Array Elements one by one or all at once with space in between : \n");
    for(int i = 0; i < size ; i++)
    {
        scanf("%d" , &arr[i] );
    }


    //invoking sorting function
    bubble_Sort(arr ,(sizeof(arr)/sizeof(arr[0])));


    //printing the sorted Array
    printf("\nSorted Array :  ");
    printArray(arr ,(sizeof(arr)/sizeof(arr[0]))); 

    printf("\n\n");

}


