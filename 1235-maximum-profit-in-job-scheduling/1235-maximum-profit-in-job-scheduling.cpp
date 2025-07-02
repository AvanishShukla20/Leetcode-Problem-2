class Solution {
public:
    unordered_map<int, int> dp;

    int solve(int idx, vector<vector<int>>& vec)
    {
        if(idx >= vec.size()) return 0;
        if (dp.count(idx)) return dp[idx];

        int n=vec.size();
        // don't include
        int maxi = solve(idx+1, vec);
        // include 
        int nextidx = bs(idx, n-1, vec[idx][1], vec);
        maxi = max(maxi, vec[idx][2] + solve(nextidx, vec));

        return dp[idx] = maxi;
    }

    int bs(int low, int high, int val, vector<vector<int>>& vec) {
        int n = vec.size();
        int mid, ans = n;
        while (low <= high) {

            mid = (low + high) / 2;

            if (vec[mid][0] >= val)
            {  
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();

        vector<vector<int>> vec(n, vector<int> (3));

        for(int i=0; i<n; i++)
        {
            vec[i][0] = startTime[i];
            vec[i][1] = endTime[i];
            vec[i][2] = profit[i];
        }

        sort(vec.begin(), vec.end());
        return solve(0, vec);
    }
};