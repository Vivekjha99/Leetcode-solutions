class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int idx=0;
        for(int i=1;i<n;i++){
            if(ans[idx][1]>=intervals[i][0]){
                ans[idx][1]=max(ans[idx][1],intervals[i][1]);
            }
            else{
                idx++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};