/*
 * Program to implement queue using Linked list
 *
 * Compilation: gcc queue.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 28/08/2021
 *
 */

#include <stdlib.h>
#include <stdio.h>
//<-----------QUEUE NODES----------->

//Node for Integer Queue
struct Node{
    int data;
    struct Node* next;
    struct Node* end;
    int length;
};
typedef struct Node Node;

//<-------------------------------->


//<------------------CONSTRUCTION OF QUEUE------------------->


//Function to construct queue;
Node* constructQueue(){
    Node* head=(Node*)malloc(sizeof(Node));
    head->data=-1;
    head->length=-1;
    head->next=NULL;
    head->end=NULL;
}

//<--------------------------------------------------------->


//<--------------------ENQUEUE IN THE QUEUE------------------------>


//Function to push into Queue
void enqueueBack(Node* head,int val){

    //if queue is empty
    if(head->length==-1){
    	head->data=val;
	head->length=1;
	head->end=head;
	return;
    }

    //Intializing memory for queue element
    Node* newNode=(Node*)malloc(sizeof(Node));

    //assigning at the front
    newNode->data=val;
    newNode->next=NULL;
    head->end->next=newNode;
    head->end=newNode;

    //increase length of queue
    head->length+=1;
}

//Function to push into Integer Stack
void enqueueFront(Node* head,int val){

    //if stack is empty
    if(head->length==-1){
    	head->data=val;
	head->length=1;
	head->end=head;
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


//<----------------------DEQUEUE FROM THE QUEUE--------------------------->



//Function to dequeue from Queue
void dequeueFront(Node* head){

    //if queue is empty
    if(head->length==-1){
    	printf("ERROR: Queue is Empty\n");
	return;
    }

    //if queue has only one element
    if(head->next==NULL){
    	head->data=-1;
	head->length=-1;
	head->end=head;
	return;
    }

    //removing the element at front
    head->data=head->next->data;
    Node* todelete=head->next;
    head->next=head->next->next;

    //free the unusable memory
    free(todelete);

    //decrease length of queue
    head->length-=1;

}

//<------------------------------------------------------------->


//<-------------------PEEK THE QUEUE------------------------->


//Function to get front element of Integer Queue
int peekFront(Node* head){

    //if queue at empty
    if(head->length==-1){
    	printf("ERROR: Queue is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->data;

}

//Function to get front element of Integer Queue
int peekBack(Node* head){

    //if queue at empty
    if(head->length==-1){
    	printf("ERROR: Queue is Empty\n");
	exit(1);
    }
     
    //if queue has only one element
    if(head->length==1){
    	return head->data;
    }
    //return top element of stack
    return head->end->data;

}
//<------------------------------------------------------->


//<---------------------STACK IS EMPTY------------------------->


//Function which returns if stack is empty or not
int is_empty(Node* head){
    return head->length>0?0:1;
}

//<------------------------------------------------------------>


int main(){
	Node* head;
	head=constructQueue();
	enqueueFront(head,1);
	enqueueBack(head,2);
	enqueueBack(head,3);
	enqueueFront(head,4);
	enqueueFront(head,5);

	while(!is_empty(head)){
		printf("%d %d\n",peekFront(head),peekBack(head));
		dequeueFront(head);
	}
}
