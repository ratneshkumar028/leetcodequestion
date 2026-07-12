class Solution {
public:
    void solve(string s, int n, vector<string>& ans) {
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }

        
        solve(s + "1", n, ans);

        
        if (s.empty() || s.back() != '0') {
            solve(s + "0", n, ans);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        solve("", n, ans);
        return ans;
    }
};