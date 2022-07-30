class Solution {
    int n{0};
    int m{0};
    vector<vector<int>> fireTime;
    vector<int> rowDir, colDir;
public:
    Solution(){
        rowDir.assign({-1,+0,+1,+0});
        colDir.assign({+0,-1,+0,+1});
    }
    // check if cell indices are valid
    bool isValid(int nx, int ny, vector<vector<int>>& grid){
        if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]==2){
            return false;
        }
        return true;
    }
    // spread fire and compute time
    void spreadFire(vector<vector<int>>& grid){
        queue<pair<int,int>> gridCells;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == 1){// store cells which are initially on fire
                    gridCells.push({i, j});
                    fireTime[i][j] = 0;
                }
            }
        }
        // bfs - compute fire spreading time
        while(!gridCells.empty()){
            auto curr = gridCells.front(); gridCells.pop();
            int x = curr.first;
            int y = curr.second;
            for(int i=0; i<4; ++i){// explore 4-adjacent cells
                int nx = x + rowDir[i];
                int ny = y + colDir[i];
                if(isValid(nx, ny, grid) == false){
                    continue;
                }
                // adjacent cell have greater fire time update to smaller reachable time
                if(fireTime[nx][ny] > fireTime[x][y]+1){
                    fireTime[nx][ny] = fireTime[x][y]+1;
                    gridCells.push({nx, ny});
                }
            }
        }
    }
    
    int minTimeToReachEnd(int waitTime, vector<vector<int>>& grid){ // wait time is the time person can wait at initial position
        vector<vector<int>> personTime(n, vector<int>(m, INT_MAX));
        personTime[0][0] = waitTime;
        
        queue<pair<int,int>> gridCells;
        gridCells.push({0, 0});
        while(!gridCells.empty()){
            auto curr = gridCells.front(); gridCells.pop();
            int x = curr.first;
            int y = curr.second;
            
            for(int i=0; i<4; ++i){// explore 4-adjacent cells
                int nx = x + rowDir[i];
                int ny = y + colDir[i];
                if(isValid(nx, ny, grid) == false){
                    continue;
                }
                int currMin = min(personTime[nx][ny], personTime[x][y]+1);
                
                if(nx==n-1 && ny==m-1 && currMin <= fireTime[n-1][m-1]){ // if we reached safe house and person time is valid
                    return currMin;
                }
                if(currMin >= fireTime[nx][ny]){ // adjacent cell fire time is greater and person time, then person will die
                    continue;
                }
                
                if(personTime[nx][ny] > personTime[x][y]+1){
                    personTime[nx][ny] = personTime[x][y]+1;
                    gridCells.push({nx, ny});
                }
                 
            }
        }
        return INT_MAX;
    }
    
    int computeMaxWaitingTime(vector<vector<int>>& grid){
        // edge case:
        // if fire cannot reach safe house, then we have two possibilities
        // fire cannot spread to the path from grid(0,0) --> grid(n-1)(m-1), path exist, so answer == INFINITE
        // or fire can spread to person's path but road is blocked to reach destination, path doesnt exist, so answer is -1, i.e not reachable
        if(fireTime[n-1][m-1] == INT_MAX){
           return (minTimeToReachEnd(1e9, grid) < INT_MAX ? 1000000000 : -1);
        }
        
        // compute maxWait time for fire reachable to safe house
        int low = 0;
        int high = n*m;
        int maxWait = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            bool isReachable = minTimeToReachEnd(mid, grid) <= fireTime[n-1][m-1];
            if(isReachable){
                low = mid + 1;
                maxWait = mid;
            }else{
                high = mid - 1;
            }
        }
        
        return maxWait;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid[0].size();
        fireTime.resize(300, vector<int>(300, INT_MAX));
        spreadFire(grid);
        
        return computeMaxWaitingTime(grid);
    }
};