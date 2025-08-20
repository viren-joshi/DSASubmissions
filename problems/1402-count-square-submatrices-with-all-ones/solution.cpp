/*

First instinct is to have create a dp that has the data of the 1s in the prev row and cols (till that index).

Another chain of thought is that presence of one NxN square would mean that its has 4 x (N-1 x N-1) sized squares.

I wrote soem code that created a dp array of size matrix[0] (size of the first array of the matrix)
and then tried to calculate the squares. 

I also added this new variable `temp` that would store the value of matrix[i-1][j-1]
as I realised that would be important then too. 

The logic worked for the examples, but when I tried some more test cases it failed.

After another hour of trying stuff, I gave in and looked at the solution.


Learnt that sometimes a new dp is not needed, you can use the input matrix itself.
(Speat a lot of time debating if the dp would be an array or a matrix)
Also, that my logic of adding to `count` based on the values was correct, but I was wrong to think to take max().


Solution logic:
We need to check only m[i-1][j-1], m[i-1][j] and m[i][j-1] values. 

If current value is 0, then move on.
If its the first row or column then count++ (or count += m[i][j], its the same).

Else
m[i][j] is the minimum of the three values (m[i-1][j-1], m[i-1][j] and m[i][j-1]). 
count += m[i][j]

*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;

        for(int i = 0; i<matrix.size(); i++) {
            for (int j = 0; j< matrix[0].size(); j++) {
                if(matrix[i][j] == 0) continue;

                if(i > 0 && j > 0) {
                    matrix[i][j] = min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]}) + 1;
                }

                count += matrix[i][j];
            }
        }
        return count;
    }
};
