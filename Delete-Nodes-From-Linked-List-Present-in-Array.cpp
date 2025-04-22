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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      
      unordered_set<int> s(nums.begin(), nums.end());
       ListNode * dummy=new ListNode(0);
       ListNode * follow = dummy;
       ListNode * temp = head;
       while(temp!= nullptr ){
        if(s.find(temp->val)!=s.end()){
            temp = temp->next;
        }
        else{
            follow->next = temp;
            follow= follow->next;
            temp = temp->next;
        }
        
       }
       follow->next=nullptr;
       return dummy->next;
    }
};