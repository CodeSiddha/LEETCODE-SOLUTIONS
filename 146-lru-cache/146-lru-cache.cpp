class LRUCache {
    private:
    list<pair<int,int>> li;
    unordered_map<int , list<pair<int ,int>>::iterator> mpp;
    int cap;
    public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mpp.count(key)){
            li.splice( li.begin(), li , mpp[key]);
            return mpp[key]->second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mpp.count(key)){
            mpp[key]->second = value;
            li.splice(li.begin() , li , mpp[key]);
            return;
        }
        if(mpp.size() == cap){
            auto del = li.back().first;
            li.pop_back();
            mpp.erase(del);
        }
        li.push_front({key, value});
        mpp[key] = li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */