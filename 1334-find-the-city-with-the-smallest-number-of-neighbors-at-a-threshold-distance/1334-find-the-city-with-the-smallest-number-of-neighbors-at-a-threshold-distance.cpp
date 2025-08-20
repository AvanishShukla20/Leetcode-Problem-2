class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        /* Here we have to find all the nodes with sum along the path under threshold for 
           all  the nodes. So , we will need the minpathSum for each and every node to ther node. So, We use floyd algorithm*/

           vector<vector<int>> costMatrix(n, vector<int> (n, 1e9));

           for(int i=0; i<n; i++)
           {
                costMatrix[i][i] = 0;
                
                int u = edges[i][0], v = edges[i][1], wt = edges[i][0];
                costMatrix[u][v] = wt;  
           }




           //algorithm

           for(int intermediate = 0; intermediate < n; intermediate++)
           {
            for(int i=0; i<n; i++)
            {
                for(int j = 0; j < n ; j++)
                {
                    costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][intermediate] + costMatrix[intermediate][j]);
                }
            }
           }


           for(int i=0; i<n; i++)
           {
            for(int j = 0; j < n; j++){
                if(costMatrix[i][j] == 1e9) costMatrix[i][j] = 0;
            }  
           }

           int minCount = INT_MAX, ans= INT_MIN;

           for(int i=0; i<n ; i++)
           {
            int count = 0;
            for(int j =0; j < n; j++)
            {
                if(costMatrix[i][j] < distanceThreshold) count++;
            }

            if(count <= minCount)
            {
                minCount = count;
                ans = max(i, ans);
            }
           }

        return ans;
    }
};