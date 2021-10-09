class Trie {
public: // dont forget this line./...
    bool end;
    int count;
    int endCount;
    Trie* children[26];
    Trie() {
        end = false;
        count = 0;
        for (int i = 0; i <26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
private:
    Trie* root = new Trie();
    void insert(string word) {              /* Insert word into the trie */
        Trie* node = root;
        for(char c : word){
            node->count++;
            if(!node -> children[c - 'a']){
                node -> children[c - 'a'] = new Trie();
            }
            node = node -> children[c - 'a'];
        }
        node->count++;
        node -> end = true;
    }
    bool checkPrefix(string word) {
        Trie* node = root;
        for(char c : word){
            if (c == '.') return false;
            if(!node -> children[c - 'a']){
                return false;
            }
            node = node -> children[c - 'a'];
            if (node->count == 0) return false;
        }

       
        return true;
    }
    bool search(string word) {             /* Search word into the trie */
        Trie* node = root;
        if (node->count == 0) return false;
        for(char c : word){
            if (c == '.') return false;
            if(!node -> children[c - 'a']){
                return false;
            }
            node = node -> children[c - 'a'];
            if (node->count == 0) return false;
        }
        return node -> end;
    }
     void deleteNode(string word) {
        Trie* node = root;
        for (char c:word) {
            int u = c - 'a';
            node->count--;
            node = node->children[u];
        }
        node->count--;
        node->end = false;
    }

    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,1,-1,0};
public:
    vector<string> ans;
    string path;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (path.size() == 0 || !checkPrefix(path)) {
            return;
        }
        if (search(path) == true) {
            deleteNode(path);
            ans.push_back(path);
        }
        for (int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax >= 0 && ay >= 0 && ax < board.size() && ay < board[0].size()) {
                path += board[ax][ay];
                char c = board[ax][ay]; 
                board[ax][ay] = '.';
                dfs(board, ax, ay);
                path.pop_back();
                board[ax][ay] = c;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto word:words) {
            insert(word);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                path += board[i][j];
                char c = board[i][j]; 
                board[i][j] = '.';
                dfs(board, i, j);
                path.pop_back();
                board[i][j] = c;
            }
        }
        
        return ans;
    }
};