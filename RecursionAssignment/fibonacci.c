/*
 * program to print n times the evry third element of fibonacci series
 *
 * Compilation: gcc -o fib fibonacci.c
 * execution: ./fib
 *
 * @Harsh Sandhu, 1911981371, 03/08/2021
 *
 */
#include <stdio.h>

//Declaring the function for printing every third element of fibonacci
void fib(int n);

int main(){

    //number of elements
    int n;

    //Input for the n
    printf("Enter the number of elements\n");
    scanf("%d",&n);

    //printing the n elemnts of fibonnaci(every third element)
    fib(n);
    printf("\n");
}

//function to print n times the every third elements of the fibonacci
void fib(int n){

    //decalring the static elements
    static int a=0,b=1,c,m=1;

    //termination statement
    if(n<1){
       return;
    }

    //getting the next fibonnaci element
    c=a+b;
    a=b;
    b=c;

    //increasing the m
    m++;

    //if every third element
    if(m%3==0){

	//printing the element
        printf("%d ",c);

	//recursivly calling function for the remaining element 
        fib(n-1);

    }else{
	//recurcivly calling the function
        fib(n);
    }
}

