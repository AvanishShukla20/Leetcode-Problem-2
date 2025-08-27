class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int freq = n/3;
        int e1, c1 = 0, c2 = 0, e2;

        for(int i=0; i<n; i++)
        {
            if(c1 == 0 && e2 != nums[i])
            {
                e1 = nums[i];
                c1++;
            }
            else if(c2 == 0 && e1 != nums[i])
            {
                e2 = nums[i];
                c2++;
            }
            else
            {
                if(e1 == nums[i]) c1++;
                else if(e2 == nums[i]) c2++;
                else
                {
                    // we decrease both because no this person Competes with both the already present candidates
                    c1--;
                    c2--;
                }
                
            }
        }
        
        vector<int> vec;
        // manual check is required because In Tescase [2, 2, 1, 3] is failed

        // if(c1 > freq) vec.push_back(e1);
        // if(c2 > freq) vec.push_back(e2);

        c1 = 0, c2 = 0;
        for(int i=0; i<n; i++) if(e1 == nums[i]) c1++;
        for(int i=0; i<n; i++) if(e2 == nums[i]) c2++;
        if(c1 > freq) vec.push_back(e1);
        if(c2 > freq) vec.push_back(e2);
        return vec;
    }
};