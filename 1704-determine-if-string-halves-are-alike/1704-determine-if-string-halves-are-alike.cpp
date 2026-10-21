class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n / 2; i++) {
            if (tolower(s[i]) == 'a' ||
                tolower(s[i]) == 'e' ||
                tolower(s[i]) == 'i' ||
                tolower(s[i]) == 'o' ||
                tolower(s[i]) == 'u') {
                count++;
            }

            if (tolower(s[i + n / 2]) == 'a' ||
                tolower(s[i + n / 2]) == 'e' ||
                tolower(s[i + n / 2]) == 'i' ||
                tolower(s[i + n / 2]) == 'o' ||
                tolower(s[i + n / 2]) == 'u') {
                count--;
            }
        }

        return count == 0;
    }
};