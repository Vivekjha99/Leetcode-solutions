class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        vector<int>res(num1.size()+num2.size(),0);
        for(int i=num1.size()-1;i>=0;i--){
            for(int j=num2.size()-1;j>=0;j--){
                res[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                res[i+j]+=res[i+j+1]/10;
                res[i+j+1]%=10;
            }
        }
        int idx=0;
        while(res[idx]==0)idx++;
        string ans="";
        for(int i=idx;i<res.size();i++){
            ans+=to_string(res[i]);
        }
        return ans;
    }
};