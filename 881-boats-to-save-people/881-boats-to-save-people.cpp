class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin() , people.end());
        int i = 0;
        int j = n - 1;
        int boatCount = 0;
        while(i <= j){
            if(i == j){
                boatCount++;
                i++;
                j--;
            }else if(people[i] + people[j] <= limit){
                boatCount++;
                i++;
                j--;
            }else if(people[i] + people[j] > limit){
                boatCount++;
                j--;
            }
        }
        return boatCount;
    }
};