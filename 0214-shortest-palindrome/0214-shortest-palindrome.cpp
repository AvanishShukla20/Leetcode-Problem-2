class Solution {
public:
    int maxlpslen(string& s)
    {
        int i=1, len =0, n=s.size();
        vector<int> lps(n, 0);
        while(i<n)
        {
            if(s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else if(len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len-1];
            }
        } 

        return lps[n-1];

    }
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        string str = s + "&" + rev;
        int length = maxlpslen(str);
        string ans = rev.substr(0, (n-length)) + s;
        return ans;
    }
};