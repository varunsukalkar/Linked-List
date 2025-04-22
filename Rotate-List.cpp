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
  
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * tail=head;
        int lenght =1;
        while(tail->next!=nullptr){
            tail=tail->next;
            lenght ++;
        }
        
        int rotate=k%lenght;
        if(rotate==0){
            return head;
        }
           tail->next=head;
        int j = lenght-k-1;
        ListNode * temp= head;
        while(j!=0){
            temp=temp->next;
            j--;
        }
        head=temp->next;
        temp->next =nullptr;
        return head;

    }
};