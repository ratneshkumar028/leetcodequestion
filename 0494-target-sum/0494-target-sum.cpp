class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int> dp;
        dp[0]  = 1;
        for(int i : nums){
            unordered_map<int , int>nextdp;
            for(auto &j : dp){
                int t = j.first;
                int c = j.second;
                nextdp[t+i] +=c;
                nextdp[t-i] +=c; 
            }
            dp = nextdp;
        }
        return dp[target];
    }
};