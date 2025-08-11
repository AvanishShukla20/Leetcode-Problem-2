class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (auto& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end()); // O(L log L), L = word length
            mp[sortedWord].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto& it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
