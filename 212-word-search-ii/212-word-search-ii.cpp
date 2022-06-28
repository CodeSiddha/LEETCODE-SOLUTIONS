struct Node{
    Node* links[26];
    bool flag = false;
    bool isContainKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch , Node* node){
        links[ch - 'a'] = node;
    }
    void isTheEnd(){
        flag = true;
    }
};
class Solution {
    private:
    Node* root;
public:
    Solution(){
        root = new Node();
    }
    void insert(string &word){
        Node* node = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(!node->isContainKey(word[i])){
                node->put(word[i] , new Node());
            }
            node = node->links[word[i] - 'a'];
        }
        node->isTheEnd();
    }
    bool search(string &word){
        Node* node = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(node->links[word[i] - 'a']){
                node = node->links[word[i] - 'a'];
            }else{
                return false;
            }
        }
        
        if(node->flag){
         node->flag = false;    
        return true;
        }
        
        return false;
    }
    bool linkPresent(string &word){
         Node* node = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(node->links[word[i] - 'a']){
                node = node->links[word[i] - 'a'];
            }else{
                return false;
            }
        }
        return true;
    }
    void dfs(int i , int j , vector<vector<char>>& board , vector<vector<bool>>&visited , vector<string>&ans , string str){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){
            return;
        }
         if(visited[i][j] == true) return;
         visited[i][j] = true;
         str += board[i][j];
         if(!linkPresent(str)){
             visited[i][j] = false;
             return;
         }
         if(search(str)){
                ans.push_back(str); 
         }
         dfs(i + 1 , j , board , visited , ans , str);
         dfs(i - 1 , j , board , visited , ans , str);
         dfs(i , j - 1 , board , visited , ans , str);
         dfs(i , j + 1 , board , visited , ans , str);
         visited[i][j] = false;
         return ;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < words.size() ; i++){
            insert(words[i]);
        }
        vector<string> ans;
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(root->links[board[i][j] - 'a'])
                dfs(i , j , board , visited , ans , "");
            }
        }
        return ans;
    }
};