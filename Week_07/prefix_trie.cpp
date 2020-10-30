class Trie {
private:
    /** TrieNode class */
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        int end;
        TrieNode(): end(0) {}
    };
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children.find(word[i]) == curr->children.end()) {
                curr->children[word[i]] = new TrieNode();
            }
            curr = curr->children[word[i]];
        }
        curr->end = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children.find(word[i]) == curr->children.end()) {
                return false;
            }
            curr = curr->children[word[i]];
        }
        return (curr->end == 1) ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (curr->children.find(prefix[i]) == curr->children.end()) {
                return false;
            }
            curr = curr->children[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
