/*
 * Program to return the node where cycle begin, if cycle exists
 *
 * Compilation: gcc cycleInList.c
 * execution: ./a.out
 *
 * @Harsh Sandhu, 1911981371, 28/08/2021
 *
 * Solution Link: https://leetcode.com/submissions/detail/545247457/ */

/* LeetCode */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            fast=head;
            while(fast!=slow){
                slow=slow->next;
                fast=fast->next;
            }
            return fast;
        }
    }
    return NULL;
}
