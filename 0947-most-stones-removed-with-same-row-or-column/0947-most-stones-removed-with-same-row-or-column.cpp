class Solution {
public:
    void dfs(int idx, vector<vector<int>>& stones, vector<int>& vis) {
        vis[idx] = 1;
        for (int j = 0; j < stones.size(); j++) {
            if (!vis[j] && (stones[idx][0] == stones[j][0] || stones[idx][1] == stones[j][1])) {
                dfs(j, stones, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<int> vis(n+1, 0);
        int comps = 0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                comps++;
                dfs(i, stones, vis);
            }
        }

        return n - comps;
    }
};