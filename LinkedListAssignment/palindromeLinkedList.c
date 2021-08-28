/*
 * Program to Check if the given singly linked list is palindrome or not
 *
 * Compilation: gcc palindromeLinkedList.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 28/08/2021
 *
 * Solution Link: https://leetcode.com/submissions/detail/545256956/ */

/* LeetCode */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool palindrome(struct ListNode* head, struct ListNode**headptr){
    if(head==NULL){
        return true;
    }
    if(!palindrome(head->next,headptr))
        return false;
    bool ans=(head->val==(*headptr)->val);
    *headptr=(*headptr)->next;
    return ans;
}
bool isPalindrome(struct ListNode* head){
    return palindrome(head,&head);
}
