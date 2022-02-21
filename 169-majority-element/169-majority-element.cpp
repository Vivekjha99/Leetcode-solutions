class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=-1,freq=0;
        for(auto x:nums){
            if(x!=ele){
                if(freq==0){
                ele=x;
                freq=1;
                }
                else freq--;
            }
            else if(x==ele)freq++;
        }
        return ele;
    }
};