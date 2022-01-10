class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()<num2.size())swap(num1,num2);
        //num1>always
        while(num2.size()<num1.size())num2="0"+num2;
       int carry=0;
        string res;
        //vector<int>res(num1.size()+2,0);
        for(int i=num1.size()-1;i>=0;i--){
            int x=(num1[i]-'0')+(num2[i]-'0');
            int sum=x+carry;
          //  cout<<x<<" "<<carry<<" "<<sum<<endl;
            res=to_string(sum%10)+res;
            carry=sum>9?sum/10:0;
        }
        if(carry)
            res=to_string(carry)+res;
        return res;
    }
};