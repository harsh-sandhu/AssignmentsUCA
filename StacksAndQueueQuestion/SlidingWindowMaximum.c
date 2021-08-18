/*
 *Program of Sliding Window Maximum
 *
 * Compilation: gcc SlidingWindowMaximum
 * execution: ./a.out
 *
 * @Harsh Sandhu , 1911981371, 18/08/2021
 */

#include <stdio.h>
#include <stdlib.h>

//<---------------DEQUEUE IMPLEMENTATION---------------->
int MAX=1000;
int deque[1000];
int front=-1;
int rear=-1;

int isFull(){
    if ( (front==0 && rear==MAX-1) || (front==rear+1) )
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if( front == -1)
        return 1;
    else
        return 0;
}
void push_front(int item)
{
    if( isFull() )
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if( front==-1 )
    {
        front=0;
        rear=0;
    }
    else if(front==0)
        front=MAX-1;
    else
        front=front-1;
    deque[front]=item ;
}

void push_back(int item)
{
    if( isFull() )
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if(front==-1)
    {
       front=0;
       rear=0;
    }
    else if(rear==MAX-1)
       rear=0;
    else
        rear=rear+1;
    deque[rear]=item ;
}

void delete_front(){
    if( isEmpty() )
    {
        printf("\nQueue Underflow\n");
        return;
    }
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        if(front==MAX-1)
           front=0;
        else
           front=front+1;
}

void delete_back()
{
    if( isEmpty() )
    {
       printf("\nQueue Underflow\n");
       return;
    }

    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(rear==0)
        rear=MAX-1;
    else
        rear=rear-1;
}

int show_front(){
    if( isEmpty() )
    {
        printf("\nQueue Underflow\n");
        return -1;
    }
    return deque[front];
}

int show_back(){
    if( isEmpty() )
    {
        printf("\nQueue Underflow\n");
        return -1;
    }
    return deque[rear];
}

//Sliding Window Maximum Function
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int j=0;
    int *ans;
    *returnSize = (numsSize - k + 1);
    ans = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i=0;i<k;i++){
        while(isEmpty()==0&&nums[show_back()]<nums[i]){
            delete_back();
        }
        push_back(i);
    }
    ans[j++]=nums[show_front()];
    for(int i=k;i<numsSize;i++){
        if(show_front()==i-k){
            delete_front();
        }
        while(isEmpty()==0&&nums[show_back()]<nums[i]){
            delete_back();
        }
        push_back(i);
        ans[j++]=nums[show_front()];
    }
    return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
	    scanf("%d",&arr[i]);
	}
	int k;
	scanf("%d",&k);
	int size;
	int *ans=maxSlidingWindow(arr,n,k,&size);
	for(int i=0;i<size;i++){
	   printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
