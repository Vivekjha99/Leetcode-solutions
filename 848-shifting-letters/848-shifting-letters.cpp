class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();
        for(int i=n-2;i>=0;i--)shifts[i]=(shifts[i]+shifts[i+1])%26;
        string res="";
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            ch=(ch+shifts[i])%26;
            res.push_back(ch+'a');
        }
        return res;
    }
};