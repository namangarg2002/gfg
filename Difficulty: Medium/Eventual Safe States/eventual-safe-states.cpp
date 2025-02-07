//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int src, unordered_map<int, bool>&visit, unordered_map<int, bool>&dfsTrack, vector<int> adj[]){
        visit[src] = true;
        dfsTrack[src] = true;
        for(auto child:adj[src]){
            if(!visit[child]){
                if(dfs(child, visit, dfsTrack, adj)){
                    return true;
                }
            }else{
                if(visit[child]==true && dfsTrack[child]){
                    return true;
                }
            }
        }
        dfsTrack[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int, bool>visit;
        unordered_map<int, bool> dfsTrack;
        for(int i=0; i<V; i++){
            if(!visit[i]){
                dfs(i, visit, dfsTrack, adj);
            }
        }
        for(int i=0; i<V; i++){
            if(!dfsTrack[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends