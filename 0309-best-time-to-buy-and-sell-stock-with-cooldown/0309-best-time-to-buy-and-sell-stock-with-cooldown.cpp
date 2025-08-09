class Solution {
public:
    int solve(int idx, int buy, vector<int>& nums, vector<vector<int>>& dp)
    {
        if (idx >= nums.size()) return 0; // base case
        if (dp[idx][buy] != -1) return dp[idx][buy]; // memoization

        int profit = 0;
        if (buy) {
            // Buy or Skip
            profit = max(-nums[idx] + solve(idx + 1, 0, nums, dp), // buy now
                         solve(idx + 1, 1, nums, dp));             // skip buying
        } 
        else {
            // Sell or Skip
            profit = max(nums[idx] + solve(idx + 2, 1, nums, dp),  // sell now (cooldown next day)
                         solve(idx + 1, 0, nums, dp));             // skip selling
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // dp[idx][buy]
        return solve(0, 1, prices, dp); // start with buy allowed
    }
};