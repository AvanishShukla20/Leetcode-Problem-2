class Solution {
public:
    int solve(int L, int R, vector<int>& nums, vector<vector<int>>& dp) {
        if (L > R) return 0;
        if (dp[L][R] != -1) return dp[L][R];

        int res = 0;
        for (int idx = L; idx <= R; idx++) {
            // i am choosing idx means It is the onky one remainaing in L to R i.e idx is chosen at last
            int curr = nums[L-1] * nums[idx] * nums[R+1];
            curr += solve(L, idx-1, nums, dp) + solve(idx+1, R, nums, dp);
            res = max(res, curr);
        }
        return dp[L][R] = res;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n+2, 1); // [1, nums..., 1]
        for (int i = 0; i < n; i++) vec[i+1] = nums[i];

        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return solve(1, n, vec, dp);
    }
};
