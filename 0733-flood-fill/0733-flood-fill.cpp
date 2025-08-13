class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> grid = image;

        grid[sr][sc] = color;

        q.push({sr, sc});
         vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        vector<int> vis(m*n+1, 0);

        vis[sr*n + sc + 1] = 1;

        while(!q.empty())
        {
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k]; 
                int idx = nr*n + (nc+1);
                if(nr >=0 && nr < m && nc >=0 && nc < n && !vis[idx] && image[nr][nc] == image[r][c])
                {
                    grid[nr][nc] = color;
                    vis[idx] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return grid;
    }
};