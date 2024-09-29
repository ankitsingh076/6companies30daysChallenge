class AllOne {
public:
    unordered_map<string, int> umap;  // To store key-value pairs
    
    // Max heap to store pairs {count, key} for getting max key
    priority_queue<pair<int, string>> maxHeap;
    
    // Min heap to store pairs {count, key} for getting min key
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> minHeap;

    AllOne() {
        // Constructor
    }
    
    // Increment the count for the key
    void inc(string key) {
        umap[key]++;  // Increment the count in the hash map
        maxHeap.push({umap[key], key});  // Add updated pair to the maxHeap
        minHeap.push({umap[key], key});  // Add updated pair to the minHeap
    }
    
    // Decrement the count for the key
    void dec(string key) {
        if (umap.find(key) != umap.end()) {
            umap[key]--;  // Decrement the count in the hash map
            if (umap[key] == 0) {
                umap.erase(key);  // Remove the key if the count becomes 0
            } else {
                maxHeap.push({umap[key], key});  // Add updated pair to the maxHeap
                minHeap.push({umap[key], key});  // Add updated pair to the minHeap
            }
        }
    }
    
    // Get the key with the maximum value
    string getMaxKey() {
        // Clean the top of maxHeap if it's outdated (lazy removal)
        while (!maxHeap.empty() && umap[maxHeap.top().second] != maxHeap.top().first) {
            maxHeap.pop();
        }
        if (maxHeap.empty()) return "";  // If no valid elements, return empty string
        return maxHeap.top().second;  // Return the key with the max count
    }
    
    // Get the key with the minimum value
    string getMinKey() {
        // Clean the top of minHeap if it's outdated (lazy removal)
        while (!minHeap.empty() && umap[minHeap.top().second] != minHeap.top().first) {
            minHeap.pop();
        }
        if (minHeap.empty()) return "";  // If no valid elements, return empty string
        return minHeap.top().second;  // Return the key with the min count
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */