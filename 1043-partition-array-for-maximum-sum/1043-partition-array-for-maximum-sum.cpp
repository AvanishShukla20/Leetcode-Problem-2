class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int idx = n-1; idx >= 0; idx--)
        {
        int maxi = INT_MIN;
        int ans = 0, len = 0;
        for(int i = idx; i < min(n, idx + k); i++) // mistake you did -> if idx = n-1 and k > 1 then idx+k may increase bounds of n
        { 
            len++;
            if(arr[i] > maxi) maxi = arr[i];
            int pos = (len*maxi) + dp[i+1];
            ans = max(ans, pos);
        }
        dp[idx] = ans;
        }

        return dp[0];
    }
};