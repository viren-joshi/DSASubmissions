class MovieRentingSystem {
public:

    struct CustomComparer {
        bool operator()(const pair<int, pair<int,int>> a,const pair<int, pair<int,int>> b) const {
            if(a.first != b.first) return a.first < b.first;
            if(a.second.first != b.second.first) return a.second.first < b.second.first;
            return a.second.second < b.second.second;
        }
    };

    // map<int, int> moviePrice; // Price of a movie (wrap in a vector or another map)
    map<int, map<int, int>> shopMoviePrice;
    map<int, set<pair<int,int>>> movieShopPrice; // Map of movies, stored in order of price and shopid
    set<pair<int, pair<int,int>>, CustomComparer> cheapestRented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto entry: entries) {
            movieShopPrice[entry[1]].insert({entry[2], entry[0]});
            shopMoviePrice[entry[0]][entry[1]] = entry[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        if(!movieShopPrice.contains(movie)) {
            return ans;
        }
        int i = 0;
        for(auto mov: movieShopPrice[movie]) {
            ans.push_back(mov.second);
            i++;
            if(i==5) break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = shopMoviePrice[shop][movie];
        movieShopPrice[movie].erase({price, shop});
        cheapestRented.insert({price, {shop, movie}});
    }
    
    void drop(int shop, int movie) {
        int price = shopMoviePrice[shop][movie];
        cheapestRented.erase({price, {shop, movie}});
        movieShopPrice[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        int i = 0;
        vector<vector<int>> ans;
        for(auto mov: cheapestRented) {
            ans.push_back({mov.second.first, mov.second.second});
            i++;
            if(i == 5) break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
