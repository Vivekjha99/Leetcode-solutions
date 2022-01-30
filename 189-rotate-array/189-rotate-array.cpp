class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        int cnt=0;//tracks no of numbers rotated
        int start=0,curr=0;
        while(cnt<n){
            curr=start;
            int prev=nums[curr];
            while(true){
                int temp=nums[(curr+k)%n];
                nums[(curr+k)%n]=prev;
                prev=temp;
                curr=(curr+k)%n;
                cnt++;
                if(curr==start)break;
            }
            start++;
        }
    }
};