class Solution {
    private:
    int n,m;
public:
    bool dfs(vector<vector<char>>&mat,int i,int j,int idx,string &word,vector<vector<bool>>&vis){
        if(idx==word.size())return true;
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]||mat[i][j]!=word[idx])
            return false;
        vis[i][j]=true;
        bool res=dfs(mat,i+1,j,idx+1,word,vis) || dfs(mat,i,j+1,idx+1,word,vis) || dfs(mat,i-1,j,idx+1,word,vis) || dfs(mat,i,j-1,idx+1,word,vis);
        vis[i][j]=false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,i,j,0,word,vis))
                    return true;
            }
        }
        return false;
    }
};