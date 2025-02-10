class Solution {
public:
    int getGCD(int a, int b) {
        if (b == 0) return a;
        return getGCD(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        int min_num = *min_element(nums.begin(), nums.end());
        int max_num = *max_element(nums.begin(), nums.end());
        return getGCD(min_num, max_num);
    }
};
