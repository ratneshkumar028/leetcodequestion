class Solution {
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    res = max(res,dfs(grid,i,j));
                }
            }
        }
        return res;
    }
    int dfs(vector<vector<int>> &grid,int i,int j){
        if(i<0 || j< 0|| i>=grid.size() || j>=grid[0].size() ||grid[i][j]==0){
            return 0;
        }
        int ans =1;
        grid[i][j]=0;
        for( int k =0;k<4;k++){
            ans+=dfs(grid,i+dir[k][0],j+dir[k][1]);
        }
        return ans;
    }
};