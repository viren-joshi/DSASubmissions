class Solution {
public:

    int getIndex(int i, int j) {
        return ((i) * (i + 1)) / 2 + j;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<pair<int,int>> dp((triangle.size() * (triangle.size() + 1))/2, {-1,INT_MIN});

        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        };
        for(int i = triangle.size() - 1; i>=0; i--) {
            for(int j = 0; j <= i; j++) {
                int index = getIndex(i,j);
                if(i == triangle.size() - 1) {
                    dp[index] = {-1, triangle[i][j]};
                } else {
                    int below = getIndex(i+1, j);
                    int adj = getIndex(i+1, j+1);
                    auto [dest, cost] = min(dp[below], dp[adj], cmp);
                    dp[index] = {dest, cost + triangle[i][j]};
                }
            }
        }
        return dp[0].second;
    }
};
