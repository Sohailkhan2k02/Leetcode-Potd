class Fancy {
public:
    int mod = 1e9 + 7 ; 
    int curr ;
    vector<pair<int ,int>> ops;
    unordered_map<int ,int > d ;
    int size = 0 ;
    map<int ,int > m;

    Fancy() {
        curr = 0 ;
        size = 0 ;
    }
    
    void append(int val) {
        m[size] = val;
        d[size] = curr;
        size++;
    }
    
    void addAll(int inc) {
        curr++;
        ops.push_back({1 , inc});
    }
    
    void multAll(int m) {
        curr++;
        ops.push_back({2 , m});
    }
    
    int getIndex(int idx) {
        if(m.find(idx) == m.end()) return -1;

        long long val = m[idx];

        for(int i = d[idx]; i < ops.size(); i++){
            if(ops[i].first == 1){
                val = (val % mod + ops[i].second % mod) % mod;
            }
            else{
                val = ((val % mod) * (ops[i].second % mod)) % mod;
            }
        }

        d[idx] = ops.size();
        m[idx] = val;

        return val;
    }
};
