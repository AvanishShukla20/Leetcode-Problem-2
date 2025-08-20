class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> hash(26, 0);
        int i =0, maxlen = 0, maxfreq = 0, changes;

        for(int j=0; j<n; j++)
        {
            hash[s[j]-'A']++;
            maxfreq = max(maxfreq, hash[s[j]-'A']);
            changes = (j-i+1) - maxfreq;

            while(changes > k)
            {
                hash[s[i]-'A']--;
                // recalculate maxfreq for correctness
                maxfreq = 0;
                for(int l=0; l<26; l++) maxfreq = max(maxfreq, hash[l]);
                i++;
                changes = (j-i+1) - maxfreq;
            }
            maxlen = max(maxlen, j-i+1);

        }


        return maxlen;
    }
};