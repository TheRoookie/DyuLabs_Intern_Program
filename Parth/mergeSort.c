#include <stdio.h>


void mergeSort(int* arr , int cSize );
void merge(int* leftArr ,int* rightArr , int* arr , int leftSize , int rightSize);



int size;

 
void mergeSort(int* arr , int cSize )
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
            leftArr[i] = arr[i];
        }
        else
        {
            rightArr[j]  = arr[i];
            j++;
        }
    }
    
    mergeSort(leftArr , mid );
    mergeSort(rightArr , cSize-mid );
    

    merge( leftArr , rightArr , arr , mid , cSize-mid ) ;
    

    
}
void merge(int* leftArr ,int* rightArr , int* arr , int leftSize , int rightSize)
{
    
    //printf("Size of left array passed in merge!%d\n" , (sizeof(leftArr)/sizeof(leftArr[0])) );
    
	int i = 0, l = 0, r = 0;

    

	
	//check the conditions for merging
	while(l < leftSize && r < rightSize) 
    {
		if(leftArr[l] < rightArr[r]) 
        {
			arr[i] = leftArr[l];
			i++;
			l++;
		}
		else 
        {
			arr[i] = rightArr[r];
			i++;
			r++;
		}
	}
	while(l < leftSize) 
    {
		arr[i] = leftArr[l];
		i++;
		l++;
	}
	while(r < rightSize)
    {
		arr[i] = rightArr[r];
		i++;
		r++;
	}
}
void main()
{
    //Prompt user to enter Array
    printf("Enter Array size : ");
    do//To get proper input validating the input by user(here- size)
    {
        scanf("%d" , &size );
    }
    while(size<=0);
    int arr[ size ];
    printf("Array size : %ld\n" , ( sizeof(arr)/sizeof(arr[0]) ) );

    //Array input...
    
    printf("Enter Array Elements one by one or all at once with space in between : \n");
    
    for(int i = 0; i < size ; i++)
    {
        scanf("%d" , &arr[i] );
    }

    
    //Invoking Sorting Function
    mergeSort(arr , ( sizeof(arr)/sizeof(arr[0]) ) );



    //Printing the sorted Array
    printf("\nSorted Array :  ");
    for(int i = 0; i < size ; i++)
    {
        printf("%d " , arr[i] );
    }

    printf("\n\n");

}