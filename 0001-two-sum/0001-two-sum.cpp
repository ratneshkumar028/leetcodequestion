class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        unordered_map<int,int>mpp;
        for( int i=0; i<n;i++){
            int res = target - nums[i];
            if(mpp.count(res)){
                return {mpp[res],i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};