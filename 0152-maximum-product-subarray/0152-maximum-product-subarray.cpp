class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int mp = nums[0];
        int np = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            if (x < 0) {
                swap(mp, np);
            }

            mp = max(x, mp * x);
            np = min(x, np * x);

            ans = max(ans, mp);
        }

        return ans;
    }
};