class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 1ll * k * (k + 1) / 2;
        set<int> st(nums.begin(), nums.end());
        for (auto x : st) {
            if (x <= k) {
                res +=(++k)-x ;
            }
        }
        return res;
    }
};