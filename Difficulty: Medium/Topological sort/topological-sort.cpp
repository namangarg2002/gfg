//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> topoSortBFS(int n, vector<vector<int>>& adjList){
        vector<int> ans;
        queue<int> q;
        vector<int> inDegree(n, 0);
        // initialise inDegree
        for (int node = 0; node < n; node++)
        {
          for (auto child : adjList[node])
          {
            inDegree[child]++;
          }
        }
        // push all zero indegree wali node into queue
        for (int node = 0; node < n; node++)
        {
          if (inDegree[node] == 0)
          {
            q.push(node);
          }
        }
    
        // BFS CONCEPT
        while (!q.empty())
        {
          int frontNode = q.front();
          q.pop();
          ans.push_back(frontNode);
          for (int child : adjList[frontNode])
          {
            inDegree[child]--;
            // check for 0
            if (inDegree[child] == 0)
            {
              q.push(child);
            }
          }
        }
        return ans;
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        
        return topoSortBFS(n, adj);
        
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends