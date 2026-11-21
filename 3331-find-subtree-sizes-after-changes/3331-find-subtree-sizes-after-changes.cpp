
class Solution {
public:
    vector<int> answer;
    vector<int> newParent;
    vector<vector<int>> children;
    vector<vector<int>> path;

    void findParents(int u, string &s) {
        int ch = s[u] - 'a';

        // Find closest ancestor with same character
        if (!path[ch].empty()) {
            newParent[u] = path[ch].back();
        }

        // Add current node to the DFS path
        path[ch].push_back(u);

        // Visit original children
        for (int v : children[u]) {
            findParents(v, s);
        }

        // Backtrack
        path[ch].pop_back();
    }

    int dfs(int u, vector<vector<int>> &newChildren) {
        int size = 1;

        for (int v : newChildren[u]) {
            size += dfs(v, newChildren);
        }

        answer[u] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        children.resize(n);
        newParent = parent;
        answer.resize(n);
        path.resize(26);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
        findParents(0, s);

        vector<vector<int>> newChildren(n);

        for (int i = 1; i < n; i++) {
            newChildren[newParent[i]].push_back(i);
        }

        dfs(0, newChildren);

        return answer;
    }
};
