class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int,char>>st;
        st.push_back({0,'*'});
        for(auto x:s){
            if(st.back().second!=x)st.push_back({1,x});
            else if(++st.back().first==k)st.pop_back();
        }
        string ans;
        for(auto x:st){
            ans.append(x.first,x.second);
        }
        return ans;
    }
};