class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& pre) {
        // Code here
        // first make adj list from the give connected nodes and indegree also
        vector<int> adj[N];
        vector<int> indegree(N,0);
        for(int i=0;i<P;i++){
            int u = pre[i].first;
            int v = pre[i].second;
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        // push the elements with the indegree 0 in the queue
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        // appling bfs from the inserted nodes
        while(!q.empty()){
            int temp = q.front();
            count++;
            q.pop();
            for(auto nei:adj[temp]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }
        return N == count;
    }
};