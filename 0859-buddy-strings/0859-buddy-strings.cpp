class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int mismatch = 0;
        int n = goal.size(), m = s.size();
        if(m != n) return false;
        
        vector<int> h1(26, 0), h2(26, 0);

        for(int i=0; i<n; i++)
        {
            h2[s[i] - 'a']++;
        }

        for(int i=0; i<n; i++)
        {
            h1[goal[i] - 'a']++;
        }

        for(int i=0; i<26; i++)
        {
            if(h1[i] != h2[i])
            {
                return false;
            }
        }


        for(int i=0; i<n; i++)
        {
            if(s[i] != goal[i]) mismatch++;
        }

        if(mismatch == 0)
        {
            for(int i=0; i<n-1; i++)
            {
                if(s[i] != s[i+1]) return false;
            }

            return true;
        }

        return (mismatch == 2) ;
    }
};