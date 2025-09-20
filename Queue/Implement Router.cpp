class Router {
public:
    queue<vector<int>> packets; //stores all packets as they come
    unordered_map<int, unordered_map<int, unordered_set<int>>> packs; //used to check if packet already exists
    unordered_map<int, deque<int>> packsToDest; //store all timestamps going to a dest
    int maxPacks;

    Router(int memoryLimit){ maxPacks = memoryLimit; }
   
    vector<int> forwardPacket(){
        if (packets.size() == 0){ return {}; }

        vector<int> ans = packets.front();
        packets.pop();
        packs[ans[0]][ans[1]].erase(ans[2]);
        packsToDest[ans[1]].pop_front();
        return ans;
    }

    bool addPacket(int source, int destination, int timestamp){
        if (packs.find(source) != packs.end() && packs[source].find(destination) != packs[source].end() && packs[source][destination].find(timestamp) != packs[source][destination].end()){ return 0; }

        packets.push({source, destination, timestamp});
        packs[source][destination].insert(timestamp);
        packsToDest[destination].push_back(timestamp);

        if (packets.size() > maxPacks){ forwardPacket(); }
        return 1;
    }
    
    int getCount(int destination, int startTime, int endTime){
        if (packsToDest[destination].size() == 0){ return 0; }

        int l = lower_bound(packsToDest[destination].begin(), packsToDest[destination].end(), startTime) - packsToDest[destination].begin();
        int r = upper_bound(packsToDest[destination].begin(), packsToDest[destination].end(), endTime) - packsToDest[destination].begin();
        return r - l;
    }
};
