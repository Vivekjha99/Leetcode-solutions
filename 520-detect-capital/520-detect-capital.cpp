class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int s=0,l=0;
        for(int i=0;i<n;i++){
            int x=word[i];
           if(x>=65 && x<=90)l++;
            else s++;
        }
        if(s==n || (l==1 && word[0]>='A' && word[0]<='Z')||(l==n))
            return true;
        else return false;
    }
};