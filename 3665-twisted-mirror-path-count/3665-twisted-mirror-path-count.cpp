class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int mod = 1e9+7;
        vector<int> down(grid[0].size());
        down[0]=1;
        for(auto& row : grid){
            int r = 0;
            for( int j=0;j<row.size();j++){
                if(row[j]){
                    swap(r,down[j]);
                }
                else{
                    r = down[j]=(r+down[j])%mod;
                }
            }
        }
        return down.back();
    }
};