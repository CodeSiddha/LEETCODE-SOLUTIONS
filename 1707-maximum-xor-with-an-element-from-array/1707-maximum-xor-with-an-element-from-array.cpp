struct Node{
    Node* child[2];
    bool isContainKey(int bit){
        return (child[bit] != NULL);
    }
    void put(int bit , Node* node){
        child[bit] = node;
    }
};
class Solution {
public:
     Node* root = new Node();
    void insert(int num){
        Node* node = root;
        for(int i = 31 ; i >= 0 ; i--){
            int bit = ((num >> i) & 1);
            if(!node->isContainKey(bit)){
                node->put(bit , new Node());
            }
            node = node->child[bit];
        }
    }
    int findMaxXor(int num , Node* root){
        Node* node = root;
        int ans = 0;
        int power = 31;
        for(int i = 31 ; i >= 0 ; i--){
            int bit = !((num >> i) & 1);
            if(node->isContainKey(bit)){
                ans += pow(2 , power);
                node = node->child[bit];
            }else{
                node = node->child[!bit];
            }
            power--;
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<pair<int,pair<int,int>>> qry;
        vector<int> ans(queries.size());
        for(int i = 0 ; i < queries.size() ; i++){
            qry.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(qry.begin() , qry.end());
        sort(nums.begin() , nums.end());
        int j = 0;
        for(int i = 0 ; i < qry.size() ; i++){
            
            while(j < n && qry[i].first >= nums[j]){
                insert(nums[j]);
                j++;
            }
            if(root->child[0] == NULL && root->child[1] == NULL){
                ans[qry[i].second.second] = -1;    
            }else{
                ans[qry[i].second.second] = findMaxXor(qry[i].second.first , root); 
            }
        }
        return ans;
    }
};