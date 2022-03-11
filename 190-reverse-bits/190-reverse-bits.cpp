class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int x=0;
        for(int i=0;i<=31;i++){
            int mask=1<<i;
            if(mask&n)
                x+=1<<(31-i);
        }
        return x;
    }
};