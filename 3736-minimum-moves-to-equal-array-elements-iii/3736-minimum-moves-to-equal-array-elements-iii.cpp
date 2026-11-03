class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long int sum = 0;
        for( int i: nums) sum+=i;
        int mx = *max_element(nums.begin(),nums.end());
        return nums.size()*mx-sum;
    }
};