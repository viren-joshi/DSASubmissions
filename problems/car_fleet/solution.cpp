class Solution {
public:

    static bool comparator(const pair<int,int> &a, const pair<int,int> &b) {
        return a.first > b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> ps;
        stack<float> dStack;
        float tempTime;
        int fleets=0;
        for(int i=0; i<position.size(); i++) {
            ps.push_back({position[i],speed[i]});
        }
        sort(ps.begin(),ps.end(), comparator);
        // 0 3 5 8 10
        // 1 3 1 4 2  
        for(int i = 0; i < ps.size(); i++) {
            tempTime = (target - ps[i].first) / ((float) ps[i].second);
            // adding to the decreasing monotonic stack
            while(!dStack.empty() && dStack.top() < tempTime) {
                dStack.pop();
            }
            if(dStack.empty()) fleets++;
            dStack.push(tempTime);
        }
        return fleets;
    }
};