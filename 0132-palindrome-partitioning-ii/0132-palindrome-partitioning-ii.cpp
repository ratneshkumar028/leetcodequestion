class Solution {
public:
    vector<int> dp;

    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, string &s) {
        if (i == s.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                ans = min(ans, 1 + solve(j + 1, s));
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        dp.assign(n, -1);

        return solve(0, s) - 1;
    }
};
