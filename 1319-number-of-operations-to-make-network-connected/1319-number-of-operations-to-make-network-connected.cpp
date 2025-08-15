class DSU{
    public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int node) {
    if (parent[node] != node) {
        parent[node] = find(parent[node]); 
    }
    return parent[node];
}

    void Union(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return;
        if(rank[pa] == rank[pb])
        {
            parent[pa] = pb;
            rank[pb]++ ;
        }
        else if(rank[pa] > rank[pb])
        {
            parent[pb] = pa;
        }
        else parent[pa] = pb;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int extras = 0;
        for(int i=0; i<connections.size(); i++)
        {
            int a = dsu.find(connections[i][0]);
            int b = dsu.find(connections[i][1]);
            if(a != b)
            {
                dsu.Union(connections[i][0], connections[i][1]);
            }
            else extras++;
        }

        int comps = 0;
        for(int i=0; i<n; i++)
        {
            if(dsu.parent[i] == i) comps++;
        }

        int ans = comps-1;
        if(extras >= ans) return ans;

        return -1;
    }
};