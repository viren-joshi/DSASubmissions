class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        string term;
        int temp, minDiff = INT_MAX, n = timePoints.size(), h,m;
        for(auto& p : timePoints) {
            h = stoi(p.substr(0,2));
            m = stoi(p.substr(3));
            temp = h*60 + m;
            time.push_back(temp);
        }
        sort(time.begin(), time.end());
        for(int i =0; i<time.size() - 1; i++) {
            minDiff = min(minDiff, time[i+1]-time[i]);
        }
        minDiff = min(minDiff, 24 * 60 - time.back() + time.front());
        return minDiff;
    }
};