class Solution {
public:
    bool dfs(int node, vector<bool>& vis,vector<bool>& path, vector<bool>& ans, vector<vector<int>>& adj)
    {
        vis[node] = 1;
        path[node] = 1;

        for(int it : adj[node])
        {
            // If neighbor is in current path -> cycle
            if (path[it]) {
                ans[node] = false;
                return false;
            }
            // If neighbor not visited, explore
            if (!vis[it]) {
                if (!dfs(it, vis, path, ans, adj)) {
                    ans[node] = false;
                    return false;
                }
            }
            // If neighbor visited but unsafe
            else if (!ans[it]) {
                ans[node] = false;
                return false;
            }
        }

        path[node] = 0;
        ans[node] = true;

        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> ans(n, false);
        vector<bool> vis(n, false);
        vector<bool> inpath(n, false);

        vector<int> res;

        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, inpath, ans, graph);
            }
        }

        for(int i=0; i<n; i++)
        {
            if(ans[i] == true)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};