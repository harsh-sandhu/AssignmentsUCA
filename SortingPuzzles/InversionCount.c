/*
 * Program to find number of inversions in array
 *
 * Compilation: gcc InversionCount.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 13/08/2021
 */

#include <stdio.h>

//Declaring a function to count inversions
int count_inversion(int arr[],int n);

int main(){
    //the number of element in array
    int n;

    //input for number of elements
    printf("Enter the number of elements\n");
    scanf("%d",&n);

    //the array
    int arr[n];

    //input for array
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    }

    //computing and printing the inversion count
    printf("Inversion Count = %d\n",count_inversion(arr,n));

}

//function to print number of inversions
int count_inversion(int arr[],int n){
    
    //Intializing a count varible as zero to keep count of inversions
    int count=0;

    //iterating through array
    for(int i=0;i<n;i++){
	//iterating through indexes bigger than i
    	for(int j=i+1;j<n;j++){

	    //inversion condition
	    if(arr[i]>arr[j]){
	    	count++;
	    }
	}
    }

    //returning the number of inversions
    return count;

}
