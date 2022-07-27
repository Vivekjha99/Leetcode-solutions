class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string>st;
        vector<string>v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto s:words){
            string res="";
            for(auto ch:s){
                res+=v[ch-'a'];
            }
            st.insert(res);
        }
        return st.size();
    }
};