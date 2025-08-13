class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        int StartPixelColor = image[sr][sc]; // you have to color all connected pixels with this color

        
        if(StartPixelColor == color) return image;

        image[sr][sc] = color;

        q.push({sr, sc});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while(!q.empty())
        {
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k]; 
                if(nr >=0 && nr < m && nc >=0 && nc < n  && image[nr][nc] ==  StartPixelColor)
                {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};