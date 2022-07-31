class NumArray {
public:
    vector<int>seg;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n,0);
        buildTree(nums,0,0,n-1);
    }
    void buildTree(vector<int>&nums,int idx,int l,int r){
        if(l==r){
            seg[idx]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        buildTree(nums,2*idx+1,l,mid);
        buildTree(nums,2*idx+2,mid+1,r);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    void updateutil(int idx,int l,int r,int index,int val){
        if(index<l|| index>r)return;
        if(l==r){
            if(l==index)
                seg[idx]=val;
            return;
        }
        int mid=(l+r)/2;
        updateutil(2*idx+1,l,mid,index,val);
        updateutil(2*idx+2,mid+1,r,index,val);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    int rangeUtil(int qlow, int qhigh, int low, int high, int pos){
        if (qlow <= low && qhigh>= high){ // total overlap
            return seg[pos];
        }
        if (qlow > high || qhigh < low) { // no overlap
            return 0;
        }
        // partial overlap
        int mid = low+(high-low)/2;
        return (rangeUtil(qlow, qhigh, low, mid, 2*pos+1) + rangeUtil(qlow, qhigh, mid+1, high, 2*pos+2));
    }
    void update(int index, int val) {
        if(n==0)return;
        updateutil(0,0,n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        if(n==0)return 0;
        return rangeUtil(left, right, 0, n-1, 0); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */