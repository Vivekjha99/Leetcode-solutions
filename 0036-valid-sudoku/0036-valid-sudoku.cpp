class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols, boxes;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char val = board[i][j];
                if (val != '.') {
                    if (rows[i].find(val) != rows[i].end())
                        return false;
                    if (cols[j].find(val) != cols[j].end())
                        return false;
                    int boxNo = (i / 3)*3 + j / 3;
                    if (boxes[boxNo].find(val) != boxes[boxNo].end())
                        return false;
                    rows[i].insert(val);
                    cols[j].insert(val);
                    boxes[boxNo].insert(val);
                }
            }
        }
        return true;
    }
};