class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>>freq(256,{0,0});
        for(auto x:s){
            int i=x;
            freq[i].first++;
            freq[i].second=x;
        }
        sort(freq.rbegin(),freq.rend());
//         for(int i=0;i<256;i++){
//             cout<<freq[i].first<<" "<<freq[i].second<<endl;
    
//         }
        string ans="";
        for(int i=0;i<256;i++){
            if(freq[i].first){
                while(freq[i].first--)ans.push_back(freq[i].second);
            }
        }
        return ans;
        
    }
};