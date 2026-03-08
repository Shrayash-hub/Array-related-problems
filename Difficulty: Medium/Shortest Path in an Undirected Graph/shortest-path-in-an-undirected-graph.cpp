class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
         // adjacency list -> {neighbor, weight}
        vector<pair<int,int>> adj[n+1];

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w}); // undirected graph
        }

        // distance array
        vector<int> dist(n+1, INT_MAX);

        // parent array for path reconstruction
        vector<int> parent(n+1);

        for(int i=1;i<=n;i++)
            parent[i]=i;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[1]=0;
        pq.push({0,1});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            for(auto nbr : adj[node]){

                int adjNode = nbr.first;
                int weight = nbr.second;

                if(d + weight < dist[adjNode]){

                    dist[adjNode] = d + weight;

                    pq.push({dist[adjNode], adjNode});

                    // store parent
                    parent[adjNode] = node;
                }
            }
        }

        // if destination unreachable
        if(dist[n] == INT_MAX)
            return {-1};

        vector<int> path;

        int node = n;

        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }

        path.push_back(1);

        reverse(path.begin(), path.end());

        // add distance at beginning
        path.insert(path.begin(), dist[n]);

        return path;
    }
};