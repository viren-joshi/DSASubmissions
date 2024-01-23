class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxProd = -1, tempProd, cmp;
        while(i<j) {
            cmp = min(height[i],height[j]);
            tempProd = (j-i) * cmp;
            if(tempProd > maxProd) {
                maxProd = tempProd;
            }
            if(cmp==height[i])
                i++;
            else
                j--;
        }
        return maxProd;
    }
};