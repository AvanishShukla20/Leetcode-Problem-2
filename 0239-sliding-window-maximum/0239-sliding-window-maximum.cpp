class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //monotonic ddecreasing deque
        deque<int> dq;

        vector<int> res;

        int i = 0, n = nums.size();
        while(i < n)
        {
            while(!dq.empty() && dq.front() <= (i - k)) dq.pop_front();

            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

            // insert nums[i]
            dq.push_back(i);

            //check if window size is made for all i >= k - 1 .... window is made
            if(i >= k-1)
            {
                res.push_back(nums[dq.front()]);
            }
            i++;
        }
        return res;
    }
};