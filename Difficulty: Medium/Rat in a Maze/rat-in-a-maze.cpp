class Solution {
  public:
    char dir[4] = {'D','U','R','L'};
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void solve(vector<vector<int>>& maze, int i, int j, vector<vector<int>> &visited, vector<string> &ans,string &curr){
        if(i==maze.size()-1 && j==maze.size()-1){
            ans.push_back(curr);
            return;
        }
        
        for(int k=0;k<=3;k++){
            int newi = i + dx[k];
            int newj = j + dy[k];
            if(newi<maze.size() && newj<maze.size() && newi>=0 && newj>=0 && visited[newi][newj]!=1 && 
            maze[newi][newj]==1){
                visited[newi][newj] = 1;
                curr+= dir[k];
                solve(maze,newi,newj,visited,ans,curr);
                
                visited[newi][newj] = 0;
                curr.pop_back();
            }
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        
        string curr = "";
        vector<string> ans;
        if(maze[0][0]==0 || maze[n-1][n-1]==0){
            return ans;
        }
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        solve(maze,0,0,visited,ans,curr);
        sort(ans.begin(), ans.end());
        return ans;
    }
};