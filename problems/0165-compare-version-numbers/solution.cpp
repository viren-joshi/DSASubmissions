class Solution {
public:
    int compareVersion(string version1, string version2) {
        string temp1 = "", temp2 = "";
        int i1 = 0, i2 = 0, t1, t2;
        while (i1 < version1.size() || i2 < version2.size()) {
            while(i1 < version1.size() && version1[i1] != '.') {
                temp1+=version1[i1];
                i1++;
            }
            while(i2 < version2.size() && version2[i2] != '.') {
                temp2 +=version2[i2];
                i2++;
            }
            t1 = stoi(temp1);
            t2 = stoi(temp2);
            if(t1 > t2) return 1;
            else if (t1 < t2) return -1;
            
            if(i1 < version1.size()) {
                temp1 = "";
                i1++;
            } else {
                temp1 = "0";
            }
            if(i2 < version2.size()){
                temp2 = "";
                i2++;
            } else {
                temp2 = "0";
            }
        }
        return 0;
    }
};
