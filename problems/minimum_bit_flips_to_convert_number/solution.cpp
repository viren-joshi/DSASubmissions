class Solution {
public:
    int minBitFlips(int start, int goal) {
     int xored = start ^ goal, count = 0;
     while(xored != 0){
        if(xored%2 == 1) count++;
        xored/=2;
     }
     return count;
    }
};