class MyCircularQueue {
public:
    vector<int>nums;
    int cap=0,sz=0;
    int front,rear;
    MyCircularQueue(int k) {
        nums=vector<int>(k,0);
        cap=k;
        sz=0;
        front=0,rear=0;
    }
    bool enQueue(int value) {
        if(isFull())return false;
        nums[rear++]=value;
        rear%=cap;
        sz++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        front=(front+1)%cap;
        sz--;
        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        return nums[front];
    }
    
    int Rear() {
        if(isEmpty())return -1;
        if(rear==0)return nums[cap-1];
        else return nums[rear-1];
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */