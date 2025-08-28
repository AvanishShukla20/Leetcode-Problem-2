class Solution {
public:
    int expand(const string& s, int left, int right) {
        // Base case: out of bounds or characters don't match
        if (left < 0 || right >= s.size() || s[left] != s[right]) return 0;
        // Count the current palindrome, and expand further
        return 1 + expand(s, left - 1, right + 1);
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            // Odd length palindromes (single center)
            count += expand(s, i, i);
            // Even length palindromes (center between i and i+1)
            count += expand(s, i, i + 1);
        }
        return count;
    }
};
