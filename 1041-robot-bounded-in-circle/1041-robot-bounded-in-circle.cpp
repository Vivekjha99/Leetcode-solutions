class Solution {
public:
    int left(int x){
        return (x+1)%4;
    }
    int right(int x){
        if(x==0)return 3;
        else if(x==1)return 0;
        else if(x==2)return 1;
        else return 2;
    }
    bool isRobotBounded(string ins) {
        vector<int>dx={1,0,-1,0};
        vector<int>dy={0,-1,0,1};
        int x1=0,y1=0;//stores coordinates
        ins+=ins+ins+ins;
        int n=ins.size();
        int dir=0;
        for(auto x:ins){
            if(x=='L')dir=left(dir);
            else if(x=='R')dir=right(dir);
            else{
                x1+=dx[dir];
                y1+=dy[dir];
                // cout<<x1<<" "<<y1<<endl;
            }
        }
        if(x1==0 && y1==0 )return true;
        return false;
    }
};