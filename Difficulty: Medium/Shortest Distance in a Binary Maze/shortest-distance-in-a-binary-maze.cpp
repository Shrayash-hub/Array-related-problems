// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(grid[source.first][source.second] == 0) return -1;
        // we are going to use djikstra's algorithm to find the shortest ditance between source 
        // and destination
        
        // we dont need priority queue here because we have unit distance between any two cells , so
        // queue is already going to be in sorted order
        queue<pair<int,pair<int,int>>> q;  // going to save {distance from the source, {i,j}}
        
        // we also need a dist 2d matrix , same size of grid
        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        
        //pushing source to the queue , as we are starting from there
        q.push({0,{source.first,source.second}});
        // marking source with dist = 0
        dist[source.first][source.second] = 0;
        
        // applying djikstra algo
        int dx[4] = {-1,0,1,0};            
        int dy[4] = {0,1,0,-1}; 
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int d = node.first;
            int i = node.second.first;
            int j = node.second.second;
            
            // if we reached to the destination node then return the distance
            if(i==destination.first && j== destination.second) return d;
            // we can move in four directions
            for(int k=0;k<4;k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && grid[ni][nj]==1){
                    // if we get the shorter distance from any other path, update the distance and 
                    // push it in the queue
                    if(d+1<dist[ni][nj]){
                        dist[ni][nj] = 1+d;
                        q.push({1+d,{ni,nj}});
                    }
                }
            }
            
        }
        return -1;
    }
};
