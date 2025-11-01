//Directed Graph Cycle

class Solution {
  public:
  
    bool dfsHelper(int node, unordered_map<int, bool>&visited,vector<vector<int>>&adj, unordered_map<int, bool>&pathTrack){
        
        visited[node] = true;
        pathTrack[node] = true;
        
        for(auto nbr : adj[node]){
            
            if(!visited[nbr]){
                bool ans = dfsHelper(nbr, visited, adj, pathTrack);
                if(ans == true){
                    return true;
                }
            }
            /// if node is visited and also present in current path → cycle exists
            else if(visited[nbr] == true && pathTrack[nbr] == true){
                //cycle present
                return true;
            }
        }
        
        //backtrack
        pathTrack[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        
        //build the adj list for directed graph
        vector<vector<int>>adj(V);
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
        }
        
        int n = V;
        unordered_map<int, bool>visited;
        
        unordered_map<int, bool>pathTrack;
        
        //handling the disconnected component
        bool ans = false;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans = dfsHelper(i, visited, adj, pathTrack);
                
                if(ans) break;
            }
        }
        
        return ans;
    }
};

/*
🔹 Approach (DFS + Path Tracking):

1️⃣ Build adjacency list for directed graph.
2️⃣ Use two maps:
   - visited[] → marks visited nodes.
   - pathTrack[] → marks nodes in current recursion path.
3️⃣ During DFS:
   - If a neighbour is already in pathTrack → cycle exists.
4️⃣ Backtrack by marking pathTrack[node] = false.
5️⃣ Repeat for all unvisited nodes (handles disconnected graph).

🧠 Time: O(V + E)
💾 Space: O(V)
*/