/*
 * program that implements stack using queue
 *
 * @Harsh Sandhu, 1911981371, 10/08/2021
 * 
 * leetCode Submission: https://leetcode.com/submissions/detail/536176912/
 */

#include <stdio.h>

typedef struct {
    int* queue1;
    int* queue2;
    int head1;
    int head2;
    int tail1;
    int tail2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* pt=(MyStack*)malloc(sizeof(MyStack));
    pt->head1=0;
    pt->head2=0;
    pt->tail1=-1;
    pt->tail2=-1;
    pt->queue1=(int*)malloc(sizeof(int)*10);
    pt->queue2=(int*)malloc(sizeof(int)*10);
    
    return pt;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->queue1[++obj->tail1]=x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int i;
    for(i=0;i<obj->tail1;i++){
        obj->queue2[i]=obj->queue1[i];
    }
    obj->tail2=i-1;
    int ans=obj->queue1[i];
    obj->queue1[i]=0;
    for(i=0;i<=obj->tail2;i++){
        obj->queue1[i]=obj->queue2[i];
        obj->queue2[i]=0;
    }
    obj->tail2=0;
    obj->tail1--;
    return ans;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int i;
    for(i=0;i<obj->tail1;i++){
        obj->queue2[i]=obj->queue1[i];
    }
    obj->tail2=i-1;
    int ans=obj->queue1[i];
    for(i=0;i<=obj->tail2;i++){
        obj->queue1[i]=obj->queue2[i];
        obj->queue2[i]=0;
    }
    obj->tail2=0;
    return ans;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
  return obj->tail1==-1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
