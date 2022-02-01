class Solution {
public:
    bool check(priority_queue<int>&pq){
        int x=pq.top();
        pq.pop();
        int d=abs(x-pq.top());
        x=pq.top();
        pq.pop();
        while(!pq.empty()){
            int diff=x-pq.top();
            if(diff!=d){
                return false;
            }
            x=pq.top();
            pq.pop();
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        priority_queue<int>pq;
        int n=l.size();
        for(int i=0;i<n;i++){
            int start=l[i];
            int end=r[i];
            for(int i=start;i<=end;i++){
                pq.push(nums[i]);
            }
            ans.push_back(check(pq));
            while(!pq.empty())pq.pop();
        }
        return ans;
    }
};