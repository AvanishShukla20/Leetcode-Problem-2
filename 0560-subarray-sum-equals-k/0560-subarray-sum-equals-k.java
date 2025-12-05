class Solution {
    public int subarraySum(int[] nums, int k) {
        int sum = 0;
        int ans = 0;

        Map<Integer, Integer> mpp = new HashMap<>();

        for(int i=0; i<nums.length; i++)
        {
            sum += nums[i];
            System.out.print(sum);

            if(sum == k) ans += 1;
                
            

            int t = sum;
            mpp.put(t, mpp.getOrDefault(t, 0) + 1);

            for(int j=0; j<i; j++)
            {
                t -= nums[j];
                if(t == k) ans += 1;
            }
        }


        return ans;
    }
}