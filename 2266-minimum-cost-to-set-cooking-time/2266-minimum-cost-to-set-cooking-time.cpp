class Solution {
public:
    int findMinMoves(int mins,int secs,int tar,int pc,int mc,int start){
        string target=to_string(mins*100+secs);
        char curr=start+'0';
        int cost=0;
        for(char ch:target){
            if(curr==ch)cost+=pc;
            else{
                cost+=pc+mc;
                curr=ch;
            }
        }
        return cost;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
            int maxMins=targetSeconds/60;
            int res=INT_MAX;
            for(int mins=0;mins<=maxMins;mins++){
                int secs=targetSeconds-mins*60;
                if(secs>99 || mins>99)continue;
                res=min(res,findMinMoves(mins,secs,targetSeconds,pushCost,moveCost,startAt));
            }
            return res;
    }
};