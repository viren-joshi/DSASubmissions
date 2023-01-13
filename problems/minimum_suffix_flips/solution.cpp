class Solution {
public:
    int minFlips(string target) {
        int len = target.size(),count = 0;
        for(int i = 0; i < len ; i++){
            if(count%2==0){
                if(target[i] == '1') {
                    count++;
                }
            } else {
                if(target[i] == '0') {
                    count++;
                }
            }
        }
        return count;
    }
};