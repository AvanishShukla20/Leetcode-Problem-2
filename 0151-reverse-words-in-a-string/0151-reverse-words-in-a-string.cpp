class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();

        int i=0;
        while(i < n)
        {
            if(s[i] == ' ')
            {
                i++;
                continue;
            }

            // if not then here only capture the word or number

            string temp = "";
            while(s[i] != ' ' && i <  n)
            {
                temp += s[i];
                i++;
            }

            cout<<temp<<endl;
            ans = temp + " " + ans;
        }
        
        ans.pop_back();
        return ans;
    }
};