class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i=0; i<n; i++)
        {
            mpp[nums[i]]++;
        }

        int ans = 0;
        if(k == 0)
        {
            for(auto it : mpp)
            {
                if(it.second > 1) ans++;
            }
            return ans;
        }

        

        for (auto& it : mpp) {
            if (mpp.count(it.first + k)) ans++;
        }

        return ans;
    }
};