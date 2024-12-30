class Solution {
public:
    // void countPerms(int n, int curr, vector<bool>& placed, int& res) {
    //     if (curr > n) {
    //         // we have completed one permutation
    //         res++;
    //         return;
    //     }
    //     for (int i = 1; i <= n; i++) {
    //         if (!placed[i] && (curr % i == 0 || i % curr == 0)) {
    //             placed[i] = true;
    //             countPerms(n, curr + 1, placed, res);
    //             placed[i] = false;
    //         }
    //     }
    // }
    // int countArrangement(int n) {
    //     if (n < 4)
    //         return n;
    //     vector<bool> placed(n + 1, false);
    //     int res = 0;
    //     countPerms(n, 1, placed, res);
    //     return res;
    // }
    int getBit(int num,int pos){
	return num& 1<<pos;
}

int setBit(int num,int pos){
	return num | 1<<pos;
}
int countBeautifulArray(int pos, int mask, vector<vector<int>>& dp,int N){
	if(pos == N){
	return 1;
}
if(dp[pos][mask]!=-1)
	return dp[pos][mask];
int ans =0;
for(int i = 0; i< N; i++){
	if(getBit(mask,i)==0){
		if((i+1)%(pos+1)==0  ||(pos+1)%(i+1)==0)
		ans += countBeautifulArray(pos+1, setBit(mask,i), dp,N);
}
}
return  dp[pos][mask] = ans;
}
int countArrangement(int N) {
        int mask = 1<<15;
        vector<vector<int>> dp (N, vector<int>(mask,-1));
        return countBeautifulArray(0,0,dp,N);    
}
};