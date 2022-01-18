class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz=flowerbed.size();
        int f=0;
        for(int i=0;i<sz;i++){
            if(flowerbed[i]==0){
                int left=(i==0||flowerbed[i-1]==0)?0:1;
                int right=(i==sz-1||flowerbed[i+1]==0)?0:1;
                if(left==0 && right==0){
                    f++;
                    flowerbed[i]=1;
                }
            }
        }
            return f>=n;
    }
};