class DisjointSet{
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1, 0); // n+1 because say if in future we have 1 based indexing
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltPar(int node)
    {
        if(parent[node] == node) return node;

        return parent[node] = findUltPar(parent[node]);
    }

    void UnionByRank(int a, int b)
    {
        int UltPar_a = findUltPar(a);
        int UltPar_b = findUltPar(b);

        if(UltPar_a == UltPar_b) return;

        if(rank[UltPar_a] < rank[UltPar_b])
        {
            parent[UltPar_a] = UltPar_b;
        }
        else if(rank[UltPar_a] > rank[UltPar_b])
        {
            parent[UltPar_b] = UltPar_a;
        }
        else
        {
            parent[UltPar_a] = UltPar_b;
            rank[UltPar_b] += 1;
        }
    }

    void UnionBySize(int a, int b)
    {
        int UltPar_a = findUltPar(a);
        int UltPar_b = findUltPar(b);

        if(UltPar_a == UltPar_b) return;

        if(size[UltPar_a] < size[UltPar_b])
        {
            parent[UltPar_a] = UltPar_b;
            size[UltPar_b] += size[UltPar_a];
        }
        else
        {
            parent[UltPar_b] = UltPar_a;
            size[UltPar_a] += size[UltPar_b];
        }
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mailMap;

        DisjointSet ds(n);

        for(int i=0; i < n; i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(mailMap.find(mail) != mailMap.end())
                {
                    // perform UNIONBYSIZE since here we can more intuiteively merge by size .
                    ds.UnionBySize(i, mailMap[mail]);
                }
                else
                {
                    mailMap[mail] = i;
                }
            }
        }


        //merging the mails

        vector<string> mergedMails[n]; // < -this is nothing but of a static array of the vector of strings

        for(auto &it : mailMap)
        {
            string s  = it.first;
            int node = it.second;
            int parnode = ds.findUltPar(node);
            mergedMails[parnode].push_back(s);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++)
        {
            if(mergedMails[i].size() == 0) continue; // if the node i doesn't contain any string we dont include anything of it
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for(auto &it : mergedMails[i])
            {
                temp.push_back(it);
            }

            ans.push_back(temp);
        }


        return ans;
    }
};