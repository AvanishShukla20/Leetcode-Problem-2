class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int val = nums[0];

        for(int i=0; i<nums.size(); i++)
        {
            if(cnt == 0)
            {
                val = nums[i];
                cnt=1;
            }
            else if(nums[i] == val)
            {
                cnt++;
            }
            else cnt--;
            
        }

        return val;
    }
};