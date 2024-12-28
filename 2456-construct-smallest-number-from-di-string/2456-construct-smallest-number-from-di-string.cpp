class Solution {
public:
    void findSmallestNo(string &p,vector<int>&vis,int idx,string &s,string &res){
        if(idx==p.length()){
            if(res>s)res=s;
            return;
        }
        if(idx==-1){
            for(int j=1;j<=9;j++){
                if(vis[j]==0){
                    vis[j]=1;
                    s+=j+'0';
                    findSmallestNo(p,vis,idx+1,s,res);
                    s.pop_back();
                    vis[j]=0;
                }
            }
        }
        else{
            if(p[idx]=='D'){
                int t=s[s.length()-1]-'0';
                for(int j=t-1;j>=1;j--){
                    if(vis[j]==0){
                        vis[j]=1;
                        s+=j+'0';
                        findSmallestNo(p,vis,idx+1,s,res);
                        s.pop_back();
                        vis[j]=0;
                    }
                }
            }
            else{
                int t=s[s.length()-1]-'0';
                for(int j=t+1;j<=9;j++){
                    if(vis[j]==0){
                        vis[j]=1;
                        s+=j+'0';
                        findSmallestNo(p,vis,idx+1,s,res);
                        s.pop_back();
                        vis[j]=0;
                    }
                }
            }
        }
    }
    string smallestNumber(string pattern) {
        string res="987654321";
        string s="";
        vector<int>vis(10,0);
        findSmallestNo(pattern,vis,-1,s,res);
        return res;
    }
};