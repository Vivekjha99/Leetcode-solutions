class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int res=0;
        string t="123450";
        vector<vector<int>>moves={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string start="";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                start+=to_string(board[i][j]);
            }
        }
        unordered_set<string>vis;
        vis.insert(start);
        queue<pair<string,int>>q;
        q.push({start,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            string curr=p.first;
            int d=p.second;
            int idx=curr.find("0");
            if(curr==t)return d;
            for(auto x:moves[idx]){
                string temp=curr;
                swap(temp[idx],temp[x]);
                if(vis.count(temp)==0){
                    vis.insert(temp);
                    q.push({temp,d+1});
                }
            }
        }
return -1;
    }
};