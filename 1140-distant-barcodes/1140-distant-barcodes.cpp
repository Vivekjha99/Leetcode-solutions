class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> mp;
        for (auto x : barcodes)
            mp[x]++;
        priority_queue<pair<int, int>> pq;
        for (auto [x, f] : mp) {
            pq.push({f, x});
        }
        int idx = 0;
        while (!pq.empty()) {
            auto p1 = pq.top();
            pq.pop();
            barcodes[idx++] = p1.second;
            if (pq.size() > 0) {
                auto p2 = pq.top();
                pq.pop();
                barcodes[idx++] = p2.second;
                if (p2.first - 1 > 0)
                    pq.push({p2.first - 1, p2.second});
            }
            if (p1.first - 1 > 0)
                pq.push({p1.first - 1, p1.second});
        }
        return barcodes;
    }
};