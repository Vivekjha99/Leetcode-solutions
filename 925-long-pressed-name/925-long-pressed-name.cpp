class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n=name.size();
        int m=typed.size();
        int i=0;
        for(int j=0;j<m;j++){
            if(i<n && name[i]==typed[j])i++;
            else if(j==0 || typed[j]!=typed[j-1])return false;
        }
        return i==n;
    }
};