/*
 * program to find GCD of of two number using recurtion
 *
 * Compilation: gcc -o gcd gcd.c
 * execution: ./gcd
 *
 * @Harsh Sandhu, 1911981371, 03/08/21
 *
 */
#include <stdio.h>

//Declaring a function to find gcd of two numbers
int gcd(int a,int b);

int main(){
    //the two numbers
    int n1,n2;

    //Input for the two numbers
    printf("Enter the first number\n");
    scanf("%d",&n1);

    printf("Enter the second number\n");
    scanf("%d",&n2);

    //printing the gcd of two numbers
    printf("GCD of %d, %d = %d\n",n1,n2,gcd(n1,n2));
}

//function to find gcd of two numbers using Euclid Algorithm
int gcd(int a,int b){
    
    //swapping elements first element is bigger than second	
    if(a>b){
        int temp=a;
	a=b;
	b=temp;
    }

    //Terminating statement    
    if(a%b==0){
        return b;
    }

    //recursivly calling function
    return gcd(a,b%a);

}
