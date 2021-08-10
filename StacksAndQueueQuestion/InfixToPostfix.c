/*
 * program to change Infix expression to postfix expression
 *
 * Compilation: gcc -o infixToPostfix InfixToPostfix.c
 * execution: ./infixToPostfix
 *
 * @Harsh Sandhu, 1911981371, 10/08/2021
 */
#include <stdio.h>

//<----------STACK IMPLEMENTATION---------->

//define the stack
#define N 100
char stack[100];
int top=-1;

//push into the stack
void push(char ch){
    stack[++top]=ch;
}

//pop element from stack
void pop(){
    stack[top]=0;
    top--;
}

//peek the top of the stack
char peek(){
    return stack[top];
}

//check if stack is empty
int is_empty(){
    return top==-1?1:0;
}

//declaring the function to convert infix to postfix expression
void infixToPostfix(char* str);

//declaring the function to return precedence
int prec(char ch);

int main(){

    //declaring the string for infix expression
    char str[N];

    //Input for the string
    printf("Enter the infix expression\n");
    fgets(str,N,stdin);

    //convert into postfix expression
    infixToPostfix(str);

    //print the postfix expression
    printf("%s\n",str);

    return 0;
}

//function to return precedence
int prec(char ch){

    //return the values for precedence
    if(ch=='*'||ch=='/'){
        return 2;
    }else if(ch=='+'||ch=='-'){
        return 1;
    }else{
        return 0;
    }
}

//function to covert infix to postfix
void infixToPostfix(char* str){

    //declaring a temporary string
    char postfix[N];
    int k=0;

    //iterating through the string
    for(int i=0;str[i]!='\0'&&str[i]!='\n';i++){
	
	//if character is a number, add it to the temporary string
        if(str[i]>='0'&&str[i]<='9'){
	    postfix[k++]=str[i];
	}else if(str[i]=='('){
            //if there is opening parenthesis, push it to stack
	    push('(');
	}else if(str[i]==')'){
	    //if character is closing parentheses, pop until opening parenthesis
	    while(!is_empty()&&peek()!='('){
	    	postfix[k++]=peek();
		pop();
	    }
	    //pop the opening parenthesis 
	    pop();

	}else{
	    //if character is a arthmatic operator

	    //pop from stack until precedence of top of stack is greater then precedence of operator
	    while(!is_empty()&&prec(peek())>=prec(str[i])){
	    	postfix[k++]=peek();
		pop();
	    }

	    //push the operator in the stack
	    push(str[i]);
	}
    }

    //pop until stack is empty
    while(!is_empty()){
        postfix[k++]=peek();
	pop();
    }
    
    int i;
    //put the temporary string to main string
    for(i=0;postfix[i]!='\0';i++){
        str[i]=postfix[i];
    }
    str[i]='\0';
}
