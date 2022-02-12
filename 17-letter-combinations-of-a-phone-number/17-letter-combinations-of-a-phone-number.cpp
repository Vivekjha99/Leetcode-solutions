class Solution {
public:
    vector<string>v={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string digits,int idx,string &s,vector<string>&ans){
        if(s.size()==digits.size()){
            ans.push_back(s);
            return;
        }
        else{
            for(auto x:v[digits[idx]-'2']){
                s.push_back(x);
                solve(digits,idx+1,s,ans);
                s.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits=="")return ans;
        string s="";
        solve(digits,0,s,ans);
        return ans;
    }
};