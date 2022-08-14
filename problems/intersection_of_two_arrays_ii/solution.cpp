class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        map<int,int> m;
        for(auto i=nums1.begin();i!=nums1.end();++i){
            if(m.find(*i) != m.end()){
                m[*i]++;
            } else {
                m.insert({*i,1});
            }
        }
        for(auto i=nums2.begin();i!=nums2.end();++i){
            if(m.find(*i) != m.end()){
                if(m[*i]>0){
                    m[*i]--;
                    v.push_back(*i);
                }
            }
        }
        return v;
    }
};