/*
 *Program to swap two variable without using third variable
 * 
 * Compilation: gcc -o swap_variables problem1.c
 * execution: ./swap_variables
 *
 * @Harsh Sandhu, 1911981371, 23/07/2021 
 * */

#include <stdio.h>

int main(){
    //the two number a and b
    int a,b;

    //Input for the a and b
    printf("Enter the first number(a)\n");
    scanf("%d",&a);

    printf("Enter the second number(b)\n");
    scanf("%d",&b);

    //the swaping of variables without using the third varible
    a=a+b;
    b=a-b;
    a=a-b;

    printf("a = %d, b = %d\n",a,b);

    return 0;
}
