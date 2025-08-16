class Solution {
public:
    void solve(int node, vector<vector<pair<int, int>>>& adj, vector<int>& cost)
    {
        for(auto &it : adj[node])
        {
            int ngbr = it.first;
            int wt = it.second;

            if(cost[node] + wt < cost[ngbr])
            {
                cost[ngbr] = cost[node] + wt;
                solve(ngbr, adj, cost);
            }
        }

    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int mincost = INT_MIN;
        vector<int> cost(n+1, INT_MAX);

        vector<vector<pair<int, int>>> adj(n+1);

        for(int i=0; i<times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        cost[k] = 0;
        solve(k, adj, cost);

        for(int i=1; i<=n; i++)
        {
            if(cost[i] == INT_MAX) return -1;
            if(i == k) continue;
            mincost = max(mincost, cost[i]);
        }

        return mincost == INT_MIN ? -1 : mincost;
    }
};