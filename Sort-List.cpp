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
    ListNode * getmiddle(ListNode * head){
        if(head== nullptr || head->next == nullptr){
        return head;
        }
        ListNode * fast = head->next;
        ListNode * slow= head;
        while(fast!= nullptr && fast->next!= nullptr){
             fast = fast->next->next;
             slow= slow->next;
        }
        return slow;
    }


    ListNode * merge(ListNode * left1 ,ListNode * right1){
         ListNode * dummy = new ListNode (-1);
         ListNode * temp = dummy;
         ListNode * left = left1;
         ListNode * right = right1;
         while( left != nullptr && right != nullptr){
            if(left->val<right->val){
                temp->next = left;
                temp = temp->next;
                left= left->next;
            }
            else{
                temp ->next = right;
                temp = temp->next;
                right = right ->next;

            }

         }
            if(left){
                temp->next = left;
            }
            else{
                temp->next = right ;

            }
         return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode * middle= getmiddle(head);
          ListNode * left = middle->next;
           middle->next = nullptr;
           ListNode * right = head;

           left  = sortList(left);
           right = sortList(right );
           return merge(left,right);


    }
};