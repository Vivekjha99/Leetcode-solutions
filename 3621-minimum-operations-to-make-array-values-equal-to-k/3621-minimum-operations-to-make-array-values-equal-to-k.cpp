class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int mini=INT_MAX;
        set<int>st(nums.begin(),nums.end());
        if(*st.begin()<k)return -1;
        int first=*st.begin();
        return first==k?st.size()-1:st.size();
        
        

    }
};