class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i,j;
        unordered_set<int> rowSet, colSet, boxSet;

        for(i=0; i<9; i++) {
            for(j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    if(rowSet.count(board[i][j]) == 1)
                    return false;
                    rowSet.insert(board[i][j]);
                }
                if(board[j][i] != '.') {
                    if(colSet.count(board[j][i]) == 1)
                    return false;
                    colSet.insert(board[j][i]);
                }
            }
            rowSet.clear();
            colSet.clear();
        }

        for(i=0;i<9;i+=3)  {
            for(j=0;j<9;j+=3) {
                boxSet.clear();
                for(int x = i; x<i+3;x++) {
                    for(int y=j; y<j+3;y++) {
                        if(board[x][y] != '.') {
                            if(boxSet.count(board[x][y]) == 1)
                            return false;
                            boxSet.insert(board[x][y]);
                        }
                    }
                }
            }
        }
        return true;
        
    }
};