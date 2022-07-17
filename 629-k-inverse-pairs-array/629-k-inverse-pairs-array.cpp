#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;

    int kInversePairs(int n, int k) {


        vector<vector<ll>> dp(n + 1, vector<ll> (k + 1, 0));
        vector<vector<ll>> aux(n + 1, vector<ll> (k + 1 , 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
            aux[i][0] = 1;
        }

        for (int j = 0; j <= k; j++) {
            dp[0][j] = 0;
            aux[0][j] = 0;
        }



        for (int i = 1; i <= n; i++) {
            int rowSum = 1;
            for (int j = 1; j <= k; j++) {


                dp[i][j] =  (aux[i - 1][j] % mod - (j - i >= 0 ? aux[i - 1][j - i] % mod : 0) + mod) % mod;
                aux[i][j] = (aux[i][j - 1] % mod + dp[i][j] % mod) % mod;
            }


        }



        return dp[n][k];



    }
};