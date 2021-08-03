/*
 * program to print movement along with count of movements in Tower of Hanoi
 *
 * Compilation: gcc -o tower_of_hanoi towerOfHanoi.c
 * execution: ./tower_of_hanoi
 *
 * @Harsh Sandhu , 1911981371, 03/08/21
 *
 */
#include <stdio.h>

//Declaring the function to print movement and count of movement in tower of Hanoi
void tower_of_hanoi(int n, char from, char to, char aux);

int main(){

    //number of disc
    int n;

    //Input for number of disc
    printf("Enter the number of discs\n");
    scanf("%d",&n);

    //calling towerOfHanoi function for given number of discs
    tower_of_hanoi(n,'A','C','B');
}

//function to print movement and count of movement in tower of Hanoi
void tower_of_hanoi(int n,char from, char to, char aux){
    
    //variable to keep count of movements
    static int m=1;

    //termination statement
    if(n==0){
	return;
    }

    //move disc from initial disc to auxilary disc
    tower_of_hanoi(n-1,from,aux,to);

    //prints the movement number with the movement
    printf("%d. %c to %c\n",m++,from,to);

    //move the disc from auxilary disc to final disc
    tower_of_hanoi(n-1,aux,to,from);
}
