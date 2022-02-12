class Solution {
private:
    unordered_map<int,vector<int>>g;
    void make_graph(vector<vector<int>>pre){
        for(auto x:pre){
            g[x[1]].push_back(x[0]);
        }
    }
    vector<int>findindegree(int num){
        vector<int>res(num,0);
        for(int i=0;i<num;i++){
            for(auto x:g[i])res[x]++;
        }
        return res;
    }
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        make_graph(prerequisites);
        vector<int>ind=findindegree(numCourses);
        vector<int>res;
        for(int i=0;i<numCourses;i++){
           if(ind[i]==0)res.push_back(i); 
        }
        for(int i=0;i<res.size();i++){
            for(auto x:g[res[i]]){
                ind[x]--;
                if(ind[x]==0)res.push_back(x);
            }
        }
        if(res.size()==numCourses)return res;
        return {};
   
    }
};