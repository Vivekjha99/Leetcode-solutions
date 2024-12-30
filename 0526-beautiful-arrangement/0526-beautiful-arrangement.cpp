class Solution {
public:
    void countPerms(int n, int curr, vector<bool>& placed, int& res) {
        if (curr > n) {
            // we have completed one permutation
            res++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!placed[i] && (curr % i == 0 || i % curr == 0)) {
                placed[i] = true;
                countPerms(n, curr + 1, placed, res);
                placed[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        if (n < 4)
            return n;
        vector<bool> placed(n + 1, false);
        int res = 0;
        countPerms(n, 1, placed, res);
        return res;
    }
};