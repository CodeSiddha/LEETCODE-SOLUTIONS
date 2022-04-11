// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
     static bool comp(pair<int,int> a, pair<int,int>b){
       if(a.second== b.second){
           return a.first<b.first;
       }
       return a.second<b.second;
   }
   int maxMeetings(int start[], int end[], int n)
   {
       // greedy
       // sort wrt the finish time
       vector<pair<int,int>> act(n);
       for(int i=0;i<n;i++){
           act[i]= {start[i], end[i]};
       }
       sort(act.begin(),act.end(), comp);
       int i=0, j=1, count=1;
       while(j<n){
           if(act[i].second<act[j].first){
               i=j;
               count++;
           }
           j++;
       }
       return count;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends