class Solution {
public:
    string largestPalindromic(string num) {
        vector<int>nums(10,0);
        for(auto x:num){
            int ch=x-'0';
            nums[ch]++;
        }
        int cnt=nums[0];
        int ans=0;bool flag=false;
        string res1="",res2="";
        char mid=' ';
        for(int i=9;i>=1;i--){
            if(nums[i]>0){
                int d=nums[i];
                while(d>1){
                    res1.push_back(i+'0');
                    res2.push_back(i+'0');
                    d-=2;
                }
                if(nums[i]%2 && !flag){
                    mid=i+'0';   
                    flag=true;
                }
            }
        }
        // cout<<cnt<<endl;
        if(res1.size()>0){
            while(cnt>1){
                res1.push_back('0');
                res2.push_back('0');
                cnt-=2;
            }
            if(!flag && cnt>0){
                mid='0';
                flag=true;
            }
        }
        reverse(res2.begin(),res2.end());
        if(res1.size()==0 && res2.size()==0 && mid==' ' && cnt>0)return "0";
        if(flag)res1.push_back(mid);
        res1+=res2;
        
        return res1;
    }
};