class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), [](const auto& x, const auto& y){
            return x[0] != y[0] ? x[0] < y[0] : x[1] > y[1];
        });
        int cnt=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(intervals[j][0]<=intervals[i][0] && intervals[j][1]>=intervals[i][1]){
                    cnt++;
                    break;
                }
            }
        }
        return n-cnt;
    }
};