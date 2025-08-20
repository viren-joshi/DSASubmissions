/*

    The main challenge is to identify this pattern

    Modifying the letters that appear less frequently (but are not zero) in either 
        the horizontal or vertical direction increases the Manhattan distance by 2.
    Modifying the letters that appear more frequently in either direction decreases 
        the Manhattan distance by 2.
    If no modifications are made, the Manhattan distance remains unchanged.

    So we calculate the occurence of all 4 directions,
    We change the less occuring directions into the more occuring direction upto K. (+ 2 for each)
    If the less occuring direction < K, then we change the more occuring directions  (-2 for each)

*/
class Solution {
public:

    int count(int dir1, int dir2, int times) {
        return abs(dir1-dir2) + times * 2;
    }

    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east=0, west = 0;
        for(auto i : s) {
            switch(i) {
                case 'N':
                    north++;
                    break;
                case 'S':
                    south++;
                    break;
                case 'E':
                    east++;
                    break;
                case 'W':
                    west++;
                    break;
                default:
            }
            int times1 = min({north, south, k});
            int times2 = min({east, west, k - times1});

            ans = max(ans, count(east, west, times2) + count(north, south, times1));
        }
        return ans;
        
    }
};
