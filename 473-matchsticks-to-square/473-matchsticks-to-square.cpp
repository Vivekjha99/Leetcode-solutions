class Solution {
public:
    bool checksides(vector<int>&sides){
        return sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3];
    }
    bool seen(vector<int>&sides,int idx){
        for(int i=0;i<idx;i++){
            if(sides[i]==sides[idx])return true;
        }
        return false;
    }
    bool dfs(vector<int>&nums,vector<int>&sides,int idx,int side){
        if(idx==nums.size())
            return checksides(sides);
        for(int i=0;i<4;i++){
            if(sides[i]+nums[idx]>side)continue;
            if(seen(sides,i))continue;
            sides[i]+=nums[idx];
            if(dfs(nums,sides,idx+1,side))return true;
            sides[i]-=nums[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4)return false;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4)return false;
        sort(nums.rbegin(),nums.rend());
        vector<int>sides(4,0);
        int side=sum/4;
        return dfs(nums,sides,0,side);
    }
};