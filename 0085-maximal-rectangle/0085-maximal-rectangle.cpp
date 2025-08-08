class Solution {
public:
    void fillns(vector<int>& arr, vector<int>& lvec, vector<int>& rvec)
    {
        stack<int> st;
        lvec[0] = -1;
        st.push(0);
        for(int i=1;i<arr.size(); i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(st.empty()) lvec[i] = -1;
            else lvec[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        int n=arr.size();
        rvec[n-1] = n;
        st.push(n-1);

        for(int i=n-2; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(st.empty()) rvec[i] = n;
            else rvec[i] = st.top();
            st.push(i);
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        // form heights array
        vector<vector<int>> heights(m, vector<int>(n, 0));

        for(int j=0;j<n;j++) heights[0][j] = matrix[0][j] - '0';

        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '1')
                {
                    heights[i][j] = heights[i-1][j] + 1;
                }
                else heights[i][j] = 0;
            }
        }
        
        int maxarea=0;
        vector<int> res;
        for(int row = 0; row < m; row++)
        {
            res = heights[row];
            vector<int> nsl(n), nsr(n);
            fillns(res, nsl, nsr);

            for(int j=0; j<n; j++)
            {
                int width = nsr[j] - nsl[j] - 1;
                int height = res[j];
                maxarea = max(maxarea, height*width);
            }
        }

        return maxarea;
    }
};