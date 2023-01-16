class Solution {
public:
    int maxVal(const int& n1, const int& n2){
        if(n1>=n2) return n1;
        else return n2;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            //case 1 occurs
            if(intervals[i][0] > newInterval[1]){
                ans.push_back(newInterval);
                newInterval = intervals[i]; 
            }

            //case 2 occurs
            else if(intervals[i][1] < newInterval[0]){ans.push_back(intervals[i]);}       
    
            //case 3 occurs
            else if(intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1]){
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        //final step
        ans.push_back(newInterval); 
        return ans;
    }
};