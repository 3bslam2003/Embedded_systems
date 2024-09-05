#include <stdio.h>
#define Size        6

/**
 * Function to print array elements.
 *
 * @arr     Integer array to print.
 * @size    Size of array.
 */
void printArray(int *arr, int size)
{
	for(int i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	// Add Your Code Here
}

void main(void)
{
	int Swap_array [Size]={100,200,300,400,500,600};
	int Arr_Rev[Size] ;
	
	printf ("\n--------------------------\n");
	/*
	// another solution without using second array to reverse //
	int*ptr_start;
	int *ptr_end;
	for(int start=0,end=Size-1;start<(Size/2)&&end>(Size/2)-1;start++,end--){
		Swap_array[start]=Swap_array[start]^Swap_array[end];
		Swap_array[end]=Swap_array[start]^Swap_array[end];
		Swap_array[start]=Swap_array[start]^Swap_array[end];
	}
	*/
	for(int i=0,j=Size-1;i<Size&&j>=0;i++,j--){
		Arr_Rev[i]=Swap_array[j];
	}
	printArray(Arr_Rev,Size);
	
	
	printf ("\n--------------------------\n");
	
}
