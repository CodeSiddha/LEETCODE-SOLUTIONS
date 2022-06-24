class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<int> pq;
        long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += target[i];
            pq.push(target[i]);
        }
        while(true){
            if(pq.top() == 1){
                return true;
            }
            long long topval = pq.top();
            pq.pop();
            sum -= topval;
            if(sum == 1) return true;
            if(topval < sum || sum == 0 ||topval % sum == 0){
                return false;
            }
            pq.push(topval%sum);
            sum += (topval%sum);
        }
    }
};