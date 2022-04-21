class MyHashSet {
    private:
    int arr[1000001];
public:
    MyHashSet() {
        memset(arr,0,sizeof(arr));
    }
    
    void add(int key) {
        arr[key]++;
    }
    
    void remove(int key) {
        arr[key] = 0;
    }
    
    bool contains(int key) {
        if(arr[key] > 0)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */