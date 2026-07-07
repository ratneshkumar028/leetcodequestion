class Solution {

bool dfs(int i , int j , vector<vector<bool>> &vis , vector<vector<char>> &grid) {
    int n = grid.size() , m = grid[0].size(); //
    vector<vector<int>> tran = { {0 , 1} , {0 , -1} , {1 , 0} , {-1, 0} };
    vis[i][j] = true;

    for(int x = 0; x < tran.size(); ++x) {
        int I = i + tran[x][0]; int J = j + tran[x][1];

        if(I < 0 || J < 0 || I >= n || J >= m || vis[I][J] || grid[I][J] == '0')
           continue;
        else 
           dfs(I , J , vis , grid);    
    }

    return false;
}

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0 , n = grid.size() , m = grid[0].size(); // 
        vector<vector<bool>> vis(n , vector<bool>(m , false));

        for(int i = 0; i < n; ++i) 
           for(int j = 0; j < m; ++j) 
             if(!vis[i][j] && grid[i][j] == '1')
                 (++ans) && dfs(i , j , vis , grid); 

        return ans;         
    }
};