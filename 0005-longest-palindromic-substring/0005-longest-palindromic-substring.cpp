class Solution {
public:
    int expandAroundCenter(int left, int right, string& s) 
    {
        int n=s.size();
        while(left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        // return length of palindrome
        return right - left - 1; // because left and right now point outside palindrome
        };

    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";

        int start = 0, maxLen = 1;


        for(int i = 0; i < n; i++) {
            
            int len1 = expandAroundCenter(i, i, s);     // Odd-length palindrome
            int len2 = expandAroundCenter(i, i + 1, s); // Even-length palindrome

            int len = max(len1, len2);

            if(len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2; // calculate start index
            }
        }

        return s.substr(start, maxLen);
    }
};