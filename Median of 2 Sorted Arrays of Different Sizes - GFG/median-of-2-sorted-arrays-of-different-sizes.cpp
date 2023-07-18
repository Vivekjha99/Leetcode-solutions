//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        
        int n1=arr1.size();
        int n2=arr2.size();
        if(n1>n2)return MedianOfArrays(arr2,arr1);
        int l=0,r=n1;
        while(l<=r){
            int cnt1=(l+r)>>1;
            int cnt2=(n1+n2+1)/2-cnt1;
            int left1=cnt1==0?INT_MIN:arr1[cnt1-1];
            int left2=cnt2==0?INT_MIN:arr2[cnt2-1];
            int right1=cnt1==n1?INT_MAX:arr1[cnt1];
            int right2=cnt2==n2?INT_MAX:arr2[cnt2];
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2==0){
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }
                else
                return max(left1,left2);
            }
            else if (left1>right2){
                r=cnt1-1;
            }
            else
                l=cnt1+1;
                
        }
        return 0.0;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends