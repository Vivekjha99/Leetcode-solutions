class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int left=0,right=n-1;
        while(left+1<n && arr[left]<=arr[left+1])left++;
        //array already sorted
        if(left==n-1)return 0;
        while(right>left && arr[right-1]<=arr[right])right--;
        int res=min(right,n-left-1);int i=0;
        //now we will find the array in middle
        while(i<=left && right<n){
            if(arr[i]<=arr[right]){
                //we can remove the subarry between left and right
                res=min(res,right-i-1);
                i++;
            }
            //now we have to find the next element in right sorted array to make a sorted array
            else
            right++;
        }
        return res;
    }
};