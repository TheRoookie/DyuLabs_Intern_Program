#include <stdio.h>


void mergeSort(int *array , int cSize );
void merge(int* leftArr ,int* rightArr , int* arr , int leftSize , int rightSize);
void printArray(int *array ,int size);

 
void mergeSort(int* array , int cSize )
{
    // printf("Passed in array = %ld\n" , cSize );
    //sleep(2);
    if( cSize <=1){return;}//Terminating condition
    int mid = cSize / 2;
    int leftArr[mid];
    //printf("Mid size = %d\n" , mid );
    int rightArr[cSize-mid];
    int i = 0;
    int j = 0;
    for(  ;  i<cSize  ;  i++)
    {
        if(i<mid)
        {
            leftArr[i] = array[i];
        }
        else
        {
            rightArr[j]  = array[i];
            j++;
        }
    }
    
    mergeSort(leftArr , mid );
    mergeSort(rightArr , cSize-mid );
    

    merge( leftArr , rightArr , array , mid , cSize-mid ) ;
    

    
}
void merge(int* leftArr ,int* rightArr , int* array , int leftSize , int rightSize)
{
    
    //printf("Size of left array passed in merge!%d\n" , (sizeof(leftArr)/sizeof(leftArr[0])) );
    
	int i = 0, l = 0, r = 0;

	//check the conditions for merging
	while(l < leftSize && r < rightSize) 
    {
		if(leftArr[l] < rightArr[r]) 
        {
			array[i] = leftArr[l];
			i++;
			l++;
		}
		else 
        {
			array[i] = rightArr[r];
			i++;
			r++;
		}
	}
	while(l < leftSize) 
    {
		array[i] = leftArr[l];
		i++;
		l++;
	}
	while(r < rightSize)
    {
		array[i] = rightArr[r];
		i++;
		r++;
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
    //prompt user to enter Array
    int size;
    printf("Enter Array size : ");
   
    //to get valid size(non-negetive and greater than zero)
    do  
    {
        scanf("%d" , &size );
    }
    while(size<=0);
    
    int array[ size ];

    //printitng size of entered Array
    printf("Array size : %ld\n" , ( sizeof(array)/sizeof(array[0]) ) ); 

    //taking array input
    printf("Enter Array Elements one by one or all at once with space in between : \n");
    for(int i = 0; i < size ; i++)
    {
        scanf("%d" , &array[i] );
    }

    //invoking sorting function
    mergeSort(array , ( sizeof(array)/sizeof(array[0]) ) );

    //printing the sorted Array
    printf("\nSorted Array :  ");
    printArray(array ,( sizeof(array)/sizeof(array[0]) ) );
    
    printf("\n\n");

}
