class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int> (n, 0)));

        //base case for i = m - 1
        for(int j1 = 0; j1 < n; j1++)
        {
            for(int j2 = 0; j2 < n; j2++)
            {
                if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j1];
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }


        for(int row = m-2; row >= 0; row--)
        {
            for(int col1 = n-1; col1 >= 0; col1--)
            {
                for(int col2 = n-1; col2 >= 0; col2--)
                {
                    int maxcherry = -1e9;
                    //explore paths

                    for(int st1 = -1; st1 <= 1; st1++)
                    {
                        for(int st2 = -1; st2 <= 1; st2++)
                        {
                            int cherry = -1e9;

                            if(st1 + col1 >= 0 && st1 + col1 < n && st2 + col2 >= 0 &&  st2 + col2 < n)  cherry = dp[row + 1][col1 + st1][col2+st2];

                            if(col1 == col2) cherry += grid[row][col1];
                            else cherry += grid[row][col1] + grid[row][col2];

                            maxcherry = max(maxcherry, cherry);
                        }
                    }
                    
                    dp[row][col1][col2] = maxcherry;
                }
            }
        }

        return dp[0][0][n-1];

    }
};