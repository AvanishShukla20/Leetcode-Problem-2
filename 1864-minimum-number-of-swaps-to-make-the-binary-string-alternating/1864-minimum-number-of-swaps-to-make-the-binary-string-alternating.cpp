class Solution {
public:
    int flips(char ch, string& s)
    {
        int cnt = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(ch != s[i]) cnt++;

            if(ch == '1') ch = '0';
            else ch = '1';
        }
        return cnt;
    }
    int minSwaps(string s) {
       int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = s.size() - cnt0;

    if (abs(cnt0 - cnt1) > 1) return -1;

    int w1 = flips('1', s);
    int w2 = flips('0', s);

    if (cnt0 > cnt1) return w2 / 2; // must start with '0'
    if (cnt1 > cnt0) return w1 / 2; // must start with '1'
    return min(w1, w2) / 2; // both possible
    }
};