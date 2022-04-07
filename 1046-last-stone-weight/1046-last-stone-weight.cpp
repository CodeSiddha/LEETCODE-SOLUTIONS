class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        if(stones.size() == 1){
            return stones[0];
        }
        for(int i = 0 ; i < n ; i++){
            pq.push(stones[i]);
        }
        while(!pq.empty() && pq.size() != 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x > y) swap(x , y);
            if(x != y){
                 pq.push(y - x);
            }
        }
        if(pq.size() == 0){
            return 0;
        }
        return pq.top();
    }
};