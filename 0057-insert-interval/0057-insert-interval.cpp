class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& num) {
        vector<vector<int>> dp;
        int i = 0;
        int n = nums.size();
        while(i<n &&  nums[i][1]<num[0]){
            dp.push_back(nums[i]);
            i++;
        }
        while(i<n && nums[i][0]<=num[1]){
            num[0]=min(num[0],nums[i][0]);
            num[1]=max(num[1],nums[i][1]);
            i++;
        }
        dp.push_back(num);
        while(i<n){
            dp.push_back(nums[i]);
            i++;
        }
        return dp;
    }
};