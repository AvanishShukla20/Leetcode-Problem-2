class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        int prevEnd = intervals[0][1];
        int prevStart = intervals[0][0];

        for(int i=1; i<n; i++)
        {
            if(intervals[i][0] > prevEnd)
            {
                res.push_back({prevStart, prevEnd});
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
            else
            {
                prevStart = min(intervals[i][0], prevStart);
                prevEnd = max(intervals[i][1], prevEnd);
            }

        }

        res.push_back({prevStart, prevEnd });

        return res;

    }
};