class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int sb2=__builtin_popcount(num2);
        int x=0;
        int sb1=__builtin_popcount(num1);
        if(sb1==sb2)return num1;
        for(int i=31;i>=0;i--){
            if(num1 & 1<<i){
                x|=1<<i;
                sb2--;
            }
            if(sb2==0)break;
        }
        if(sb2>0){
            for(int i=0;i<=31;i++){
                if((num1 & (1<<i))==0){
                    x|=1<<i;
                    sb2--;
                }
                if(sb2==0)break;
            }
        }
        return x;

    }
};