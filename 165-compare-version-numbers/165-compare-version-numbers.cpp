class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1=v1.size();
        int n2=v2.size();
        int idx1=0,idx2=0;
        while(idx1<n1 || idx2<n2){
            int num1=0,num2=0;
            while(idx1<n1 && v1[idx1]!='.')num1=num1*10+(v1[idx1++]-'0');
            while(idx2<n2 && v2[idx2]!='.')num2=num2*10+(v2[idx2++]-'0');
            if(num1>num2)return 1;
            else if(num2>num1)return -1;
            idx1++;
            idx2++;
        }
        return 0;
    }
};