class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i++]);
                // i++;
            } else if (nums1[i] > nums2[j]){
                v.push_back(nums2[j++]);
                // j++;
            } else {
                v.push_back(nums1[i++]);
                v.push_back(nums2[j++]);
                // i++;
                // j++;
            }
        }
        while(i<m){
            v.push_back(nums1[i++]);
            // i++;
        }
        while(j<n){
            v.push_back(nums2[j++]);
            // j++;
        }
        // cout<<m+n<<" "<<v.size()<<endl;
        for(int itr=0;itr<m+n;itr++){
            nums1.at(itr)=v.at(itr);
            // nums1[itr]=v[itr];
        }
    }
};