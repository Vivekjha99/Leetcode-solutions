class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_set<int>st(spaces.begin(),spaces.end());
        string res="";
        int idx=0;int i=0;
        while(idx<s.size()){
            if(st.find(idx)!=st.end())res.push_back(' ');
            res.push_back(s[idx++]);
        }
        return res;
    }
};