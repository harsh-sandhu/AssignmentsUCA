/*
 * Largest Rectangle in Histogram
 *
 * @Harsh Sandhu, 1911981371, 16/07/2021
 *
 * LeetCode Link:https://leetcode.com/submissions/detail/539978596/
 */

#include <stdio.h>

int N=100000;
int stack[100000];
int top=-1;

//<----------STACK IMPLEMENTATION----------->

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

int largestRectangleArea(int* arr, int n){
    int v[100000];
    int maximum=0;
    for(int i=0;i<n;i++){
        while(!is_empty()&&arr[peek()]>=arr[i]){
            pop();
        }
        v[i]=is_empty()?i+1:i-peek();
        push(i);
    }
    while(!is_empty()){
        pop();
    }
    for(int i=n-1;i>=0;i--){
       while(!is_empty()&&arr[peek()]>=arr[i]){
            pop();
        }
        int temp=arr[i]*(v[i]-1+(is_empty()?n-i:peek()-i));
        if(maximum<=temp){
            maximum=temp;
        }
        push(i);
    }
    return maximum;
}


//main function
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    }
    printf("%d\n",largestRectangleArea(arr,n));
    return 0;
}
