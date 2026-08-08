class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        std::unordered_set<int> twice;
        size_t n = nums.size();
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i; j < n; ++j) {
                twice.insert(nums[i] ^ nums[j]);
            }
        }
        std::unordered_set<int> third;
        for (int& num : nums) {
            for (auto& it : twice) {
                third.insert(it ^ num);
            }
        }
        return third.size();
    }
};