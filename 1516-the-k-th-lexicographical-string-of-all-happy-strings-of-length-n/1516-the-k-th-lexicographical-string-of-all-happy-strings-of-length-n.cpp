class Solution {
public:
    void findAllHappyStrings(string &st,string temp,vector<string>&res,int n){
        if(n==0){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<st.size();i++){
           if(temp.size()==0 || temp.back()!=st[i]){
            findAllHappyStrings(st,temp+st[i],res,n-1);
           }
        }
    }
    string getHappyString(int n, int k) {
        string st="abc";
        vector<string>res;
        findAllHappyStrings(st,"",res,n);
        sort(res.begin(),res.end());
        for(auto x:res){
            cout<<x<<" ";
        }
        return res.size()>=k?res[k-1]:"";
    }
};