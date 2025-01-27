//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
  public:
    
    LRUCache(int cap) : capacity(cap) {}

    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            cache.splice(cache.begin(), cache, mp[key]);
            mp[key]->second = value;
            return;
        }
        if (cache.size() == capacity) {
            auto lru = cache.back().first;
            mp.erase(lru);
            cache.pop_back();
        }
        cache.emplace_front(key, value);
        mp[key] = cache.begin();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends