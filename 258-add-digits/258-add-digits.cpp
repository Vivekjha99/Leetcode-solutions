class Solution {
public:
    int addDigits(int n) {
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
            if(n==0){
                if(sum/10==0)return sum;
                n=sum;
                sum=0;
            }
        }
        return n;
    }
};