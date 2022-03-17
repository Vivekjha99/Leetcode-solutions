class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        stack<int>st;    
        int n=s.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            if(s[i]=='(')st.push(0);
            else{
                while(st.top()!=0){
                    cnt+=st.top();
                    st.pop();
                }
                cnt=max(2*cnt,1);
                st.pop();
                st.push(cnt);
                
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};