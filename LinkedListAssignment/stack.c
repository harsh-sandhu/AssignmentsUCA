/*
 * Program to implement stack using Linked list
 *
 * Compilation: gcc stack.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 28/08/2021
 *
 */

#include <stdlib.h>

//<-----------STACK NODES----------->

//Node for Integer Stack
struct Node{
    int data;
    struct Node* next;
    int length;
};
typedef struct Node Node;

//<-------------------------------->


//<------------------CONSTRUCTION OF STACK------------------->


//Function to construct Integer Stack
Node* constructStack(){
    Node* head=(Node*)malloc(sizeof(Node));
    head->data=-1;
    head->length=-1;
    head->next=NULL;
}

//<--------------------------------------------------------->


//<--------------------PUSH IN THE STACK------------------------>


//Function to push into Integer Stack
void push(Node* head,int val){

    //if stack is empty
    if(head->length==-1){
    	head->data=val;
	head->length=1;
	return;
    }

    //Intializing memory for stack element
    Node* newNode=(Node*)malloc(sizeof(Node));

    //assigning at the top
    newNode->data=head->data;
    newNode->next=head->next;
    head->next=newNode;
    head->data=val;

    //increase length of stack
    head->length+=1;
}

//<--------------------------------------------------------->


//<----------------------POP FROM THE STACK--------------------------->



//Function to pop from Integer Stack
void pop(Node* head){

    //if stack is empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	return;
    }

    //if stack has only one element
    if(head->next==NULL){
    	head->data=-1;
	head->length=-1;
	return;
    }

    //poping the element at top
    head->data=head->next->data;
    Node* todelete=head->next;
    head->next=head->next->next;

    //free the unusable memory
    free(todelete);

    //decrease length of stack
    head->length-=1;

}

//<------------------------------------------------------------->


//<-------------------TOP OF STACK------------------------->


//Function to get top element of Integer Stack
int top(Node* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->data;

}

//<------------------------------------------------------->


//<---------------------STACK IS EMPTY------------------------->


//Function which returns if stack is empty or not
int is_empty(Node* head){
    return head->length>0?0:1;
}

//<------------------------------------------------------------>
