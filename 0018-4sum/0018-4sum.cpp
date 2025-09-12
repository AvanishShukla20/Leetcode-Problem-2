class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates for i

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicates for j

                unordered_set<long long> seen;
                for (int k = j + 1; k < n; ++k) {
                    long long need = (long long)target - nums[i] - nums[j] - nums[k];

                    if (seen.count(need)) {
                        // found a quadruplet
                        vector<int> quad = {nums[i], nums[j], (int)need, nums[k]};
                        sort(quad.begin(), quad.end());
                        if (res.empty() || res.back() != quad) // avoid duplicates
                            res.push_back(quad);
                    }
                    seen.insert(nums[k]);
                }
            }
        }
        return res;
    }
};
