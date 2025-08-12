class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        if(a[0] != b[0]) return a[0] < b[0];
        else return a[1] > b[1];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> lastChosen = intervals[0];
        int cnt = 1;
        for(int i=1; i<n; i++)
        {
            if(lastChosen[1] < intervals[i][1])
            {
                cnt++;
                lastChosen = intervals[i];
            }
        }

        return cnt;
    }
};