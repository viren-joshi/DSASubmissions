using namespace std;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<string,int>mp;
        for(auto it:obstacles) {
            string key = to_string(it[0]) + "+" + to_string(it[1]);
            mp[key]++;
        }
        int distance = 0, dirptr = 1, tempX,tempY;
        int bl[2] = {0,0};
        vector<vector<int>> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        for (auto i : commands) {
            if(i>=1 && i<=9) {
                for(int j = 1; j <= i; j++) {
                    tempX = bl[0] + dir[dirptr][0];
                    tempY = bl[1] + dir[dirptr][1];
                    if(mp.find(to_string(tempX) + "+" + to_string(tempY)) != mp.end()) {
                        break;
                    }
                    bl[0] = tempX;
                    bl[1] = tempY;
                    distance = max(distance,tempX*tempX + tempY*tempY);
                }
            } else if(i == -2) {
                // Turn Left
                dirptr = ((dirptr - 1) + 4) % 4;
            } else {
                // Turn Right
                dirptr = (dirptr + 1) % 4;
            }
        }
        return distance;
    }
};