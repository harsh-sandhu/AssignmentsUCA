/*
 * Program to sort elements with Selection sort Recursivly
 *
 * Compilation: gcc -o selection_sort selectionSort.c
 * execution: ./selection_sort
 *
 * @Harsh Sandhu, 1911981371, 03/08/21
 *
 */
#include <stdio.h>

//Declaring function to sort using Selection sort
void selectionSort(int arr[],int n,int i);

//Declaring function to find index of minmum element
int minIndex(int arr[],int x,int y);

//Declaring a function to swap elements of array
void swap(int arr[],int i,int j);

int main(){
    //the size
    int n;

    //Input for size
    printf("Enter the size of array you want to sort\n");
    scanf("%d",&n);

    //declaring the array of the given size
    int arr[n];

    //Input for the arr
    printf("Enter the %d elements for the array\n",n);
    for(int i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    }

    //calling the function to sort
    selectionSort(arr,n,0);

    //printing the array
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }printf("\n");
}

//function to sort using selection sort
void selectionSort(int arr[],int n,int i){
    
    //Terminating statement
    //if reached the end of array, return
    if(i==n){
        return;
    }

    //find the minimum element index in array
    int min_index=minIndex(arr,i,n-1);

    //swap the values at current and minimum index
    swap(arr,min_index,i);

    //calling the function recursivly for next index
    selectionSort(arr,n,i+1);
}

//Function to fint minimum index
int minIndex(int arr[],int x,int y){

    //termination statement
    if(x==y){
        return x;
    }

    //go through the whore array to find minimum element index
    int min_index=minIndex(arr,x+1,y);

    //return the minumum index(checking between current and found minimum index)
    return (arr[x]<arr[min_index])?x:min_index;
}

//Function to swap elements in array
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
