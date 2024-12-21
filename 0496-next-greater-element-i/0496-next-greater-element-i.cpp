class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums2.size();
        vector<int>res(nums1.size(),-1);stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<nums2[i]){
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])!=mp.end()){
                res[i]=mp[nums1[i]];
            }
        }
        return res;

    }
};