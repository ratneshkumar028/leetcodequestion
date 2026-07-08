class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;

        int n = s.size();

        vector<long long> prefDigit(n + 1, 0);
        vector<int> cnt(n + 1, 0);

        vector<long long> hash(1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {
            prefDigit[i + 1] = prefDigit[i];
            cnt[i + 1] = cnt[i];

            if (s[i] != '0') {
                int d = s[i] - '0';

                prefDigit[i + 1] += d;
                cnt[i + 1]++;

                hash.push_back((hash.back() * 10 + d) % MOD);
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefDigit[r + 1] - prefDigit[l];

            int L = cnt[l];
            int R = cnt[r + 1];

            long long num =
                (hash[R] - hash[L] * pow10[R - L] % MOD + MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};