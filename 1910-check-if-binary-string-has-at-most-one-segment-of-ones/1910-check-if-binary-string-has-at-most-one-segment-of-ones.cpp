class Solution {
public:
    bool checkOnesSegment(string s) {
        int currIdx=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(currIdx==-1)currIdx=i;
                else if(i-currIdx>1)return false;
                currIdx=i;
            }
        }
        return true;

    }
};