class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp1;
        for(auto w:words){
            mp1[w]++;
        }
        vector<int>ans;
        int n=s.size();
        int l=words.size();
        if(n==0 || l==0)return ans;
        int sz=words[0].size();
        for(int i=0;i<n-l*sz+1;i++){
            //we will start from each index and see if we find the word
            unordered_map<string,int>mp2;
            int j=0;
            for(;j<l;j++){
                string s1=s.substr(i+j*sz,sz);
                if(mp1.find(s1)!=mp1.end()){
                    mp2[s1]++;
                    if(mp2[s1]>mp1[s1])break;
                }
                else break;
              
            }
            if(j==l){
                //we have found all the words
                ans.push_back(i);
            }
        }
        return ans;
    }
};