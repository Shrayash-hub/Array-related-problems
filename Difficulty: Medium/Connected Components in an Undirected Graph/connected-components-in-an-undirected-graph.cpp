class Solution {
  public:
    void dfs(int start,vector<vector<int>> &ans,vector<int> &curr,vector<int> &visited,vector<int> adj[]){
        visited[start]=1;
        curr.push_back(start);
        for(auto nei: adj[start]){
            if(visited[nei]!=1){
                dfs(nei,ans,curr,visited,adj);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> ans;
        
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                vector<int> curr;
                dfs(i,ans,curr,visited,adj);
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
