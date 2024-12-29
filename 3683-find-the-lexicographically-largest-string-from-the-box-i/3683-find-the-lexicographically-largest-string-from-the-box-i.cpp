class Solution {
public:
    string answerString(string word, int numFriends) {
        string res;
        int n = word.size();
        if(numFriends==1)return word;
        if(n==1)return word;
        int l = n - numFriends + 1;
        for(int i=0;i<n;i++){
            res=max(res,word.substr(i,l));
        }
        return res;
    }
};