class Solution {
public:
    vector<int>counter(string s){
        vector<int>counts(26,0);
        for(auto x:s){
            counts[x-'a']++;
        }
        return counts;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int>counts(26,0),v(26,0);
        //we will store the max frequency of each character we need
        for(auto s:words2){
            v=counter(s);
            for(int i=0;i<26;i++){
                counts[i]=max(counts[i],v[i]);
            }
        }
        vector<string>ans;
        for(auto s:words1){
            v=counter(s);
            int i=0;
            while(i<26){
                if(v[i]<counts[i])break;
                i++;
            }
            if(i==26)ans.push_back(s);
        }
        return ans;
    }
};