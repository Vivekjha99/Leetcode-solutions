class Solution {
public:
    unordered_set<int>vis;//stores the indexes visited
    int dfs(vector<vector<int>>&stones,int x,int y,int idx){
        vis.insert(idx);
        int ans=0;
        //first checking rows
        for(int i=0;i<stones.size();i++){
            if(stones[i][0]==x && vis.find(i)==vis.end())
                ans+=1+dfs(stones,x,stones[i][1],i);
        }
        //checking cols
        for(int i=0;i<stones.size();i++){
            if(stones[i][1]==y && vis.find(i)==vis.end())
                ans+=1+dfs(stones,stones[i][0],y,i);
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones .size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis.find(i)==vis.end()){
                ans+=dfs(stones,stones[i][0],stones[i][1],i);
            }
        }
        return ans;
    }
};