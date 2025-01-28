class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string ans="";
        int maxi=-1, h1=-1,h2=-1,m1=-1,m2=-1;
        for(int i=0;i<4;i++){
            if(arr[i]>2)continue;
            for(int j=0;j<4;j++){
                if(i==j)continue;
                if(arr[i]==2 && arr[j]>3)continue;
                for(int k=0;k<4;k++){
                    if(i==k || j==k)continue;
                    if(arr[k]>5)continue;
                    int l=6-i-j-k;
                    if(l==i || l==j || l==k)continue;
                    int val=(arr[l]+arr[k]*10)+(arr[i]*10+arr[j])*60;
                    if(maxi<val){
                        maxi=val;
                        h1=arr[i];
                        h2=arr[j];
                        m1=arr[k];
                        m2=arr[l];
                    }
                }
            }
        }
        if(h1==-1 || h2==-1 || m1==-1 || m2==-1)return "";
        ans=to_string(h1)+to_string(h2)+":"+to_string(m1)+to_string(m2);
        return ans;
    }
};