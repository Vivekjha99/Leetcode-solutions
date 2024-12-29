class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int st=0,en=n;
        while(st<en){
            int mid=st+(en-st)/2;
            int missingNo=arr[mid]-mid-1;
            if(k<=missingNo){
                en=mid;
            }
            else
            st=mid+1;
        }
        return en+k;
    }
};