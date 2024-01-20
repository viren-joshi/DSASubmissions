class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size() - 1, temp;

        while(i<j) {
            temp = target - numbers[i];
            if(temp == numbers[j]) {
                return {i+1,j+1};
            } else if (temp < numbers[j]) {
                j--;
            } else {
                i++;
            }
        }
        return {0,0};
    }
};