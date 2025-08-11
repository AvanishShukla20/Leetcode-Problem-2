class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=1;
        int ans = 0;
        sort(nums.begin(), nums.end());

        while(i < n && j < n)
        {
            if(i == j)
            {
                // typically happens when k == 0
                j++;
                continue;
            }
            int diff = abs(nums[j] - nums[i]);
            if(diff < k)
            {
                j++;
            }
            else if (diff > k) i++;
            else
            {
                ans++;
                int leftVal = nums[i];
                int rightVal = nums[j];
                while (i < n && nums[i] == leftVal) i++;   
                while (j < n && nums[j] == rightVal) j++; 
            }
        }

        return ans;
    }
};