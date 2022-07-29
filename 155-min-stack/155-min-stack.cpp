class MinStack {
public:
   vector<int>nums;
    map<int,int>mp;
    MinStack() {
        
    }
    
    void push(int val) {
        nums.push_back(val);
        mp[val]++;
    }
    
    void pop() {
        int x=nums.back();
        nums.pop_back();
        mp[x]--;
        if(mp[x]==0)mp.erase(x);
    }
    
    int top() {
        return nums.back();
    }
    
    int getMin() {
        auto it=mp.begin();
        return it->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */