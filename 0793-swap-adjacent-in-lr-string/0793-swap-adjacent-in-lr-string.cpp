class Solution {
public:
    bool canTransform(string start, string result) {
        int n=result.size();
        int i=0,j=0;
        while(i<=n && j<=n){
            //skipping Xs
            while(i<n && result[i]=='X')i++;
            while(j<n && start[j]=='X')j++;
            if(start[j]!=result[i])return false;
            if(start[j]=='L'){
                if(j<i)return false;
            }
            else{
                if(j>i)return false;
            }
            i++;
            j++;
        }

        return true;
    }
};