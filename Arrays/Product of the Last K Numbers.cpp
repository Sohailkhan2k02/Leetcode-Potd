class ProductOfNumbers {
private:
    vector<int> ans;  // Stores prefix product

public:
    ProductOfNumbers() {
        ans.push_back(1);  
    }
    
    void add(int num) {
        if (num == 0) {
            ans.clear();
            ans.push_back(1); 
        } else {
            ans.push_back(ans.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= ans.size()) return 0;
        return ans.back() / ans[ans.size() - k - 1];
    }
};
