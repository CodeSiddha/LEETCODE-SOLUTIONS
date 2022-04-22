vector<int> mpp(1000001);
// mpp.resize();
class MyHashMap {
public:  
    MyHashMap() {  
        fill(mpp.begin() , mpp.end() , -1);
    }
    
    void put(int key, int value) {
        mpp[key] = value;
        return;
    }
    
    int get(int key) {
        return mpp[key];
    }
    
    void remove(int key) {
        mpp[key] = -1;
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */