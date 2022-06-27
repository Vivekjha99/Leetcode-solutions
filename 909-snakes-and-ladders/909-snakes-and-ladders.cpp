class Solution {
public:
    void getcor(int num,int n,int &row,int &col){
        row=n-1-(num-1)/n;
        col=(num-1)%n;
        if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))col=n-1-col;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<bool>vis(n*n+1,false);
        vis[1]=true;
        queue<pair<int,int>>q;
        q.push({1,0});
        while(!q.empty()){
            int x=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(x==n*n)return dis;
            int row,col;
            for(int i=1;x+i<=n*n && i<=6;i++){
                getcor(x+i,n,row,col);
                int x1=board[row][col]==-1?x+i:board[row][col];
                if(!vis[x1]){
                    vis[x1]=true;
                    q.push({x1,dis+1});
                }
            }
        }
        return -1;
    }
};