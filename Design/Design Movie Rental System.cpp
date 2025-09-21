class MovieRentingSystem {
private:
    unordered_map<int, set<pair<int,int>>> shopList;   //{movie, {price, shop}}
    map<pair<int,int>, int> movieShopPrice;  //{price for {movie, shop}} 
    set<vector<int>> rented;   //{price, shop, movie}  
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto x : entries){
            int shop = x[0], movie = x[1], price = x[2];
            shopList[movie].insert({price, shop});
            movieShopPrice[{movie, shop}] = price;
        }
    }
    
    vector<int> search(int movie) {
        int cnt = 0; vector<int> shops;
        for(auto x : shopList[movie]){
            int price = x.first, shop = x.second;
            shops.push_back(shop); cnt++;
            if(cnt == 5) break;
        }
        return shops;
    }
    
    void rent(int shop, int movie) {
        int price = movieShopPrice[{movie, shop}];
        shopList[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = movieShopPrice[{movie, shop}];
        rented.erase({price, shop, movie});
        shopList[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res; int cnt= 0;
        for(auto x : rented){
            int price = x[0], shop = x[1], movie = x[2];
            res.push_back({shop, movie}); cnt++;
            if(cnt == 5) break;
        }
        return res;
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
