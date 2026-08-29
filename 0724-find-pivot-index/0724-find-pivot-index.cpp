class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int x : nums){
            total +=x; 
        }
        int lf = 0;
        for(int i =0;i<n;i++){
            int rf = total-lf-nums[i];
            if(lf==rf){
                return i;
            }
            lf+=nums[i];
        }
        return -1;
    }
};