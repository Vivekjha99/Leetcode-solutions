class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        stack<pair<int,int>>st;
        int ans=0;
        st.push({nums[n-1],0});
        for(int i=n-2;i>=0;i--){
            int cnt=0;
                while(!st.empty() && st.top().first<nums[i]){
                    cnt=max(st.top().second,cnt+1);
                    st.pop();
                }
                ans=max(ans,cnt);
                st.push({nums[i],cnt});
            }
      
    return ans;
    }
};