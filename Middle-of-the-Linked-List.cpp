class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<int>>pq;
        priority_queue<int,vector<int>,greater<int>>pq1;
        for(int i = 0; i< n; i++){
            pq.insert{hand[i]};

        }
        int a = pq.top();
        pq.pop();
        while(pq.size()!=0){
            if(a+1==pq.top()){
                a=a+1;
                
            }
        }

    }
};