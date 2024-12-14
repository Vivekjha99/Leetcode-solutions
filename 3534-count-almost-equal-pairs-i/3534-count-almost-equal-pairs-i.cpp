class Solution {
public:
bool check(int a, int b){
    string s1=to_string(a);
    string s2=to_string(b);
    while(s1.length()<s2.length())s1='0'+s1;
    while(s2.length()<s1.length())s2='0'+s2;
    int diff=0;
    int firstIdx=-1,secondIdx=-1;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            diff++;
            if(diff==1)firstIdx=i;
            else if(diff==2)secondIdx=i;
            else return false;
        }
    }
    if(diff==2)
    swap(s1[firstIdx],s1[secondIdx]);
    return s1==s2;
}
    int countPairs(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j] || check(nums[i],nums[j]))ans++;
            }
        }
        return ans;
    }
};