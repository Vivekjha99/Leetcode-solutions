class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char>v={'A','C','G','T'};
        unordered_set<string>st;
        for(auto &x:bank)st.insert(x);
        if(st.find(end)==st.end())return -1;
        queue<string>q;
        int steps=0;
        q.push(start);
        while(!q.empty()){
            int sz=q.size();
            steps+=1;
            while(sz--){
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    for(int j=0;j<4;j++){
                        temp[i]=v[j];
                        if(temp.compare(end)==0)return steps;
                        if(temp.compare(curr)==0)continue;
                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return -1;
    }
};