class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        vector<int>evens,odds;
        for(auto x:s){
            int d=x-'0';
            if(d%2)odds.push_back(d);
            else evens.push_back(d);
        }
        sort(odds.rbegin(),odds.rend());
        sort(evens.rbegin(),evens.rend());
        int ei=0,oi=0;
        for(int i=0;i<s.size();i++){
            int d=s[i]-'0';
            if(d%2)s[i]=odds[oi++]+'0';
            else s[i]=evens[ei++]+'0';
        }
        return stoi(s);
    }
};