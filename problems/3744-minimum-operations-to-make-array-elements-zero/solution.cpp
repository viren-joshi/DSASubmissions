class Solution {
public:
    long long solve(long long a, long long b) {
        long long L=1, step = 1, res = 0;
        long long R, maxi, mini;
        while(L <= b) {
            R = 4*L - 1;
            maxi = max(L,a);
            mini = min(R,b);
            if(maxi<=mini) {
                res += (mini - maxi + 1) * step;
            }
            L*=4;
            step++;
        }
        return res;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long count = 0;
        for(auto query: queries) {
            count += (solve(query[0], query[1]) + 1) / 2;
        }
        return count;
    }
};
