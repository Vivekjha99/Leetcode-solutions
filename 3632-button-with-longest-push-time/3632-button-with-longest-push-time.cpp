class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int res=events[0][0];
        int time=events[0][1];
        int n=events.size();
        for(int i=1;i<n;i++){
            int d=events[i][1]-events[i-1][1];
            if(d>time || d==time && res>events[i][0]){
                time =d;
                res=events[i][0];
            }
        }
        return res;
    }
};