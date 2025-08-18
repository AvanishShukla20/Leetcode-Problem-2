class Solution {
public:
    int solve(int idx,int target, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(idx == 0)
        {
            if(target% nums[idx] == 0) return target/nums[idx];
            return 1e8;
        }
        if(dp[idx][target] != -1) return dp[idx][target];

        int v1 = solve(idx-1, target, nums, dp);
        int v2 = 1e8;
        if(target >= nums[idx])
        {
            v2 = 1 + solve(idx, target-nums[idx], nums, dp);
        }
        return dp[idx][target] = min(v1, v2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

         int ans = solve(coins.size()-1, amount, coins, dp);
        return ans != 1e8 ? ans : -1;
    }
};