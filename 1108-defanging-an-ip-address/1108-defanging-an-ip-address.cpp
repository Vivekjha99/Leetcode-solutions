class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        for(auto x:address){
            if(x=='.'){
                ans+="[.]";
            }
            else ans.push_back(x);
        }
        return ans;
        
    }
};