/*
 * program to print Mth smallest element
 *
 * Compilation: gcc MthSmallestElement.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 20/08/2021
 *
 */

#include <stdio.h>

//<---------------Implementation of QQuick Sort----------------->


// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int arr[], int l, int r) {
  
  int pivot = arr[r];
  
  int i=(l-1);

  for (int j = l; j < r; j++) {
    if (arr[j] <= pivot){  
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[r]);
  
  return (i + 1);
}

void quickSort(int arr[], int l, int r) {
  if (l < r) {
    
    int pi = partition(arr, l, r);
    
    quickSort(arr, l, pi - 1);
    
    quickSort(arr, pi + 1, r);
  }
}

// main function
int main() {
    //the number of element
    int n;

    //Input for n
    printf("Enter the number of Elements for Array\n");
    scanf("%d",&n);

    //the array
    int arr[n];

    //input for array
    printf("Enter the array\n");
    for(int i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    }

    //the Mth element;
    int m;
    printf("Enter the Mth position\n");
    scanf("%d",&m);

    quickSort(arr,0,n-1);

    //printing the Mth smallest Element
    printf("The %dth smallest Element is\n",m);
    printf("%d\n",arr[m-1]);

    return 0;
}
