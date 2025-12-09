// Last updated: 12/8/2025, 11:27:43 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.emplace(root);
        while (!q.empty()) {
            vector<int> temp;
            int sz = q.size();
            while (sz--) {
                Node* cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                for (Node* child : cur->children)
                    if (child) q.emplace(child);
            }
            res.emplace_back(temp);
        }
        return res;
    }
};