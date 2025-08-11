class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> isflipped(n, 0);

        int flipsFromPast = 0;
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            //remove pastinfluences 
            if(i >= k)
            {
                if(isflipped[i-k] == 1)
                {
                    flipsFromPast--;
                }
                
            }

            if(flipsFromPast%2 == nums[i]) // affective flips is 1 and element is also 1, vice versa
            {
                if(i+k > n)
                {
                    return -1;
                }

                flipsFromPast++;
                ans++;
                isflipped[i] = true;
            }
        }

        return ans;
    }
};