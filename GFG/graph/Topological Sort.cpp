//Topological Sort


class Solution {
  public:
  
    void topoDfs(int src,unordered_map<int, bool>&vis, vector<vector<int>>&adj, vector<int>&ans){
        
        vis[src] = true;
        
        for(auto nbr:adj[src]){
            
            if(!vis[nbr]){
                
                topoDfs(nbr, vis, adj, ans);
            }
        }
        
        //backtrack
        ans.push_back(src);
        
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(auto edge:edges){
            int u=edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            
        }
        
        vector<int>ans;
        unordered_map<int, bool>visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topoDfs(i, visited, adj, ans);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};