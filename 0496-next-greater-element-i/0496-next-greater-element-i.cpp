class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums2.size();
        vector<int>res(n);stack<int>st;
        for(int i=0;i<nums2.size();i++)mp[nums2[i]]=i;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i])st.pop();
            if(st.empty())res[i]=-1;
            else res[i]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=res[mp[nums1[i]]];
        }
        return nums1;

    }
};