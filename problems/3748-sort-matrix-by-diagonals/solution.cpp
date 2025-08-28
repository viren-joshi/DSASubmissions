class Solution {
public:
    // Heap Implementation
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int diagonals = 2 * grid.size() - 1;
        int lower = diagonals / 2 + 1;
        int upper = diagonals - lower;
        vector<priority_queue<int>> desc(lower);
        vector<priority_queue<int, vector<int>, greater<int>>> asc(upper);

        for(int i = 0; i<grid.size(); i++) {
            for(int j = 0; j< grid.size(); j++) {
                if(j > i) {
                    // Upper Triangle
                    asc[j-i-1].push(grid[i][j]);
                } else {
                    // Lower Traiangle
                    desc[i-j].push(grid[i][j]);
                }
            }
        }

        for(int i = 0;i<grid.size(); i++) {
            for(int j = 0; j< grid.size(); j++) {
                if(j > i) {
                    grid[i][j] = asc[j-i-1].top();
                    asc[j-i-1].pop();
                } else{
                    grid[i][j] = desc[i-j].top();
                    desc[i-j].pop();
                }
            }
        }
        return grid;
    }
};
