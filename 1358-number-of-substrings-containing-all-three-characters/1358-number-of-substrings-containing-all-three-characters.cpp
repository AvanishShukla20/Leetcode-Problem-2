class Solution {
public:
    bool isvalid(vector<int>& vec)
    {
        for(int i=0; i<3; i++)
        {
            if(vec[i] < 1) return false;
        }
        return true;
    }
    
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> vec(3, 0);
        int ans = 0;
        int j=0;
        for(int i=0; i<n; i++)
        {
            vec[s[i]-'a']++;
            while(isvalid(vec))
            {
                vec[s[j]-'a']--;
                j++;
            }
            int idx = j-1;
            ans += (idx+1);
        }
        return ans;
    }
};