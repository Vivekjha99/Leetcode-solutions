class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int swaps=0;
        int bal=0;
        int i=0,j=n-1;
        for(i=0;i<n;i++){
            if(s[i]=='[')bal++;
            else bal--;
            if(bal<0){
                while(i<j && s[j]==']')j--;
                swap(s[i],s[j]);
                bal=1;
                swaps++;
            }
        }
        return swaps;
    }
};