#include <stdio.h>
#include <stdlib.h>

int MAX=1000;
int deque[1000];
int front=-1;
int rear=-1;

int isFull()
{
        if ( (front==0 && rear==MAX-1) || (front==rear+1) )
                return 1;
        else
                return 0;
}/*End of isFull()*/

int isEmpty()
{
        if( front == -1)
                return 1;
        else
                return 0;
}/*End of isEmpty()*/
void push_front(int item)
{
        if( isFull() )
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if( front==-1 )/*If queue is initially empty*/
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
        if(front==-1)  /*if queue is initially empty*/
        {
                front=0;
                rear=0;
        }
        else if(rear==MAX-1)  /*rear is at last position of queue */
                rear=0;
        else
                rear=rear+1;
        deque[rear]=item ;
}/*End of insert_rearEnd()*/

void delete_front()
{
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                return;
        }
        if(front==rear) /*Queue has only one element */
        {
                front=-1;
                rear=-1;
        }
        else
                if(front==MAX-1)
                        front=0;
                else
                        front=front+1;
}/*End of delete_frontEnd()*/

void delete_back()
{
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                return;
        }

        if(front==rear) /*queue has only one element*/
        {
                front=-1;
                rear=-1;
        }
        else if(rear==0)
                rear=MAX-1;
        else
                rear=rear-1;
}/*End of delete_rearEnd() */

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
