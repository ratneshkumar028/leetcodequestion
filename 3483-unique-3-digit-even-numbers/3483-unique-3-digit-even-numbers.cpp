class Solution {
public:
    unordered_set<int> nums;

    void backtrack(vector<int>& digits, vector<bool>& used,
                   int curr, int len) {

        if (len == 3) {
            if (curr % 2 == 0) {
                nums.insert(curr);
            }
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (used[i]) continue;

            if (len == 0 && digits[i] == 0) continue;

            used[i] = true;
            backtrack(digits, used,
                      curr * 10 + digits[i],
                      len + 1);
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(), false);
        backtrack(digits, used, 0, 0);
        return nums.size();
    }
};