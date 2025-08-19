class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mpp;
        for(int i=0; i<t.size(); i++) mpp[t[i]]++;
        int lenrequired = t.size();
        int minWindow = 1e8;
        int res_i = 0;
        int i=0, j= 0;
        while(j < n)
        {
            char ch = s[j];
            //if frequency of any character in our map is > 0 it means it should be part of our valid substring
            if(mpp[ch] > 0)
            {
                lenrequired--;
            }
            mpp[ch]--;

            while(i <= j && lenrequired == 0)
            {
                char ch1 = s[i];

                int currWindow = j - i + 1;
                mpp[ch1]++;
                if(currWindow < minWindow)
                {
                    minWindow = currWindow;
                    res_i = i;
                }
                if(mpp[ch1] > 0) lenrequired++;
                i++;
            }
            j++;
        }

        return (minWindow == 1e8) ? "" : s.substr(res_i, minWindow);
    }
};