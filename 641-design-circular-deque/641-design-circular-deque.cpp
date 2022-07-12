class MyCircularDeque {
public:
    vector<int>nums;
    int cap,sz,head,tail;
    MyCircularDeque(int k) {
        nums=vector<int>(k,0);
        cap=k;
        sz=0;
        head=0,tail=0;
    }
    
    bool isFull(){
        return sz==cap;
    }
    bool isEmpty(){
        return sz==0;
    }
    bool insertFront(int value) {
        if(isFull())return false;
        head=head==0 ?cap-1:head-1;
        nums[head]=value;
        sz++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())return false;
        nums[tail++]=value;
        tail%=cap;
        sz++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        head=(head+1)%cap;
        sz--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        tail=tail==0?cap-1 :tail-1;
        sz--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())return -1;
        return nums[head];
    }
    
    int getRear() {
        if(isEmpty())return -1;
        if(tail==0)return nums[cap-1];
        else return nums[tail-1];
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */