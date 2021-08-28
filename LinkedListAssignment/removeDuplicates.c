/*
 * Program to remove duplicates from a sorted linked list
 *
 * Compilation: gcc removeDuplicates.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 28/08/2021
 *
 * Solution Link: https://leetcode.com/submissions/detail/545210292/ */

/* LeetCode */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL){
        return head;
    }
    struct ListNode* temp=head;
    struct ListNode* prev=NULL;
    while(temp->next!=NULL){
        struct ListNode* t=temp->next;
        if(temp->val==t->val){
            while(t->next!=NULL&&t->val==temp->val){
                t=t->next;
            }
            if(t->val==temp->val){
                if(prev==NULL){
                    head=t->next;
                }else{
                    prev->next=t->next;
                }
                return head; 
            }
            if(prev==NULL){
                head=t;
                temp=t;
            }else{
                prev->next=t;
                temp=prev;
            }
        }else{
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}
