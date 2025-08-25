class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();

        // Diagonals mean the number of ups and downs to read the matrix.
        int diagonals = (2*max(m,n) - 1) - (max(m,n) - min(m,n));
        int i = 0, j = 0;
        bool up = true;
        while(diagonals > 0) {
            while(i < m && j < n && i >=0 && j>=0) {
                ans.push_back(mat[i][j]);
                if(up) {
                    // Moving Diagonally Upwards
                    i--;
                    j++;
                } else {
                    // Moving Diagonally Downwards
                    i++;
                    j--;
                }
            }
            if(up) {
                
                if(j >= n) {
                    // If hopping into next row, same column
                    j--;
                    i+=2;
                } else {
                    // If hopping into next column, same row
                    i=0;
                }
            } else {
                if(i >= m) {
                    // If hopping into next column, same row
                    i--;
                    j+=2;
                } else {
                    // If hopping into next row, same column
                    j=0;
                }
            }
            up = !up;
            diagonals--;
        }
        return ans;
    }
};
