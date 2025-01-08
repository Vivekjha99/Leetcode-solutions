class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int swid) {
        int n=books.size();
        vector<int>dp(n+1,0);
        dp[0]=0;//initially no books are there so no height
        for(int i=0;i<n;i++){
            //now we start placing the books
            dp[i+1]=dp[i]+books[i][1];//stores min height for i books to be placed
            //we have taken assumption that new shelf will be required but we will try checking if the current book can be placed in some previous shelf
            int sum=0,h=0;
            for(int j=i;j>=0;j--){
                sum+=books[j][0];
                if(sum>swid){
                    //we cannot squeeze the book in the previous layer it is already full
                    //we know this because we are including the ith book also as j starts from i
                    break;//no option new shelf required
                }
                else{
                    //we will find the max height of this shelf
                    h=max(h,books[j][1]);
                    dp[i+1]=min(dp[i+1],dp[j]+h);
                }
            }
        }
        return dp[n];
    }
};