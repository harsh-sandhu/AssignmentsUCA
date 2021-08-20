/*
 * Program to print n numbers in Fibonacci series that are even
 *
 * compilation: gcc Fibonacci.c
 * execution: ./a.out
 * 
 * @Harsh Sandhu, 1911981371, 20/08/2021
 */

#include <stdio.h>

//Declaring function for printing first n even Fibonacci numbers
void fibEven(int no_of_elements);

int main(){
    //the no_of_elements
    int nEle;

    //Input for no_of_elemets
    printf("Enter the Number of Elements\n");
    scanf("%d",&nEle);

    //calling the function
    printf("First %d Even Elements in Fibonacci series\n",nEle);
    fibEven(nEle);
}

//function for printing first n even Fibonacci numbers
void fibEven(int no_of_elements){
    //declaring initial variables
    int n1=0,n2=2;

    //using n3=4*n2+n1;
    while(no_of_elements--){
    	printf("%d ",n2);
	int temp=4*n2+n1;
	n1=n2;
	n2=temp;
    }
    printf("\n");
}
