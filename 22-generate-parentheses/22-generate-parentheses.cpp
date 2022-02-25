class Solution {
public:
    void solve(vector<string>&ans,string s,int op,int cl,int max){
        if(s.size()==2*max){
            ans.push_back(s);
            return ;
        }
        if(op<max)solve(ans,s+'(',op+1,cl,max);
        if(cl<op)solve(ans,s+')',op,cl+1,max);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(ans,"",0,0,n);
        return ans;
    }
};