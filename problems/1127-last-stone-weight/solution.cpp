class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        int n1, n2;
        while(maxHeap.size() > 1) {
            n1 = maxHeap.top();
            maxHeap.pop();
            n2 = maxHeap.top();
            maxHeap.pop();
            if(n1 != n2) {
                maxHeap.push(abs(n1-n2));
            }
        }
        return maxHeap.size() == 1? maxHeap.top(): 0; 
    }
};
