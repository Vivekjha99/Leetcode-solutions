class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int>digits;
        if(n==10)return 9;
        while(n>0){
            digits.push_back(n%10);
            n/=10;
        }
        
        reverse(digits.begin(),digits.end());
        // for(auto x:digits)cout<<x<<" ";
        // cout<<endl;
        int len=digits.size();
        int idx=len;
        for(int i=len-1;i>0;i--){
            if(digits[i]<digits[i-1]){
                idx=i;
                digits[i-1]--;
            }
        }
        while(idx!=len){
            digits[idx++]=9;
        }
        int res=0;
        for(int i=0;i<len;i++){
            res=res*10+digits[i];
        }
        return res;
    }
};