/*
 * Program to analize Insertion sort
 *
 * Compilation: gcc insertionSort InsertionSort.c
 * execution: ./insertionSort
 *
 * @Harsh Sandhu, 1911981371, 26/07/21
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaring the function which returns time taken to sort data using insertion sort
void insertionSort(int arr[],int n);

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

    //random data insertion sort time
    printf("Time taken in Random data\n");
    insertionSort(data1,n);

    //sorted data insertion sort time
    printf("Time taken in Already Sorted data\n");
    insertionSort(data2,n);

    //sorted data in reverse insertion sort time
    printf("Time taken in reverse sorted data\n");
    insertionSort(data3,n);
    
    return 0;

}

//function insertion sort(prints time taken);
void insertionSort(int arr[], int n)
{
    clock_t t;
    int i, key, j;
    t=clock();
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("%lf sec\n",time_taken);
}
