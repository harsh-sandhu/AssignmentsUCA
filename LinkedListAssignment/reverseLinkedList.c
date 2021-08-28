/*
 * Program to reverse the linked list
 *
 * Compilation: gcc reverseLinkedList.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 28/08/2021
 *
 * Solution Link: https://leetcode.com/submissions/detail/545239703/ */

/* LeetCode */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head, int n, int count, struct ListNode* tailend){
    
    //printf("%d ",count);
    if(count==n||head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode* newHead=reverse(head->next,n,count+1,tailend);
    head->next->next=head;
    if(count==1){
        //printf("called");
        head->next=tailend;
    }else{
        head->next=NULL;
    }
    return newHead;
    
}
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* temp=head;
    int len=0;
    struct ListNode* frontEnd=NULL;
    struct ListNode* tailEnd=NULL;
    while(temp!=NULL){
        len++;
        if(left-1==len){
            frontEnd=temp;
        }
        if(right+1==len){
            tailEnd=temp;
        }
        temp=temp->next;
    }
    if(frontEnd==NULL){
        return reverse(head,right-left+1,1,tailEnd);
    }
    frontEnd->next=reverse(frontEnd->next,right-left+1,1,tailEnd);
    return head;
}
