class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        vector<long long>nums1,nums2;
        int sz1=hc.size();
        int sz2=vc.size();
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        if(sz1==1){
            nums1.push_back(hc[0]);
            nums1.push_back(h-hc[0]);
        }
        else{
        for(int i=0;i<sz1;i++){
            if(i==0)nums1.push_back(hc[0]);
            else if(i==sz1-1){
                nums1.push_back((long long)(hc[i]-hc[i-1]));
                nums1.push_back((long long)(h-hc[i]));
            }
            else
                nums1.push_back((long long)(hc[i]-hc[i-1]));
        }
        }
        if(sz2==1){
            nums2.push_back(vc[0]);
            nums2.push_back((long long)(w-vc[0]));
        }
        else{
        for(int i=0;i<sz2;i++){
            if(i==0)nums2.push_back(vc[0]);
            else if(i==sz2-1){
                nums2.push_back((long long)(vc[i]-vc[i-1]));
                nums2.push_back((long long)(w-vc[i]));
            }
            else
                nums2.push_back((long long)(vc[i]-vc[i-1]));
        }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(auto x:nums1){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:nums2)cout<<x<<" ";
        cout<<endl;
        long long ans=nums1.back()*nums2.back();
        int mod=1e9+7;
        // cout<<endl;
        return ans%mod;
    }
};