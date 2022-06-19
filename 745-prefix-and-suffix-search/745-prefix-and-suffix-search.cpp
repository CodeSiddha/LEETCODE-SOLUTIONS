class WordFilter {
private:
    unordered_map<string , int> mpp;
public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int i = 0 ; i < n ; i++){
            string str = words[i];
            for(int j = 0 ; j < str.size() ; j++){
                string pre = str.substr(0 , j + 1);
                for(int k = 0 ; k < str.size() ; k++){
                    string suf = str.substr(k);
                    mpp[pre + "|" + suf] = i + 1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string search = prefix + "|" + suffix;
        return mpp[search] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */