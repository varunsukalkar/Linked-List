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
    ListNode* mergeTwoLists(ListNode* List1, ListNode* List2) {
     if(List1==nullptr){
        return List2;
     }
     if(List2==nullptr){
        return List1;
     }
        ListNode * dnode=new ListNode(-1);
        ListNode * temp = dnode;
        while(List1!=nullptr && List2!=nullptr){

            if(List1->val <= List2->val){
                temp->next = List1;
                temp=temp->next;
                List1=List1->next;

            }
            else{
                temp->next=List2;
                temp=temp->next;
                List2=List2->next;
            }


        }
        if(List1){
            temp->next=List1;
        }
        else
        {
            temp->next=List2;
        }
        return dnode->next;
    
    }
};