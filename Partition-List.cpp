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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next){
            return head;
        }
        ListNode * small= new  ListNode(-1);
        ListNode * Big= new ListNode (-1);
        ListNode * s= small;
        ListNode * b = Big;
        ListNode * temp = head;
        while(temp!=nullptr ){
         if(temp->val<x){
            s->next = temp;
            s= s->next;
            temp = temp->next;
            
         }
         else{
            b->next=temp;
            b= b->next;
            temp=temp->next;
            
         }
        }
        b->next = nullptr;
        s->next = Big->next;
        return small->next;
        

    }
};