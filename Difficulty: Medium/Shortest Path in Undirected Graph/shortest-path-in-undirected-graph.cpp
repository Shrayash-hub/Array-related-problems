class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        
        // we have give connected nodes , from which we need to make adj list
        vector<vector<int>> adj(V);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // we need a dist vector to save the minimum distance from the start node
        vector<int> dist(V,INT_MAX); // intially consider that distance from src to all the nodes is infinity
        
        // lets start from src node and call bfs to the adjancent node
        // we need a queue storing {node,dist from source node}
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src] = 0;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto [node,d] = q.front();
                q.pop();
                for(auto next: adj[node]){
                    if(dist[next]==INT_MAX){
                        dist[next] = d+1;
                        q.push({next,d+1});
                    }
                }
            }
        }
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX){
            dist[i] = -1;
            }
        }
        return dist;
    }
};
