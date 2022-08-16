class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int>q;
        unordered_map<int,bool>vis;
        int ans=0;
        q.push(start);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                q.pop();
                if(curr==goal)return ans;
                if(curr>1000 || curr<0 || vis[curr])
                    continue;
                vis[curr]=true;
                for(int i=0;i<nums.size();i++){
                    int a=curr+nums[i];
                    int b=curr-nums[i];
                    int c=curr^nums[i];
                    q.push(a);
                    q.push(b);
                    q.push(c);
                }
            }
            ans++;
        }
        return -1;
    }
};