class Solution {
public:
    bool solve(int idx, int k, int subsetSum, int& target,vector<bool>& used, vector<int>& nums)
    {
        if(k == 0) return true;
        if(subsetSum == target)
        {
            // don't stop here explore remaining subarray
            return solve(0, k-1, 0, target,used, nums);
        }

        int n = nums.size();

        for(int j=idx; j<n; j++)
        {
            if( used[j] == true || subsetSum + nums[j] > target)
            {
                continue;
            }

            used[j] = true;
            if(solve(j, k, subsetSum + nums[j] , target, used, nums) == true) return true;
            used[j] = false;
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;

        int target = total / k;
        vector<bool> used(nums.size(), false);
        sort(nums.rbegin(), nums.rend());
        return solve(0, k, 0, target,used, nums);

    }
};