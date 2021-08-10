/*
 * program to Balanced Parentheses,checks whether the sequence of brackets in the given string is balanced or not
 *
 * Compilation: gcc -o balancedParentheses BalancedParentheses.c
 * execution: ./balancedParentheses
 *
 * @Harsh Sandhu, 1911981371, 10/08/2021
 */
#include <stdio.h>

//<-------STACK IMPLEMENTATION------->

//define stack
#define N 100
char stack[100];
int top=-1;

//push function for stack
void push(int data){
    stack[++top]=data;
}

//pop function for stack
void pop(){
    stack[top]=0;
    top--;
}

//peek function for stack
char peek(){
    return stack[top];
}

//check if stack is empty
int is_empty(){
    return top==-1?1:0;
}

//<-------BALANCED PARENTHESES FUNCTION------->

//Declaring function to balanced parentheses
int balancedParentheses(char* str);

int main(){

    //declaring a string(Character array)
    char str[N];

    //Input for the string
    printf("Enter the Parentheses String\n");
    fgets(str,N,stdin);


    int balanced=balancedParentheses(str);

    //print answer
    if(balanced){
        printf("true\n");
    }else{
        printf("false\n");
    }

    return 0;
}

//function to balance parentheses
int balancedParentheses(char* str){

    //iterate through the string
    for(int i=0;str[i]!='\0';i++){

	//if character is end line then break
	if(str[i]=='\n'){
	    break;
	}

	//if character is open bracket then push it in stack 
        if(str[i]=='('){
	    push(str[i]);
	}
	else if(str[i]=='{'){
	    push(str[i]);
	}
	else if(str[i]=='['){
	    push(str[i]);
	}else{
	    //if character is closing bracket and matches opening bracket of the top character in the stack
	    if((str[i]=='}'&&peek()=='{')||(str[i]==')'&&peek()=='(')||(str[i]==']'&&peek()=='[')){
		pop();
	    }else{
	    	pop();
		//if brackets dont match return false;
		return 0;
	    }
	}
    }

    //if stack becomes empty, that means every parentheses is balanced, return true;
    if(is_empty()){
    	return 1;
    }

    //return false;
    return 0;
}
