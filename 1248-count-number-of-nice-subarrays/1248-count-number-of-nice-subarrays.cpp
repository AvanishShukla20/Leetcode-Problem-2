class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int sum = 0, n = nums.size(), ans =0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        for(int i=0; i < n; i++)
        {
            if(nums[i]%2 != 0) sum += 1;

            if(mpp.find(sum - k) != mpp.end()) ans += mpp[sum-k];

            mpp[sum]++;
        }

        return ans;

    }
};