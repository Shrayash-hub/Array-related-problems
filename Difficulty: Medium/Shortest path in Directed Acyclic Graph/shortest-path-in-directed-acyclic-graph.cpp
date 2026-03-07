// User function Template for C++
class Solution {
  public:
    void dfs(int node, vector<vector<pair<int,int>>>& adj,stack<int>& st,vector<int>& vis){
        vis[node] = 1;
        for(auto it:adj[node]){
            int nei = it.first;
            if(!vis[nei]){
                dfs(nei,adj,st,vis);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        // making adj list from the give connected nodes
        vector<vector<pair<int,int>>> adj(V); // adj list will contain the {node,weight} pair
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v,w});
        }
        
        // appling toposort(dfs) first
        // we need a stack for it
        stack<int> st;
        vector<int> vis(V,0);
        // run dfs for all the components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }
        
        // this is going to save the distance from the source node
        vector<int> dist(V,INT_MAX);
        // distance from itself will be zero obviously
        dist[0] = 0;
        
        // start taking out element from stack one by one
        while(!st.empty()){
            int node = st.top();
            st.pop();
            int distance = dist[node];
            if(distance != INT_MAX){
                // visit to the neignbours and if path through currNode is shorter than peviously
                // any explored path , update the distance
                for(auto nei:adj[node]){
                    int next = nei.first;
                    int currD = nei.second;
                
                    dist[next] = min(dist[next],distance+currD);
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
};
