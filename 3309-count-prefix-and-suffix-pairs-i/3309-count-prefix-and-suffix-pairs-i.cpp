class Solution {
public:
    bool isPrefixSuffix(string &w1,string &w2){
        int n1=w1.size();
        int n2=w2.size();
        if(w1>w2)swap(w1,w2);
        return w2.substr(0,n1)==w1 && w1==w2.substr(n2-n1);
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string w1=words[i];
                string w2=words[j];
                    cnt+=isPrefixSuffix(w1,w2);
            }
        }
        return cnt;
    }
};