class Solution {
public:
    const int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        vector<int> dp(n+1);
        dp[0] = 1;

        for(int i=1; i<=n; i++)
        {
            char ch = s[i-1];

            if(mpp.find(ch) == mpp.end())
            {
                dp[i] = (2LL * dp[i-1])%mod;
                mpp[ch] = i;
            }
            else
            {
                int prev_idx = mpp[ch];
                dp[i] = ( (2LL * dp[i-1])% mod - dp[prev_idx - 1] + mod ) % mod;

                mpp[ch] = i;
            }
        }

        // dp[n] will contain  {}
        return (dp[n] - 1 + mod ) % mod;
    }
};