class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
       if(a.length()>b.length())swap(a,b);
        int x=a.length();
        reverse(a.begin(),a.end());
        while(a.length()<b.length())a.push_back('0');
        cout<<a<<" "<<b<<endl;
        reverse(b.begin(),b.end());
        int carry=0;int i=0;
        for(i=0;i<a.length();i++){
            if(a[i]==b[i]){
                if(a[i]=='1'){
                    if(carry)ans.push_back('1');
                    else ans.push_back('0');
                    carry=1;
                }
                else{
                    if(carry)ans.push_back('1');
                    else ans.push_back('0');
                    carry=0;
                }
            }
            else{
                if(carry){
                    ans.push_back('0');
                    carry=1;
                }
                else{ 
                    ans.push_back('1');
                    carry=0;
                }
            }
            
        }
        
        if(carry)ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};