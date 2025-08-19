class Solution {
public:
    bool check(unordered_map<char, int>& present, unordered_map<char, int>&  required)
    {
        for(auto &it : required)
        {
           if(present[it.first] < it.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        // vector<int> store(26, 0), temp(26, 0);
        unordered_map<char , int> required, present;

        for(auto u : t) required[u-'a']++;

        int i=0, j=0, n = s.size();
        int start_idx = -1;
        int len = INT_MAX;
        while(j < n)
        {
            char ch = s[j];
            present[ch-'a']++;

            while(i <= j && check(present , required) == true)
            {
                if(j-i+1 <= len)
                {
                    len = j-i+1;
                    start_idx = i;
                }

                present[s[i]-'a']--;
                i++;
            }

            j++;
        }

        cout<<start_idx<<endl;
        if(start_idx == -1) return "";

        string ans = s.substr(start_idx, len);
        return ans;
    }
};