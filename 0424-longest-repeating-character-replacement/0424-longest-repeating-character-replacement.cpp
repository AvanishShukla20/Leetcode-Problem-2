class Solution {
public:
    int characterReplacement(string s, int k) {
        int i =0, j = 0;
        int maxfreq = 0;
        int windowSize = 0, ans = 0;

        if(k >= s.size()) return s.size();

        vector<int> hash(26, 0);

        while(j < s.size())
        {
            hash[s[j] - 'A']++;
            windowSize = j - i + 1;
            maxfreq = max(maxfreq, hash[s[j] - 'A']);

            if(windowSize - maxfreq <= k)
            {
                cout<<"increase : "<<windowSize<<endl;
                ans = max(ans, windowSize);
            }
            else
            {
                while(i < j && windowSize - maxfreq > k)
                {
                    hash[s[i] - 'A']--; 
                    maxfreq = max(maxfreq, hash[s[i] - 'A']);
                    i++;
                    windowSize = j - i + 1;
                }
                ans = max(ans, windowSize);
            }
            j++;
        }

        return ans;
    }
};