class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n=board.size();
        int cnt=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    //left
                    int idx=j-1;
                    while(idx>=0 && board[i][idx]!='B'){
                        if(board[i][idx]=='p'){
                            cnt++;
                            break;
                        }
                        idx--;
                    }
                    idx=j+1;
                    while(idx<8 && board[i][idx]!='B'){
                        if(board[i][idx]=='p'){
                            cnt++;
                            break;
                        }
                        idx++;
                    }
                    idx=i-1;
                    while(idx>=0 && board[idx][j]!='B'){
                        if(board[idx][j]=='p'){
                            cnt++;
                            break;
                        }
                        idx--;
                    }
                    idx=i+1;
                    while(idx<8 && board[idx][j]!='B'){
                        if(board[idx][j]=='p'){
                            cnt++;
                            break;
                        }
                        idx++;
                    }
                    break;
                }
            }
        }
        return cnt;
    }
};