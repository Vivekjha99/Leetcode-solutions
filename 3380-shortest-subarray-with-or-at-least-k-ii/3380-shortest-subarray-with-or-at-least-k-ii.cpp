class Solution {
public:
void addFreq(int num,vector<int>&freq,int &res){
    int idx=0;
    res=res|num;
    for(int i=0;i<32;i++){
        freq[i]+=(num&(1<<i))?1:0;
    }
}
void removeFreq(int num,vector<int>&freq,int &res){
    int idx=0;
    for(int i=0;i<32;i++){
        freq[i]+=(num&(1<<i))?-1:0;
        if(freq[i]==0)res=res &(~(1<<i));//unsetting that bit
    }
}
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>freq(32,0);int ans=INT_MAX;
        int i=0,j=0;int res=0;
        while(j<nums.size()){
            addFreq(nums[j],freq,res);
            while(i<=j && res>=k){
                ans=min(ans,j-i+1);
                removeFreq(nums[i++],freq,res);
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};