class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        deque<int>dq;
        vector<int>res(n,0);dq.push_back(n-1);
        for(int i=n-2;i>=0;i--){
            while(!dq.empty() && temperatures[dq.front()]<=temperatures[i])dq.pop_front();
            if(!dq.empty() && temperatures[dq.front()]>temperatures[i]){
                res[i]=dq.front()-i;
            }
            dq.push_front(i);
        }
        return res;
    }
};