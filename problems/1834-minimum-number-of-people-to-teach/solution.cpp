class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> peopleToTeach;

        for(auto friendship: friendships) {
            int person1 = friendship[0] - 1;
            int person2 = friendship[1] - 1;
            bool cancom = false;

            for(int lang1: languages[person1]) {
                for(int lang2: languages[person2]) {
                    if(lang1 == lang2) {
                        cancom = true;
                        break;
                    }
                }
                if(cancom) break;
            }
            if(!cancom) {
                peopleToTeach.insert(person1);
                peopleToTeach.insert(person2);
            }
        }

        int maxCount = 0;
        vector<int> count(n+1, 0);
        for(auto person: peopleToTeach) {
            for(int lan: languages[person]) {
                count[lan]++;
                maxCount = max(maxCount, count[lan]);
            }
        }

        return peopleToTeach.size() - maxCount;
    }
};
