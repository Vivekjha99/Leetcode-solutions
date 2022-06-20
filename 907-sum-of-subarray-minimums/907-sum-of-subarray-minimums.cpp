
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<long long>next_small(n);
        vector<long long>prev_small(n);
        //these two vectors are storing no of elements to the right and 
        //left of the current smaller element
        //base case
        for(int i=0;i<n;i++){
            next_small[i]=n-i-1;
            prev_small[i]=i;
        }
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()  && arr[st.top()]>arr[i]){
                next_small[st.top()]=i-st.top()-1;
                st.pop();
            }
            st.push(i);
        }
        stack<int>st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && arr[st1.top()]>=arr[i]){
                prev_small[st1.top()]=st1.top()-i-1;
                st1.pop();
            } 
            st1.push(i);
        }
        int mod=1e9+7;
        long long ans=0;
        for(int i=0;i<n;i++){
           ans+=arr[i]*(prev_small[i]+1)*(next_small[i]+1);
            ans=ans%mod;
        }
        return ans;
    }
    
};