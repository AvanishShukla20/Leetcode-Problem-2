class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
    int n = s.size(), i = 0;

    while (i < n) {
        if (s[i] == ' ') { i++; continue; }
        string temp = "";
        while (i < n && s[i] != ' ') temp += s[i++];
        words.push_back(temp);
    }

    reverse(words.begin(), words.end());
    string ans;
    for (int j = 0; j < words.size(); j++) {
        if (j) ans += " ";
        ans += words[j];
    }
    return ans;
    }
};