class Solution {
public:

    bool dfs(vector<int> adj[], vector<int>& vis, vector<int>& inPath, int node){
        
        vis[node] = 1;
        inPath[node] = 1;
        
        for(auto it : adj[node]){
            
            // Case 1: not visited
            if(!vis[it]){
                if(dfs(adj, vis, inPath, it))
                    return true;
            }
            
            // Case 2: visited and in same path → cycle detected
            else if(inPath[it]){
                return true;
            }
        }
        
        // backtrack → remove from current path
        inPath[node] = 0;
        
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        // Create adjacency list
        vector<int> adj[V];
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        vector<int> inPath(V, 0);
        
        // check each component
        for(int i = 0; i < V; i++){
            
            if(!vis[i]){
                
                if(dfs(adj, vis, inPath, i))
                    return true;
            }
        }
        
        return false;
    }
};