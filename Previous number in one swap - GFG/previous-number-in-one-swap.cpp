// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string s){
        int n = s.size();
        int k = -1;
        for(int i = n - 2 ; i >= 0 ; i--){
            if(s[i] > s[i + 1]){
                k = i;
                break;
            }
        }
        if(k == -1){
            return "-1";
        }else{
            int l = -1;
            int maxchar = -1;
            for(int i = n - 1 ; i > k ; i--){
                if( s[i] < s[k] && s[i] - '0' >= maxchar){
                    if(s[i] == '0' && k == 0){
                        continue;
                    }
                    maxchar = s[i] - '0';
                    l = i;
                }
            }
            if(l == -1){
                return "-1";
            }
            swap(s[k] , s[l]);
            return s;
        }
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends