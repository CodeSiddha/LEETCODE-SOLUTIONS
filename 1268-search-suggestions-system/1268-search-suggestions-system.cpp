
class Solution {    
public:

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        int  n = products.size();
        sort(products.begin() , products.end());
        int m = searchWord.size();
        for(int i = m - 1 ; i >= 0 ; i--){
            string searchThis = searchWord.substr(0 , i + 1);
            vector<string> candidates;
            int searchSize = searchThis.size();
            for(int i = 0 ; i < n ; i++){
                if(candidates.size() == 3) break;
                string cand = products[i].substr(0 , searchSize);
                if(cand == searchThis){
                    candidates.push_back(products[i]);
                }
            }
            ans.push_back(candidates);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};