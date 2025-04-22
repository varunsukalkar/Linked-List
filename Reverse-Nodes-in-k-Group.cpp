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

    ListNode * reverse(ListNode * head){
        ListNode * temp = head;
        ListNode * curr=head;
        ListNode * prev = nullptr;
        while(curr!=nullptr){
            ListNode* newll = curr->next;
            curr->next= prev;
            prev=curr;
            curr=newll;
        }
        return prev;
    }
    

  ListNode *   getkthnode(ListNode * temp,int k){
        k-=1;
        while(temp!=nullptr  && k>0){
        
            temp=temp->next;
            k--;
        }
        return temp;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp=head;
        ListNode * prevhead= nullptr;
        while(temp!=nullptr){
            ListNode *kthnode =getkthnode(temp,k);
            if(kthnode ==nullptr){
                if(prevhead){
                    prevhead->next=temp;
                }
                    break;
                


            }
            ListNode * newNode = kthnode->next;
            kthnode ->next = nullptr;
            reverse(temp);
            if(temp==head){
                head=kthnode;
            }else{
            prevhead->next = kthnode;
            }
            prevhead = temp;
            temp=newNode;
        }
       return head;
    }
};