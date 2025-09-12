class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        
        for(int i=0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    // vis[i][j] = 1;
                    if(grid[i][j] == 2) q.push({0, {i, j}});
                }
                
            }
        }
        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        int ans = 0;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            int lv = t.first, i = t.second.first, j = t.second.second;
            ans = lv;
            for(int k =0;k<4;k++)
            {
                int ni = i+dr[k];
                int nj = j+dc[k];
                if(ni>=0&&ni<m&&nj>=0&&nj<n && grid[ni][nj] == 1)
                {
                    grid[ni][nj] = 2;  
                    q.push({lv+1, {ni, nj}});
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
        return ans;
    }
};