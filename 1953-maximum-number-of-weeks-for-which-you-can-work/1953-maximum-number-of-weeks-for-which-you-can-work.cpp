class Solution {
public:
    long long numberOfWeeks(vector<int>& mile) {
        int n = mile.size();
        // long long ans = 0;
        int mx = *max_element(mile.begin() , mile.end());
        long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += mile[i];
        }
        long long restExceptLast = sum - mx;
        
        return min({1ll * 2 * restExceptLast + 1 , sum});
    }
};