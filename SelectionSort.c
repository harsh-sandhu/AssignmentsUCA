/*
 * Program to analize Selection sort
 *
 * Compilation: gcc selectionSort SelectionSort.c
 * execution: ./selectionSort
 *
 * @Harsh Sandhu, 1911981371, 26/07/21
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaring the function which returns time taken to sort data using selection sort
void selectionSort(int arr[],int n);

//Declaring the function to swap
void swap(int *e1, int *e2);

int main(){
    int n;

    //Input for size of input data
    printf("Enter the size of input, eg: 8000, 12000, 16000...32000\n");
    scanf("%d",&n);

    int data1[n];
    int data2[n];
    int data3[n];

    //random input data
    for(int i=0;i<n;i++){
        data1[i]=rand()%n;
    }
    
    //sorted data
    for(int i=0;i<n;i++){
        data2[i]=i+1;
    }

    //sorted data in reverse
    for(int i=0;i<n;i++){
        data3[i]=n-i;
    }

    //random data selection sort time
    printf("Time taken in Random data\n");
    selectionSort(data1,n);

    //sorted data selection sort time
    printf("Time taken in Already Sorted data\n");
    selectionSort(data2,n);

    //sorted data in reverse selection sort time
    printf("Time taken in reverse sorted data\n");
    selectionSort(data3,n);
    
    return 0;

}

//function selection sort(prints time taken);
void selectionSort(int arr[], int n)
{
    clock_t t;
    t=clock();
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("%lf sec\n",time_taken);
}

//function to swap data
void swap(int *e1, int *e2){
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}
