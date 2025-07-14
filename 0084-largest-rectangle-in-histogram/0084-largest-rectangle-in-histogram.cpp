class Solution {
public:
    void nextSmallerLeft(vector<int>& lvec, vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            lvec[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void nextSmallerRight(vector<int>& rvec, vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            rvec[i] = st.empty() ? n : st.top(); 
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int> lvec(n);
        vector<int> rvec(n);

        nextSmallerLeft(lvec, heights);
        nextSmallerRight(rvec, heights);

        int ans = 0;

        for(int i=0; i<n; i++)
        {
            // cout<<"l : "<<lvec[i]<<" "<<" r : "<<rvec[i]<<endl;

            int width = rvec[i] - lvec[i] - 1;
            int height = heights[i];
            ans = max(ans, width*height);
        }

        return ans;
    }
};