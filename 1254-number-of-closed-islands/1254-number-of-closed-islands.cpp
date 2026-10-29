class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool dfs(int x, int y, vector<vector<int>>& grid,  vector<vector<bool>> &vis){
        vis[x][y] = true;
        int m = grid.size(), n = grid[0].size();
        bool res = (x > 0 and x < m - 1 and y > 0 and y < n - 1);
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 or nx >= m or ny < 0 or ny >= n)
                continue;
            if(grid[nx][ny] == 1 or vis[nx][ny])
                continue;
            bool ans = dfs(nx, ny, grid, vis);
            res &= ans;
        }
        return res;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> vis(m, vector<bool>(n));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 0 and !vis[i][j])
                    res += dfs(i, j, grid, vis);
            }
        }
        return res;
    }
};