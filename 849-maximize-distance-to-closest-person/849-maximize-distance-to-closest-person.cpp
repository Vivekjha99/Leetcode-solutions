class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int last=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(seats[i]){
                ans=last<0?i:max(ans,(i-last)/2);
                last=i;
            }
        }
        ans=max(ans,(n-1-last));
        return ans;
    }
};