class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int countZero = 0; // best situation
        int mergeTimes = 0;
        for (int i = 0;i < m * n + 1;  i++) {
            sz.push_back(1);
            id.push_back(i);
        }
        int dx[2] = {1, 0};
        int dy[2] = {0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    countZero++;
                    for (int k = 0; k < 2; k++) {
                        int ax = i + dx[k];
                        int ay = j + dy[k];
                        if  (i == 0 || j == 0 || i == m-1 || j == n - 1) {
                            if (merge(i*n + j, m*n)) mergeTimes++;
                        }
                        if (ax >= 0 && ay >= 0 && ax < m && ay < n && grid[ax][ay] == 0) {
                            if (merge(ax*n + ay, i*n + j)) mergeTimes++;
                        }
                    }
                }
            }
        }
        cout<<countZero<<" " << mergeTimes;
        return countZero - mergeTimes;
    }
    
private:
    vector<int> id;
    vector<int> sz; 
    int root(int i) {
        while(id[i] != i) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    
    bool isConnnected(int i, int j){
        // sharing the same root;
        return root(i) == root(j);
    }
    
    bool merge(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j) return false;
        if (sz[i] < sz[j]) {
            sz[j] += sz[i];
            id[i] = j;
        } else {
            sz[i] += sz[j];
            id[j] = i;
        }
        return true;
    }
};