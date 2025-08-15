class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revgraph(n);
        vector<int> indegree(n, 0);
        queue<int> Q;
        for(int u = 0; u<n; u++)
        {
            for(auto v : graph[u])
            {
                revgraph[v].push_back(u);
                indegree[u]++;
            }
        }

        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 0) Q.push(i);
        }

        vector<int> ans;
        //bfs kahn's-traversal

        while(!Q.empty())
        {
            int frontV = Q.front();
            Q.pop();
            ans.push_back(frontV);

            for(auto it : revgraph[frontV])
            {
                indegree[it]--;
                if(indegree[it] == 0) Q.push(it);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};