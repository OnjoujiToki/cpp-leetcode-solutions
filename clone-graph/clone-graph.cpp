class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        queue<Node*> q;
        unordered_map<Node*, Node*>visited;
        visited[node] = new Node(node->val);
        q.push(node);
        while (!q.empty()) {
            auto curNode = q.front();
            q.pop();
            for (auto& n : curNode->neighbors) {
                if (visited.find(n) == visited.end())  {
                    visited[n] = new Node(n->val);
                    q.push(n);
                }
                visited[curNode]->neighbors.push_back(visited[n]);
            }
        }


        return visited[node];
    }
};