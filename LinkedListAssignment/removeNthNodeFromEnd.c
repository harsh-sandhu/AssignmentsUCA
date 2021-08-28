/*
 * Program to remove Nth Node from End of List
 *
 * Compilation: gcc removeNthNodeFromEnd.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 28/08/2021
 *
 * Solution Link: https://leetcode.com/submissions/detail/545214273/ */

/* LeetCode */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    struct ListNode* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    if(len==n){
        head=head->next;
        return head;
    }
    len=len-n+1;
    //printf("%d",len);
    int count=0;
    temp=head;
    while(temp!=NULL){
        count++;
        if(count==len-1){
            break;
        }
        temp=temp->next;
    }
    if(temp->next!=NULL){
        temp->next=temp->next->next;
    }
    return head;
}
