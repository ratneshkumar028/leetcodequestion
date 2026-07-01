class Solution {
public:
    int n;
    vector<vector<int>> dis;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    void bfs(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        dis.assign(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                   dis[nx][ny] == INT_MAX) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    bool canReach(int val) {
        if(dis[0][0] < val) return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if(x == n-1 && y == n-1)
                return true;

            for(auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                   !vis[nx][ny] &&
                   dis[nx][ny] >= val) {

                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        bfs(grid);

        int low = 0, high = 2 * n, ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canReach(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};