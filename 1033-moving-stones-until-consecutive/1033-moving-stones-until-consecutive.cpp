class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int>nums={a,b,c};
        sort(nums.begin(),nums.end());
        if(nums[0]+1==nums[1] && nums[1]+1==nums[2])return {0,0};
        int maxi=(nums[1]-nums[0]-1)+(nums[2]-nums[1]-1);
        int mini=INT_MAX;
        if(nums[2]-1==nums[1]+1)mini=1;
        else if(nums[0]+1==nums[1]-1)mini=1;
        else if(nums[0]+1==nums[1])mini=1;
        else if(nums[1]+1==nums[2])mini=1;
        else mini=2;
        return {mini,maxi};
        
    }
};