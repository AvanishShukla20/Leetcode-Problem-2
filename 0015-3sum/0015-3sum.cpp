class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(), nums.end());


        vector<vector<int>> ans;
        int prev_i_val = 0;
        for(int i=0; i<n; i++)
        {
            if(i > 0 && prev_i_val == nums[i]) continue;

            int start = i+1;
            int end = n-1;
            prev_i_val = nums[i];
            
            while(start < end)
            {
                int sum = nums[start] + nums[end] + nums[i];
                if(sum > 0)
                {
                    end--;
                }
                else if(sum < 0) start++;
                else
                {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    // increment start and decrement end until you find a different value at nums[start] and nums[end] respectively

                    int v_start = nums[start];
                    while(start < n && nums[start] == v_start)
                    {
                        start++;
                    }

                    int v_end = nums[end];

                    while(end >= 0 && nums[end] == v_end)
                    {
                        end--;
                    }

                    if(start >= end) break;
                }
            }
            
        }

        return ans;
    }
};