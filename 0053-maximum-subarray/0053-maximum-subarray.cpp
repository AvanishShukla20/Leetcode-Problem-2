class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(n+1, 0);
        vec[0] = 0;
        int gmin = 0, ans = INT_MIN;
        int pfSum = 0;
        for(int i=0; i<n; i++)
        {
            pfSum += nums[i];
            ans = max(ans, pfSum - gmin);

            if(pfSum < gmin)
            {
                gmin = pfSum;
            }
        }

        return ans;
    }
};