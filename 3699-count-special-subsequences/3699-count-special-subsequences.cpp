class Solution {
public:
        long long numberOfSubsequences(vector<int>& A) {
        int n = A.size();
        long long res = 0;
        unordered_map<double, int> cnt;
        for (int r = 3; r < n - 2; ++r) {
            int q = r - 2;
            for (int p = 0; p < q - 1; ++p)
                cnt[1.0 * A[p] / A[q]]++;
            for (int s = r + 2; s < n; ++s)
                res += cnt[1.0 * A[s] / A[r]];
        }
        return res;
    }
};