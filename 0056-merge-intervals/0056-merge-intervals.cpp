class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        // Step 1: Sort intervals based on their start times
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for (auto num : nums) {
            // If the answer is empty or the current interval does not overlap with the previous one
            if (ans.empty() || ans.back()[1] < num[0]) {
                ans.push_back(num);
            }
            // If there is an overlap, merge them by updating the end time
            else {
                ans.back()[1] = max(ans.back()[1], num[1]);
            }
        }
        
        return ans;
    }
};