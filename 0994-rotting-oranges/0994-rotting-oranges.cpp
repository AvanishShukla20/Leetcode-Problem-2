class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i=0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                   q.push({i, j});
                }
                else if(grid[i][j] == 1) fresh++;
            }
        }

        // if there are no fresh oranges then return 0
        if(fresh == 0) return 0;

        //if(q.empty()) return -1;


        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        int ans = 0;
        while(!q.empty())
        {
            int len = q.size();
            ans++;
            for(int k=0; k<len; k++)
            {
                auto t = q.front();
                q.pop();
                int i = t.first, j = t.second;
                for(int k =0;k<4;k++)
                {
                    int ni = i+dr[k];
                    int nj = j+dc[k];
                    if(ni>=0&&ni<m&&nj>=0&&nj<n && grid[ni][nj] == 1)
                    {
                        grid[ni][nj] = 2;  
                        q.push({ni, nj});
                    }
                }
            }
            
        }

        for(int i=0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans-1;
    }
};