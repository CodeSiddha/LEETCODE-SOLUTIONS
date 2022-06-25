// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    static bool cmp(string&a , string&b){
	        if(a.size() == b.size()){
	            return a < b;
	        }else if(a.size() < b.size()){
	            return true;
	        }
	        return false;
	    }
		vector<string> AllPossibleStrings(string s){
		    int n = s.size();
		    vector<string> ans;
		    for(int i = 0 ; i < (1 << n) ; i++){
		        string str = "";
		        for(int j = 0 ; j < n ; j++){
		            if(i & (1 << j)){
		                str += s[j];    
		            }
		        }
		        if(str != "")
		        ans.push_back(str);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;    
		}
		
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends