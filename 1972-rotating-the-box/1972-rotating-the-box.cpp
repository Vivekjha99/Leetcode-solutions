class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>>arr(n,vector<char>(m,'.'));
        for(int i=0;i<m;i++){
            for(int j=n-1,k=n-1;j>=0;j--){
                if(box[i][j]!='.'){
                    k=(box[i][j]=='*'?j:k);
                    arr[k--][m-1-i]=box[i][j];
                }
            }
        }
        return arr;
    }
};