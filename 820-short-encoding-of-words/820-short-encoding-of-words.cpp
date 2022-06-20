class Solution {
public:
    struct Node{
        Node* links[26];
        bool flag = false;
        bool isContainKey(char ch){
            return (links[ch - 'a'] != NULL);
        }
        void put(char ch , Node* node){
            links[ch - 'a'] = node;
        }
        void TheEnd(){
            flag = true;
        }
        bool isTheEnd(){
            return flag;
        }
    };
    Node* root = new Node();
    void insert(string word){
        Node* node = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(!node->isContainKey(word[i])){
                node->put(word[i] , new Node());
            }
            node = node->links[word[i] - 'a'];
        }
        node->TheEnd();
    }
    void calLen(Node* root , int &len , int currdepth){
        bool allNULL = true;
        for(int i = 0 ; i < 26 ; i++){
            if(root->links[i] != NULL){
                allNULL = false;
                calLen(root->links[i] , len , currdepth + 1);
            }
        }
        if(allNULL) {
            len += (currdepth + 1);
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        set<string , greater<string>> mySet;
        for(int i = 0 ; i < n ; i++){
            mySet.insert(words[i]);
        }
        for(auto it = mySet.begin() ; it != mySet.end() ; ++it){
            string word = *it;
            reverse(word.begin() , word.end());
            insert(word);
        }
        int len = 0;
        calLen(root , len , 0);
        return len;
    }
};