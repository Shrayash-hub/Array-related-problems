class Solution {
  public:
    bool isSafe(int node, vector<int> &color, vector<vector<int>> &adj,int n, int col){
        for(auto neig: adj[node]){
            if(color[neig]==col){
                return false;
            }
        }
        return true;
    }
    bool solve(int node, vector<int> &color, vector<vector<int>> &adj,int n, int m){
        if(node==n) return true;
        // trying all the colors to that vertex
        for(int i=1;i<=m;i++){
            if(isSafe(node,color,adj, n, i)){
                // place color : as it is safe for now
                color[node] = i;
                // recursively calling for next node
                if(solve(node+1,color,adj, n, m)) return true;
                
                // if at a point we reach to a dead end , so backtrack
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int V, vector<vector<int>> &edges, int m) {
        // code here
        // building adj list, where we will save ki kis node se konsa konsa node connected h ,like:
        // 0 -> {1,2,3}
        // 1 -> {0,3}
        vector<vector<int>> adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // we need a vector color -> which is going to save , ki konsi vertex ko konsa color assign hua h
        vector<int> color(V,0); // 0 means koi bhi color assign nhi hua h
        
        // calling recursive function
         return solve(0,color,adj,V,m);
    }
};