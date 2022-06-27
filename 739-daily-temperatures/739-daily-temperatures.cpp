class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n=temp.size();
        st.push(0);
        vector<int>ans(n,0);
        for(int i=1;i<n;i++){
            while(!st.empty() && temp[st.top()]<temp[i]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
    return ans;
        
    }
};