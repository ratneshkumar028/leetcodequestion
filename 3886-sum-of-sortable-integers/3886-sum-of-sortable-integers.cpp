#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    long long sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        
        // Precompute suffix min only (O(n) space)
        std::vector<int> suff_min(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {
            suff_min[i] = std::min(nums[i], suff_min[i + 1]);
        }
        
        // Lambda to check if array can be sorted with block size k
        auto is_sortable = [&](int k) {
            int running_max = INT_MIN;
            
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                
                // Global ordering check: max of previous blocks > min of remaining blocks
                if (start > 0 && running_max > suff_min[start]) {
                    return false;
                }
                
                // Count internal drops within nums[start...end] on the fly
                int drops = 0;
                for (int i = start; i < end; ++i) {
                    if (nums[i] > nums[i + 1]) {
                        drops++;
                    }
                }
                // Check wrap-around drop from end to start of the block
                if (nums[end] > nums[start]) {
                    drops++;
                }
                
                if (drops > 1) {
                    return false;
                }
                
                // Update running maximum with elements from the current block
                for (int i = start; i <= end; ++i) {
                    running_max = std::max(running_max, nums[i]);
                }
            }
            return true;
        };

        long long ans = 0;
        // Check all divisors of n
        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                if (is_sortable(k)) {
                    ans += k;
                }
                int other = n / k;
                if (other != k && is_sortable(other)) {
                    ans += other;
                }
            }
        }
        
        return ans;
    }
};