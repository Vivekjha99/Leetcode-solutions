class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(int i=arr.size()-1;i>=0;i--){
            if(mp.find(arr[i]*2)!=mp.end() || (arr[i]%2==0 && mp.find(arr[i]/2)!=mp.end())){
                return true;
            }
            mp[arr[i]]++;
            cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
        }
        return false;
    }
};