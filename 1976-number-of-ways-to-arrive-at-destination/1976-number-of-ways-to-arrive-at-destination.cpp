class Solution {
public:
    typedef pair<long long, int> pli;
    const int mod = 1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u}); // undirected
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pli, vector<pli>, greater<pli>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node]) continue; // stale

            for (auto &it : adj[node]) {
                int edgeWt = it.first;
                int neigh = it.second;

                if (currDist + edgeWt < dist[neigh]) {
                    dist[neigh] = currDist + edgeWt;
                    ways[neigh] = ways[node]; // new shortest path
                    pq.push({dist[neigh], neigh});
                }
                else if (currDist + edgeWt == dist[neigh]) {
                    ways[neigh] = (ways[neigh] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};
