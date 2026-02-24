class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            // indegree : number of incoming edges
            indegree[v]++;
        }
        
        // push the nodes with indegree to the queue -> as they can be first element in the top sort
        // kyuki unsey pheley koi aur node ni hoga
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int temp = q.front();
            ans.push_back(temp);
            q.pop();
            // ye temp node toh ans me ja chuka h toh uskey connection tod do -> means reduce the 
            // indegee of the connected nodes from temp
            for(auto it: adj[temp]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        return ans;
        
    }
};