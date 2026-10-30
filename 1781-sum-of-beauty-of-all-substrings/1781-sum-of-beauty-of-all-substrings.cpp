class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for( int i =0;i<n;i++){
            int frq[26] = {0};
            for( int j = i;j<n;j++){
                frq[s[j]-'a']++;
                int mx = 0;
                int mn = INT_MAX;
                for(int k = 0;k<26;k++){
                    if(frq[k]>0){
                        mx = max(mx , frq[k]);
                        mn = min(mn , frq[k]);
                    }
                }
                ans += mx-mn;
            }
        }
        return ans;
    }
};