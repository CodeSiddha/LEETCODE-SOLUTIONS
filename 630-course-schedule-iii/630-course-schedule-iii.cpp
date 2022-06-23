class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b){
        if(a[1] < b[1]) return true;
        return false;
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end() , cmp);
        int n = courses.size();
        priority_queue<int> pq;
        int time = 0;
        for(int i = 0 ; i < n ; i++){
            time += courses[i][0];
            pq.push(courses[i][0]);
            if(time > courses[i][1]){
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};