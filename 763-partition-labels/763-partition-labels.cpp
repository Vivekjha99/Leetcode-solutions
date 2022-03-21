class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>nums(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            nums[s[i]-'a']=i;
        }
        vector<int>ans;int st=0,e=INT_MIN;
        for(int i=0;i<n;i++){
            e=max(e,nums[s[i]-'a']);
            if(e==i){
                ans.push_back(e-st+1);
                st=i+1;
            }
        }
        return ans;
    }
};