/*
 * Program to Rotate a Linked List
 *
 * Compilation: gcc rotateLinkedList.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 28/08/2021
 *
 * Solution Link: https://leetcode.com/submissions/detail/545253154/ */

/* LeetCode */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL||k==0){
        return head;
    }
    struct ListNode* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    k=k%len;
    if(k==0){
        return head;
    }
    temp=head;
    int count=0;
    struct ListNode* newhead=NULL;
    while(temp->next!=NULL){
        count++;
        if(count==len-k){
            newhead=temp->next;
            temp->next=NULL;
            temp=newhead;
        }else{
            temp=temp->next;
        }
    }
    //printf("%d",newhead->val);
    temp->next=head;
    return newhead;
}
