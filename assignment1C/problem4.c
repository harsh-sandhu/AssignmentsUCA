/*
 * Program to reverse an array
 *
 * Compilation: gcc -o reverse_array problem4.c
 * execution: ./reverse_array
 *
 * @Harsh Sandhu, 1911981371, 23/07/2021
 * */

#include <stdio.h>

//Declaring the function for the reversing the array
void reverse(int *arr,int n);

//declaring a swaping function
void swap(int *arr,int i,int j);

int main(){
    //the length of array (n)
    int n;

    //Input the length of array
    printf("Enter the length of array\n");
    scanf("%d",&n);

    //declaring an array
    int arr[n];

    //Input for array
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    //reverse function of an arr
    reverse(arr,n);

    //printing the array
    printf("[");
    for(int i=0;i<n-1;i++){
        printf("%d, ",arr[i]);
    }
    printf("%d]\n",arr[n-1]);
}

//function for reversing the array passing by reference
void reverse(int *arr,int n){
    //two pointer method to reverse the array
    int i,j;
    for(i=0,j=n-1;i<j;i++,j--){
        swap(arr,i,j);
    }
}

//function to swap values at two indexes in an array
void swap(int *arr,int i,int j){
    //swaping without using third variable
    arr[i]=arr[i]+arr[j];
    arr[j]=arr[i]-arr[j];
    arr[i]=arr[i]-arr[j];
}
