class FoodRatings {
public:
    unordered_map<string, int> foodRatingMap;  
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, set<pair<int,string>>> cuisineFoodMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size();i++) {
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            cuisineFoodMap[cuisines[i]].insert({-1 * ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        // Fetch cuisine name for food.
        auto cuisineName = foodCuisineMap[food];

        // Find and delete the element from the respective cuisine's set.
        auto oldElementIterator = cuisineFoodMap[cuisineName].find({ -foodRatingMap[food], food });
        cuisineFoodMap[cuisineName].erase(oldElementIterator);

        // Update food's rating in 'foodRating' map.
        foodRatingMap[food] = newRating;
        // Insert the '(-1 * new rating, name)' element in respective cuisine's set.
        cuisineFoodMap[cuisineName].insert({ -newRating, food });
    }
    
    string highestRated(string cuisine) {
        auto highestRated = *cuisineFoodMap[cuisine].begin();
        // Return name of the highest rated 'food' of 'cuisine'.
        return highestRated.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
