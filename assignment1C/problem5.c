/*
 * program to multiply two given matrices
 *
 * Compilation: gcc matrix_multipication problem5.c
 * execution: ./matrix_multipication
 *
 * @Harsh Sandhu, 1911981371, 23/07/2021
 */

#include <stdio.h>

//Decalring the function for matrix multipication
void multiply_matrix(int size,int matrix1[size][size],int matrix2[size][size]);

int main(){
    //declaring the size
    int size;

    //Input for the size
    printf("Enter the size for your matrices\n");
    scanf("%d",&size);

    //declaring the two matrices
    int matrix1[size][size];
    int matrix2[size][size];

    //input for the matrices
    printf("Enter the first matrix\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
	    scanf("%d",&matrix1[i][j]);
	}
    }

    printf("Enter the second matrix\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
	    scanf("%d",&matrix2[i][j]);
	}
    }

    //mutliping the two matrices
    multiply_matrix(size,matrix1,matrix2);

    return 0;
}

//Function for multiping two matrices
void multiply_matrix(int size,int matrix1[size][size],int matrix2[size][size]){
    
    //Declaring a product matrix	
    int product[size][size];

    //---Multipication---
    
    //iterating over row of first matrix
    for(int i=0;i<size;i++){
	//iterating over column of second matrix
        for(int j=0;j<size;j++){
	
	    //setting the initial value to 0
	    product[i][j]=0;

	    //iterating over column of first matrix or row of second matrix
	    //(for multipication column of first matrix = row of second matrix) 
	    for(int k=0;k<size;k++){
	        product[i][j]+=(matrix1[i][k]*matrix2[k][j]);
	    }
	}
    }

    //print the product matrix
    printf("The product matrix after multipling two matrices is\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
	    printf("%d ",product[i][j]);
	}
	printf("\n");
    }
}
