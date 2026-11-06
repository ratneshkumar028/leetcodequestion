#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        int m = queries.size();
        vector<vector<int>> qs(m);
        for (int i = 0; i < m; ++i) {
            qs[i] = {queries[i], i};
        }
        
        sort(qs.begin(), qs.end());
        
        unordered_map<int, int> cnt;
        vector<int> ans(m);
        int j = 0, k = 0;
        
        for (auto& q : qs) {
            int r = q[0];
            int i = q[1];
            int l = r - x;
            
            while (k < logs.size() && logs[k][1] <= r) {
                cnt[logs[k][0]]++;
                k++;
            }
            
            while (j < logs.size() && logs[j][1] < l) {
                cnt[logs[j][0]]--;
                if (cnt[logs[j][0]] == 0) {
                    cnt.erase(logs[j][0]);
                }
                j++;
            }
            
            ans[i] = n - cnt.size();
        }
        
        return ans;
    }
};