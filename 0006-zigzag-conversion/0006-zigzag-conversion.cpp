class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string>str(numRows);
        int steps=0;
        int rows=0;
        for(int i=0;i<s.size();i++){
            str[rows].push_back(s[i]);
            if(rows==0)steps=1;
            else if(rows==numRows-1)steps=-1;
            rows+=steps;
        }
        string ans;
        for(int i=0;i<numRows;i++){
            for(auto x:str[i]){
                ans.push_back(x);
            }
        }
        return ans;
    }
};