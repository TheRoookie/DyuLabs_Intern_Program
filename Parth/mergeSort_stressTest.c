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
    
    size = 698017;
    int arr[ size ];

    
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = size - i ;
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