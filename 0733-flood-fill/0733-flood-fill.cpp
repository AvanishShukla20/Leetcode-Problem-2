class Solution {
public:

    void dfs(vector<vector<int>>& v,vector<vector<int>>& image,int start,int row,int col,int color)
    {
            v[row][col] = color;
            vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
            int n = image.size();
            int m = image[0].size();
            for(int i = 0; i< directions.size(); i++)
            {
                int nr = row + directions[i].first;
                int nc = col + directions[i].second;
                if(nr >=0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == start && v[nr][nc] != color)
                {
                    dfs(v, image, start, nr, nc,color);
                }
            }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> v(image.begin(), image.end());
        int start = image[sr][sc];
        dfs(v, image,start, sr, sc, color);
        return v;


    }
};