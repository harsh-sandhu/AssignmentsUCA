/* Stack Implementation in C using Arrays
 *
 * Compilation: gcc -o stack stacks.c
 * execution: ./stack
 *
 * @Harsh Sandhu, 1911981371, 03/08/2021
 *
 */

#include <stdio.h>

//Initializing the initial size and the stack array, along with the index
int N=10;
int stack[10];
int top=-1;

//function for resizing the the stack array
//Time-Complexity: O(1)
void resize(){
    printf("Stack Resized...\n");
    //stack size is increased bt 5
    stack[N+5];
    N=N+5;
}

//function to push in the stack
//Time-Complexity: O(1)
void push(int x){

    //resizing the stack if stack limit is reached
    if(top==N-1){
        resize();
    }

    //adding the data into the stack array
    stack[++top]=x;
}

//function to return the top element of stack
//Time-Complexity: O(1)
int peek(){

    //check if stack is empty
    if(top<0){
        printf("Stack is empty\n");
	return 0;
    }
    return stack[top];
}

//function to pop element from the stack
//Time-Complexity: O(1)
int pop(){

    //check if the stack is already empty
    if(top<0){
        printf("Stack is empty\n");
	return 0;
    }
    //storing the top element
    int ele=stack[top];

    //poping the top element
    stack[top]=0;
    top--;

    return ele;
}

//function to check if stack is empty
//Time-Complexity: O(1)
int is_empty(){
    return top<0?1:0;
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    push(110);
    printf("%d\n",peek());
    printf("%d\n",pop());
    printf("%d\n",is_empty());
    printf("%d\n",peek());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",is_empty());
}
