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
    int maxValue(int num , Node* root){
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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            insert(nums[i]);
        }
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , maxValue(nums[i] , root));
        }
        return ans;
    }
};