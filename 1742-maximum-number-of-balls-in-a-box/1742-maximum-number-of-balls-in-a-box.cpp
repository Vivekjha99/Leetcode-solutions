class Solution {
public:
    int solve(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        vector<int>boxes(100005,0);
        int maxi=0;
        for(int i=lowLimit;i<=highLimit;i++){
            int x=solve(i);
            boxes[x]++;
            maxi=max(maxi,boxes[x]);
        }
        return maxi;
    }
};