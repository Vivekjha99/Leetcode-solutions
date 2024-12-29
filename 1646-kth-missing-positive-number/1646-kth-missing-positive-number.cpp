class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int>st(arr.begin(),arr.end());
        int curr=0;
        while(k>0){
            curr++;
            if(st.find(curr)==st.end())
                k--;
        }
        return curr;

        
    }
};