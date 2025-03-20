class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Brute-Force Solution
        int temp;
        for(int i=0; i<arr.size(); i++) {
            temp = arr[i] * 2;
            for(int j=0; j<arr.size(); j++) {
                if(i==j) continue;
                if (temp == arr[j]) return true;
            }
        }
        return false;
    }
};
