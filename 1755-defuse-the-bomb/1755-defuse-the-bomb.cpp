class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
       int n=code.size();
       int st=1,en=k;
       vector<int>res(n,0);
       if(k==0)return res;
       //last k elements
       if(k<0){
        k*=-1;
        st=n-k;
        en=n-1;
       }
       int sum=0;
       
       for(int i=st;i<=en;i++)sum+=code[i];
       for(int i=0;i<n;i++){
        res[i]=sum;
        sum-=code[(st++)%n];
        sum+=code[(++en)%n];
       }
       return res;
    }
};