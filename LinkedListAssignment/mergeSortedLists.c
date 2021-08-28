/*
 * Program to merge two sorted linked lists
 *
 * Compilation: gcc mergeSortedLists.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 28/08/2021
 *
 * Solution Link: https://leetcode.com/submissions/detail/545244025/ */

/* LeetCode */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* ans=NULL;
    struct ListNode* head=NULL;
    while(l1&&l2){
        if(l1->val<=l2->val){
            if(ans==NULL){
                ans=l1;
                head=l1;
            }else{
                ans->next=l1;
                ans=ans->next;
            }
            l1=l1->next;
        }else{
            if(ans==NULL){
                ans=l2;
                head=l2;
            }else{
                ans->next=l2;
                ans=ans->next;
            }
            l2=l2->next;
        }
    }
    while(l1){
        if(ans==NULL){
            return l1;
        }
        ans->next=l1;
        l1=l1->next;
        ans=ans->next;
    }
    while(l2){
        if(ans==NULL){
            return l2;
        }
        ans->next=l2;
        l2=l2->next;
        ans=ans->next;
    }
    return head;
}
