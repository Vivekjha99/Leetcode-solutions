class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        bool flag=true;
        int idx=0;
        int n=str1.size();
        for(int i=0;i<n;i++){
            if(str1[i]==str2[idx]){
                idx++;
                continue;
            }
            char x=((str1[i]-'a'+1)%26)+97;
            // cout<<x<<" "<<str2[idx]<<endl;
            if(x==str2[idx]){
                idx++;
            }
        }
        return idx==str2.size();
    }
};