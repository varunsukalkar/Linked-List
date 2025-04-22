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
    ListNode* deleteDuplicates(ListNode* head) {
    
    ListNode * dummy = new ListNode (0);
    ListNode * follow= dummy;
    ListNode * temp = head;
      
    while(temp!=nullptr){
        if(temp->next!=nullptr && temp->next->val==temp->val){
            int val = temp->val;
            while(temp!=nullptr && temp->val == val){
                temp= temp->next;
            }
        }
        else{
            follow->next = temp;
            follow=follow->next;
            temp= temp->next;
        }

    }
     follow->next=nullptr;
    return dummy->next;

    }
};