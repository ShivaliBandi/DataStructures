/*
LEETCODE:206. Reverse Linked List

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(!head || !head->next) return head;
      struct  ListNode *ans=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return ans;

}
