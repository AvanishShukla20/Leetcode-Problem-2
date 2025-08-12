class WordDictionary {
public:
    struct TrieNode{
        // not supported in class or struct ->
        //vector<TrieNode*> vec(26);

        vector<TrieNode*> child;
        bool isEnd;
        TrieNode()
        {
            child.resize(26);
            for(int i=0; i<26; i++) child[i] = NULL;
            isEnd = false;
        }
    };
    
    bool searchHelper(int wordidx, string& word, TrieNode* root)
    {
        if(!root) return false;

        if(wordidx == word.size())
        {
            // if this is last node then only return true
            return root->isEnd;
        }

        if(word[wordidx] == '.')
        {
            // explore every path that can originate from each child character
            for(int i=0; i<26; i++)
            {
                if(root->child[i] != NULL && searchHelper(wordidx+1, word, root->child[i]) == true) return true;
            }
            return false;
        }
        else
        {
            int characteridx = word[wordidx] - 'a';
            // safety check
            if(characteridx < 0 || characteridx >= 26) return false;
            return searchHelper(wordidx+1, word, root->child[characteridx]);
        }
    }
    TrieNode* root ;
    
    WordDictionary() {

        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++)
        {
            int idx = word[i] - 'a';
            if(node->child[idx] == NULL)
            {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(0, word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */