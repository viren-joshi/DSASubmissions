class Solution {
public:

    int findMax(vector<vector<int>>& requests, vector<int>& nodes, int n, int count,int index) {
        if(index == requests.size()){
            for(int i=0;i<nodes.size();i++){
                if(nodes[i] != 0){
                    return 0;
                }
            }
            return count;
        }
        nodes[requests[index][0]]--;
        nodes[requests[index][1]]++;
        int take = findMax(requests, nodes, n, count+1, index+1);

        nodes[requests[index][0]]++;
        nodes[requests[index][1]]--;
        int dontTake = findMax(requests, nodes, n, count, index+1);

        return max(take, dontTake);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> nodes(n,0);
        return findMax(requests,nodes,n,0,0);
    }
};