class Trie {
public:
    struct Node {
        bool isEnd= false;
        Node* child[26];
    }*root;
        
    Trie() {
        root = new Node();    
    }
    
    void insert(string word) {
        auto p = root;
        for (auto x: word) {
            int u = x - 'a';
            if (p->child[u] == NULL) p->child[u] = new Node();
            p = p->child[u];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (auto x: word) {
            int u = x - 'a';
            if (p->child[u] == NULL) return false;
            p = p->child[u];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (auto x: prefix) {
            int u = x - 'a';
            if (p->child[u] == NULL) return false;
            p = p->child[u];
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