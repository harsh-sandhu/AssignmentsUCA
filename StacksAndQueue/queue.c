/*
 * Queue Implementation in C using Arrays
 *
 * Compilation: gcc -o queue queue.c
 * execution: ./queue
 *
 * @Harsh Sandhu, 1911981371, 03/08/2021
 *
 */

#include <stdio.h>

//Initializing the array queue and head and tail varibles
int N=10;
int queue[10];
int head=0;
int tail=-1;

//Function to add element to queue
//Time-Complexity: O(1)
void enqueue(int value){

    //if queue is full
    if(tail==N){
        printf("Queue is Full\n");
	return;
    }

    //add the element to array queue
    queue[++tail]=value;
}

//Function to remove element from queue
//Time-Complexity: O(number_of_element_in_queue) ( Worst case: O(N) )
int dequeue(){

    //check if queue is empty
    if(tail<head){
        printf("Queue is Empty\n");
	return 0;
    }

    //storing the top element
    int ele=queue[head];

    //left shifting the whole array
    for(int i=0;i<tail;i++){
        queue[i]=queue[i+1];
    }
    
    //deleting the head element
    queue[tail]=0;
    tail--;

    //returning the element deleted
    return ele;
}

//function to return head of queue
//Time-Complexity: O(1)
int peek(){

    //checking for queue is empty
    if(tail<head){
        printf("Queue is Empty\n");
	return 0;
    }

    return queue[head];
}

//Function to check if queue is empty
//Time-Complexity: O(1);
int is_empty(){
    return tail<head?1:0;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",is_empty());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",is_empty());
    printf("%d\n",dequeue());

}
