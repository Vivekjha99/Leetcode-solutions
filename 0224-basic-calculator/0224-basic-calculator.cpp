class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int sign=1,res=0;
        int n=s.size();
        int num=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch>='0' && ch<='9'){
                num=num*10+(ch-'0');
            }
            else if(ch=='-'){
                //num needs to be reset
                res+=sign*num;
                num=0;
                sign=-1;
            }
            else if(ch=='+'){
                //num needs to be reset
                res+=sign*num;
                num=0;
                sign=1;
            }
            else if(ch=='('){
                //we will reset the current res and the sign 
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(ch==')'){
                res+=sign*num;
                num=0;
                res*=st.top();
                st.pop();
                res+=st.top();
                st.pop();
            }
        }
        if(num!=0)res+=sign*num;
        return res;
    }
};