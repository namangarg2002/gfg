//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getMinValueNode(vector<int>&key, vector<int>&MST){
        int temp = INT_MAX;
        int index = -1; // represent node Having Min value
        for(int i=0; i<key.size(); i++){
            if(key[i] < temp && MST[i]==false){
                temp = key[i];
                index = i;
            }
        }
        return index;
        
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int>key(V, INT_MAX);
        vector<int>MST(V, false); // to keep trak which all nodes are added 
        vector<int>parent(V, -1); // stores final MST relations
        
        key[0] = 0;
        while(1){
            // Step1 : find u
            int u = getMinValueNode(key, MST);
            
            // breaking Condition when all the nodes are added in MST vector
            if(u == -1) break;
            
            // Step2 : MST[u] = true;
            MST[u] = true;
            
            // Step3 : get all adjacent values associated to u
            for(auto nbr:adj[u]){
                int v = nbr[0];
                int w = nbr[1];
                if(MST[v]==false && w < key[v]){
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        // find sum of weights of the MST
        int sum = 0;
        for(int u=0; u<parent.size(); u++){
            if(parent[u] == -1) continue;
            for(auto nbr:adj[u]){
                int v = nbr[0];
                int w = nbr[1];
                if(v == parent[u]){
                    sum += w;
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends