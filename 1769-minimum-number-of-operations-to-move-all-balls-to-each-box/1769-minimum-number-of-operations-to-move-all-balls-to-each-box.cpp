class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        vector<int>nums;
        for(int i=0;i<n;i++)
            if(boxes[i]=='1')nums.push_back(i);
        for(int i=0;i<n;i++){
            int res=0;
            for(auto x:nums){
                res+=abs(i-x);
            }
            ans[i]=res;
        }
        return ans;
    }
};