class Solution {
public:

    double calculateGain(int passes, int totalStudents) {
        return (double) (passes + 1) / (totalStudents + 1) - ((double)passes / totalStudents);
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> maxHeap;

        for(int i=0; i<classes.size(); i++) {
            maxHeap.push({calculateGain(classes[i][0], classes[i][1]), i});
        }

        
        while(extraStudents--) {
            auto [gain, temp] = maxHeap.top();
            maxHeap.pop();
            classes[temp][0]++;
            classes[temp][1]++;
            maxHeap.push({calculateGain(classes[temp][0], classes[temp][1]), temp});
        }
        
        double sum = 0;
        for(int i=0; i<classes.size();i++) {
            sum += ((double)classes[i][0] /(double) classes[i][1]);
        }
        return sum/classes.size();
    }
};
