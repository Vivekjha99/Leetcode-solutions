class MyHashSet {
    private:
        vector<bool>table;
public:
    MyHashSet() {
        table=vector<bool>(1e6+5,false);
    }
    
    void add(int key) {
        table[key]=true;
    }
    
    void remove(int key) {
        table[key]=false;
    }
    
    bool contains(int key) {
        
        return table[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */