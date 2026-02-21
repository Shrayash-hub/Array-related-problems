class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> adj[V];
        
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V,false);
        
        queue<pair<int,int>> q;
        
        // check all components
        for(int start = 0; start < V; start++){
            
            if(visited[start]) continue;
            
            visited[start] = true;
            q.push({start,-1});
            
            while(!q.empty()){
                
                int size = q.size();
                
                for(int k =0 ;k<size;k++){
                    
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    
                    for(auto &nei: adj[node]){
                        
                        if(!visited[nei]){
                            
                            visited[nei] = true;
                            q.push({nei,node});
                        }
                        else{
                            
                            if(nei!=parent) return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};
