//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)dp[i][i]=true;
        string ans="";
        ans+=s[0];
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i==1 || dp[i+1][j-1]){
                        dp[i][j]=true;
                        if(ans.size()<=j-i+1){
                            ans=s.substr(i,j-i+1);
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends