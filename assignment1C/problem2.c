/*
 * program to print a pyramid having the given number of steps
 *
 * Compilation: gcc -o print_pyramid problem2.c
 * execution: ./print_pyramid
 *
 * @Harsh Sandhu, 1911981371, 23/07/2021
 * */

#include <stdio.h>

int main(){
    //the number of steps
    int steps;

    //Input for the steps
    printf("Enter the number od steps for pyramid\n");
    scanf("%d",&steps);

    //---pyramid logic---
    
    //outer loop which iterates into the rows
    //here number of rows are equal to the steps

    for(int i=1;i<=steps;i++){

	//inner loop-1 is for adding spaces as we need
	//to to make pyramid 
	//number of spaces will be (steps-i+1)
	
	for(int j=i;j<=steps;j++){
	    printf(" ");
	}

	//inner loop-2 is for adding pyramid tiles(elements)
	//number of element in current steps(row) = i
	
        for(int j=1;j<=i;j++){
	    printf("# ");
	}

	//printing nextline to separate rows(steps)
	printf("\n");
    }

    return 0;
}
