/*

Intuition
At every step, pick two numbers a and b.
Replace them with all possible results of a op b.
Keep repeating until only one number remains.
If that number ≈ 24, return true.

Approach
    Convert input cards into a List (to handle division properly).

    Use DFS + backtracking:
        If only one number remains:
        Check if it’s approximately 24 (within small epsilon, 1e-6).
        Otherwise:
            Pick any two numbers a, b.
            Remove them, compute all possible results (a+b, a-b, b-a, a*b, a/b, b/a).
        Recurse with the new list.
        Backtrack.
    If any recursive branch yields 24, return true.

Complexity
Time complexity: O(1)
Space complexity: O(1)

*/


class Solution {
    const double EPS = 1e-6;
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int n: cards) nums.push_back((double) n);
        return dfs(nums);
    }

    bool dfs(vector<double>& nums) {
        if(nums.size() == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }

        for(int i = 0; i<nums.size(); i++) {
            for(int j = 0; j<nums.size(); j++) {
                if (i == j) continue;

                vector<double> temp;
                for (int k = 0; k<nums.size(); k++) {
                    if(k!=i && k!=j) temp.push_back(nums[k]);
                }

                for(double val: compute(nums[i], nums[j])) {
                    temp.push_back(val);
                    if(dfs(temp)) return true;
                    temp.pop_back();
                }

            }
        }
        return false;
    }

    vector<double> compute(double a, double b) {
        vector<double> ans;
        ans.push_back(a + b);
        ans.push_back(a - b);
        ans.push_back(b - a);
        ans.push_back(a * b);
        if(fabs(b) > EPS) ans.push_back(a/b);
        if(fabs(a) > EPS) ans.push_back(b/a);
        return ans;

    }

};
