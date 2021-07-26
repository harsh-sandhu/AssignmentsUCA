/*
 * Program to analize Bubble sort
 *
 * Compilation: gcc assignment2 assignment2.c
 * execution: ./assignment2
 *
 * @Harsh Sandhu, 1911981371, 26/07/21
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaring the function to swap data at given indexs in array
void swap(int* arr,int i,int j);

int main(){
    int n,type=0;

    //Input for size of input data
    printf("Enter the size of input, eg: 8000, 12000, 16000...32000\n");
    scanf("%d",&n);
    
    //Input for type of input data
    printf("Enter the type of inputs you want:\n");
    printf("1 for random inputs\n");
    printf("2 for sorted data\n");
    printf("3 for sorted data in reverse\n");
    scanf("%d",&type);

    int data[n];
    //setting up of data according to type
    if(type==1){
	//random input data
        for(int i=0;i<n;i++){
	    data[i]=rand()%n;
	}
    }else if(type==2){
	//sorted data
        for(int i=0;i<n;i++){
	    data[i]=i+1;
	}
    }else if(type==3){
	//sorted data in reverse
        for(int i=0;i<n;i++){
	    data[i]=n-i;
	}
    }else{
        printf("WRONG INPUTS....program terminated...\n");
    }

    //setting up clock variable
    clock_t t;

    //time before the bubble sort
    t=clock();

    //bubble sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
	    
	    //swapping the data at j and j+1
	    swap(data,j,j+1);
	}
    }

    //after the bubble sort
    t=clock()-t;

    //converting the time to seconds
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    
    //printing the time taken
    printf("time taken:%lf\n",time_taken);
    return 0;

}

//function to swap values at two given indexes in array
void swap(int* arr,int i,int j){
    
    //swapping without using the third variable
    arr[i]=arr[i]+arr[j];
    arr[j]=arr[i]-arr[j];
    arr[i]=arr[i]-arr[j];
}
