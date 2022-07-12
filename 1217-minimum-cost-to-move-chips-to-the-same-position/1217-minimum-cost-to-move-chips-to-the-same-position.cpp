class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int odds=0,evens=0;
        int n=pos.size();
        for(int i=0;i<n;i++){
            if(pos[i]&1)odds++;
            else evens++;
        }
        return min(evens,odds);
    }
};