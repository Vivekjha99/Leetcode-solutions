class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int>pq;
        vector<int>res;
        for(auto q:queries){
            int d=abs(q[0])+abs(q[1]);
            pq.push(d);
            while(pq.size()>k)pq.pop();
            if(pq.size()<k)res.push_back(-1);
            else res.push_back(pq.top());
        }
        return res;
    }
};