class Solution {
public:
    bool isCycle(int node, vector<int>& vis,vector<bool>& inRecursion, vector<vector<int>>& graph)
    {
        vis[node] = 1;
        inRecursion[node] = true;
        bool rec;
        for(auto &it : graph[node])
        {
            if(!vis[it])
            {  
                if(isCycle(it, vis,inRecursion, graph)) return true;
            }
            else if(inRecursion[it] == true)
            {
                return true;
            }
        }

        inRecursion[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<bool> inRecursion(n);

        for(int i = 0; i< n; i++)
        {
            if(!vis[i])
            {
                isCycle(i, vis, inRecursion, graph);
            }
        }

        vector<int> ans;
        for(int i = 0; i < inRecursion.size(); i++)
        {
            if(inRecursion[i] == false) ans.push_back(i);
        }

        return ans;
    }
};