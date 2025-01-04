class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix[0].size()-1,m;
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][l] <= target && matrix[i][r] >= target) {
                cout<<l<<" "<<r<<endl;
                while(l<=r) {
                    m = (l+r)/2;
                    if(matrix[i][m] == target) return true;
                    else if(matrix[i][m] > target) r = m-1;
                    else l = m+1;
                }
            }
        }
        return false;
    }
};

