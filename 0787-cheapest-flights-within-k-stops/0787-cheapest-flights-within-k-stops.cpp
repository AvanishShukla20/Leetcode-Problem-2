class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // bfs way ->

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<pair<int, int>>> adj(n);

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        for(int i=0; i<flights.size(); i++)
        {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        int ans = INT_MAX;

        // pq.push({0 , {0, src}}); // cost, stops , node galat hai 

        pq.push({0 , {0, src}}); // stops, cost, node sahi

        while(!pq.empty())
        {
            auto stops = pq.top().first;
            auto cost = pq.top().second.first;
            auto node = pq.top().second.second;
            pq.pop();

            if(node == dst)
            {
                ans = min(ans, cost);
                continue;
            }

            if(stops <= k)
            {
                for(auto &it : adj[node])
                {
                    if(dist[it.first] > cost + it.second)
                    {
                        dist[it.first] = cost + it.second;
                        // cout<<node<<" -> "<<it.first<<"cost : "<<dist[it.first]<<"stops : "<<stops<<endl;
                        pq.push({stops + 1, {it.second + cost, it.first}});
                    }
                    
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;

    }
};