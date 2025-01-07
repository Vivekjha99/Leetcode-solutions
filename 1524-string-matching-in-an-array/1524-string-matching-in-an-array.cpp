class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>res;
        for(auto s1:words){
            for(auto s2:words){
                if(s1!=s2 && s2.find(s1)!=-1){
                    res.push_back(s1);
                    break;
                }
            }
        }
        return res;
    }
};