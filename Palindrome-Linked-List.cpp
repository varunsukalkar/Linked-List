/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast=fast->next->next;
            slow = slow->next;

        }
        ListNode * curr =slow;
        ListNode * prev = nullptr;
         while(curr!= nullptr){
            ListNode * temp = curr->next;
            curr->next = prev;
            prev= curr;
            curr=temp;
         }
         ListNode * start = head;
         while(start!= nullptr && prev!= nullptr){
            if(start->val != prev->val ){
                return false;
            }
            start=start->next;
            prev=prev->next;
         }
           return true;
    }
};