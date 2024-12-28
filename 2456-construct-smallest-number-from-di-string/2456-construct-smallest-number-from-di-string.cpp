
class Solution {
    
    int ans = INT_MAX;
    
    bool solve(int x, int ind , string pattern,vector<int> &vis){        
        if(ind==pattern.size()){      
              ans = x; //if we come to the last index it is means we get one possible ans and it is the minimiun 
              return true;
        }

       int mini = INT_MAX;
       int digit = x %10; //last digit 

        if(pattern[ind]=='I'){          
            for(int i=digit+1 ;i<=9 ;i++){                               
                if(vis[i]==0){         
                 vis[i] = 1;
                 if(mini, solve( x*10 + i,ind+1,pattern,vis))return true;
                 vis[i] = 0;
                }
            }           
        }
        else{            
            for(int i=digit-1;i>=1 ;i--){
                if(vis[i]==0){
                 vis[i] = 1;
                if(solve( x*10+i , ind+1, pattern,vis) ==true)return true;
                 vis[i] = 0;
                }
            }
        }
        return  false;
    }
public:
    string smallestNumber(string pattern) {        
        vector<int> vis(10,0); // keep tracking which digit all ready taken as we cannot take same digit multiple times
        for(int i=1;i<=9;i++){     
            vis[i] = 1;
            if(solve(i,0,pattern,vis)==true)break;//if we get our ans there is not need to go further because it is the minimum 
            vis[i] = 0;          
        }
        return to_string(ans);        
    }
};