class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        unordered_map<int,int> mp;
        
        int rank = 1;
        for(int x : s){
            mp[x] = rank++;
        }
        
        for(int &x : arr){
            x = mp[x];
        }
        
        return arr;
    }
};