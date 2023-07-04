class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> numbers;
        for(auto i: nums){
            numbers[i]++;
        }
        for(auto i : numbers) {
            if(i.second == 1){
                return i.first;
            }
        }
        return 0;
    }
};