class Solution {
public:
    int compress(vector<char>& chars) {
        string res="";
        int n=chars.size();
        for(int i=0;i<n;i++){
            char ch=chars[i];
            res.push_back(ch);
            if(i!=n-1){
            int j=i+1;
            if(chars[j]==ch){
                int cnt=1;
                while(j<n && chars[j]==ch){
                    cnt++;
                    j++;
                }
                res+=to_string(cnt);
                i=j-1;
            }
            }
        }
        // cout<<res<<endl;
        chars.resize(res.size());
        for(int i=0;i<res.size();i++)chars[i]=res[i];
        return res.size();
    }
};