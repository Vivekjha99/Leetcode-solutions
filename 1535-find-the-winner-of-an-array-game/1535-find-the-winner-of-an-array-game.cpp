class Solution {
public:
    int getWinner(vector<int>& nums, int k) {
        int n=nums.size();
        int winner=nums[0];
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]>winner){
                winner=nums[i];
                cnt=0;
            }
            if(++cnt==k)return winner;
        }
        return winner;
    }
};