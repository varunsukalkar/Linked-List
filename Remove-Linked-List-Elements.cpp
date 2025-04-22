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
    ListNode* removeElements(ListNode* head, int val) {
         if(head==nullptr){
            return head;
         }
         ListNode * dummy =new ListNode(0);
         ListNode * current = dummy;
         ListNode* temp =head;
         while(temp!=nullptr){
            if(temp->val !=val){
                current->next = temp;
                temp=temp->next;
                current=current->next;



            }
            else{
                temp=temp->next;
            }
         }
            current->next=nullptr;
            return dummy->next;
       
    }
};