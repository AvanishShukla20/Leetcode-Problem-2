class Solution {
public:
    int solve(int i, int j, int k, vector<vector<int>>& vec, vector<vector<vector<int>>>& dp)
    {
        if(j < 0 || k < 0 || j >= vec[0].size() || k >= vec[0].size())
    return 0;
        if(i >= vec.size())
        {
            return 0;
        }

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int sum = 0;
        if(j == k) sum += vec[i][j];
        else
        {
            sum += vec[i][j] + vec[i][k];
        }

        vector<int> p = { -1, 0, 1 };

        int maxi = 0;
        for(int step1 : p)
        {
            for(int step2 : p)
            {
                maxi = max(maxi, solve(i+1, j+step1, k+step2, vec, dp));
            }
        }

        maxi += sum;
        return dp[i][j][k] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();

        vector<vector<vector<int>>> dp (m, vector<vector<int>>(n, vector<int>( n, -1)));

        return solve(0, 0, n-1, grid, dp);
    }
};