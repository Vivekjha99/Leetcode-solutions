class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ind(n,0);
        for(auto e:edges){
            ind[e[1]]++;
        }
        vector<int>nodes;
        for(int i=0;i<n;i++){
            if(ind[i]==0)nodes.push_back(i);
        }
        return nodes;
        
    }

};