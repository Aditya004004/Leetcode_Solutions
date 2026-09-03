class Solution {
public:
    unordered_map<int, int> pos;

    TreeNode* build(vector<int>& inorder, int inL, int inR,
                    vector<int>& postorder, int postL, int postR) {
        if (inL > inR || postL > postR)
            return nullptr;

        int rootVal = postorder[postR];
        TreeNode* root = new TreeNode(rootVal);

        int idx = pos[rootVal];
        int leftSize = idx - inL;

        root->left = build(inorder, inL, idx - 1,
                           postorder, postL, postL + leftSize - 1);

        root->right = build(inorder, idx + 1, inR,
                            postorder, postL + leftSize, postR - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }

        return build(inorder, 0, n - 1,
                     postorder, 0, n - 1);
    }
};
