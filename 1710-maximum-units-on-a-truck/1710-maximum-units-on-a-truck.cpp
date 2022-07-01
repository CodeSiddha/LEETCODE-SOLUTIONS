class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b){
        if(a[1] == b[1]){
            return a[1] > b[1];
        }else if(a[1] > b[1]){
            return true;
        }
        return false;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int ans = 0;
        sort(boxTypes.begin() , boxTypes.end() , cmp);
        for(int i = 0 ; i < n ; i++){
           if(boxTypes[i][0] >= truckSize){
            ans += truckSize * boxTypes[i][1];
            truckSize = 0;
           }else if(boxTypes[i][0] < truckSize){
               ans += boxTypes[i][0] * boxTypes[i][1];
               truckSize -= boxTypes[i][0];
           }
            if(truckSize == 0){
                break;
            }
            // cout << boxTypes[i][0] << " " << boxTypes[i][1] << endl;
        }
        return ans;
    }
};