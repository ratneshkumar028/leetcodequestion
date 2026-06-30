class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count=0;
        int l =0;
        vector<int>ans(3,0);
        for(int i =0;i<n;i++){
            ans[s[i]-'a']++;
            while(ans[0]>0&& ans[1]>0 && ans[2]>0){
                count +=(n-i);
                ans[s[l]-'a']--;
                l++;
            }
        }
        return count;
    }
};