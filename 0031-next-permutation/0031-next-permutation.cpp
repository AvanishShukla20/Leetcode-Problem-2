class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx = n-1;
        vector<int> st;
        while(idx > 0 && nums[idx-1] >= nums[idx])
        {
            st.push_back(nums[idx]);
            idx--;
        }

        if(idx == 0)
        {
            // return 1st element;
            sort(nums.begin(), nums.end());
            return; 
        }

        st.push_back(nums[idx]);

        int val = nums[idx-1];
        int l, l_idx = st.size()-1;

        for(int i=st.size()-1; i>= 0; i--)
        {
            if(st[i] <= val) break;
            l = st[i];
            l_idx = i;
        }
        
        nums[idx-1] = l;
        st[l_idx] = val;

        int k = 0;
        for(int j = idx; j<n; j++)
        {
            nums[j] = st[k]; 
            k++;
        }


    }
};