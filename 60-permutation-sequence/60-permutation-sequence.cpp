class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
            fact*=i;
        }
        k=k-1;
        string ans="";
        while(nums.size()>0){
            fact=fact/nums.size();
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            k=k%fact;
        }
        return ans;
        
    }
};