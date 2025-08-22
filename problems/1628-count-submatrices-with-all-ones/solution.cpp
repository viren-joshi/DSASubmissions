/*
Gotten from Rehan Mittal.

**Intuition**
We want to count the number of submatrices that contain only 1s.

At first glance, brute force would try all possible submatrices and check validity, which would be very slow (O(m² * n²) or worse).

Instead, we can treat each row as the "base" of potential submatrices.

If we compute histogram heights of consecutive 1s ending at each row, the problem reduces to:
"For each row, count the number of rectangles formed using that row as the bottom edge."

Thus, we can apply a histogram-like DP approach.

**Approach**
1. Maintain an array h[j] representing the number of consecutive 1s in column j up to the current row i.
2. If mat[i][j] == 1, increase h[j] += 1.
3. Else reset h[j] = 0.
4. For each row i (as the bottom of submatrices):
5. For each column j, we consider rectangles ending at (i, j).
6. To count them, move leftwards (k = j, j-1, …) while tracking the minimum height seen.
7. The number of rectangles ending at (i, j) is the sum of these minimum heights.
8. Accumulate these counts into the result.

**Complexity**
Time complexity: For each row (m), for each column (n), we may scan leftwards (n again). Worst-case → O(m × n²).
Space complexity: We only keep an array of histogram heights → O(n).

*/

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> h(n,0);

        for(int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                h[j] = mat[i][j] == 1 ? h[j]+1 : 0;
            }

            for(int j = 0; j<n; j++) {
                int mn = h[j];
                for(int k = j; k>=0 && mn>0; k--) {
                    mn = min(mn,h[k]);
                    count+=mn;
                }
            }
        }
        return count;
    }
};
