class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1 , num2 = -1 , c1 = 0 , c2 = 0 , i;
        for( i = 0 ; i < n ; i++){
            if(num1 == nums[i]){
                c1++;
            }else if(num2 == nums[i]){
                c2++;
            }else if(c1 == 0){
                num1 = nums[i];
                c1 = 1;
            }else if(c2 == 0){
                num2 = nums[i];
                c2 = 1; 
            }else{ 
                c1--;
                c2--;
            } 
        }
        // cout << num1 << " " << num2;
        int count1 = 0 , count2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == num1){
                count1++;
            }else if(nums[i] == num2){
                count2++;
            }
        }
        if((count1 > n/3) && (count2 > n/3)){
            return {num1 , num2};
        }else if(count1 > n/3){
            return {num1};
        }else if(count2 > n/3){
            return {num2};
        }else{
            return {};
        }
    }
};