class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool  n = true,m = true;
        for( int i =0;i<nums.size()-1;i++){
            if(!(nums[i]<=nums[i+1])){
                n = false;
            }
            if( !(nums[i]>=nums[i+1])){
                m = false;
            }
        }
        return n||m;
    }
};