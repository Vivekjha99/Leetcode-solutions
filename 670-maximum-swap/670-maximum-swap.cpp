class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int maxi=0,maxidx=-1,lidx=-1,ridx=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(maxi<s[i]){
                maxi=s[i];
                maxidx=i;
                continue;
            }
            if(maxi>s[i]){
                lidx=i;
                ridx=maxidx;
            }
        }
        if(lidx==-1){
            //all nos are present in right place
            return num;
        }
        swap(s[lidx],s[ridx]);
        return stoi(s);
    }
};