//Undirected Graph Cycle


class Solution {
  public:
    
    bool cycleDetectionUndirectedBFS(int src, unordered_map<int, bool>&visited, vector<vector<int>>&adj){

        unordered_map<int, int>parent;
        queue<int>q;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto nbr : adj[frontNode]){

                if(!visited[nbr]){

                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if(visited[nbr] == true && nbr != parent[frontNode]){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, bool>visited;
        
        //build the adj list 
        vector<vector<int>>adj(V);
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        int n = V;
        bool ans = false;
        for(int i=0;i<n;i++){
            if(!visited[i]){
    
                ans = cycleDetectionUndirectedBFS(i, visited,adj);
                if(ans){
                    break;
                }
            }
        }
    
       return ans;
    }
};

/*
Approach:

1. Build the adjacency list from the given edges 
   → This represents the undirected graph.

2. Use BFS (Breadth-First Search) to traverse each connected component.

3. For every unvisited node:
   - Start a BFS traversal.
   - Maintain a 'parent' map to keep track of the node from which we came.
   - If we find a neighbor that is already visited 
     and not equal to the parent of the current node → cycle detected.

4. If any component contains a cycle, return true.

5. If after checking all nodes no cycle is found, return false.

In short:
We check each component using BFS, 
and if we reach an already visited node (not parent), 
it means the graph has a cycle.
*/


//USING THE DFS APPROACH
class Solution {
  public:
  
    bool checkCycleDFS(int src, unordered_map<int,bool>&visited, vector<vector<int>>&adj, int parent){
           
        visited[src] = true;
        
        for(auto neighbour : adj[src]){
            
            if(!visited[neighbour]){
                bool ans = checkCycleDFS(neighbour, visited, adj, src);
                
                if(ans) return true;
            }
            else if(visited[neighbour] == true && neighbour != parent){
                return true;
            }
        }
        
        return false;
        
         
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>>adj(V);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int, bool>visited;
        bool ans = false;
        int parent  = -1;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                ans = checkCycleDFS(i,visited, adj, parent);
                if(ans){
                    break;
                }
            }
        }
        
        return ans;
    }
};