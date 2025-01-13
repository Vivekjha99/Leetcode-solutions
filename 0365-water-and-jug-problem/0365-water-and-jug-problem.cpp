class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y==target) return true;
        if(x+y<target) return false;
        if(x%2==0 && y%2==0 && target%2!=0)//cannot measure odd capacity using even capacity jugs 
            return false;
        //bfs on 6 states
        set<pair<int,int>>vis;
        queue<pair<int,int>>q;
        q.push({x,y});
        while(!q.empty()){
            pair<int,int>curr=q.front();
            int cx=curr.first;
            int cy=curr.second;
            q.pop();
            if((cx+cy)==target)return true;
            vis.insert(curr);
            int nx,ny;
            //pouring x to y
            nx=cx-min(cx,y-cy);
            ny=y+min(cx,y-cy);
            if(vis.find({nx,ny})==vis.end())q.push({nx,ny});
            //pouring y to x
            nx=cx+min(cy,x-cx);
            ny=cy-min(cy,x-cx);
            if(vis.find({nx,ny})==vis.end())q.push({nx,ny});
            //emptying x
            if(vis.find({0,cy})==vis.end())q.push({0,cy});
            //emptying y
            if(vis.find({cx,0})==vis.end())q.push({cx,0});
            //filling x
            if(vis.find({x,cy})==vis.end())q.push({x,cy});
            //filling y
            if(vis.find({cx,y})==vis.end())q.push({cx,y});
        }
    return false;
    }
};