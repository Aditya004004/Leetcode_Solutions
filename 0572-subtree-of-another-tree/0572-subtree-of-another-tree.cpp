/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void preorder(TreeNode* root, string &s) {
        if (root == nullptr) {
            s += "null,";
            return;
        }

        s += ","+to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string bigtree, shortree;

        preorder(root, bigtree);
        preorder(subRoot, shortree);

        return bigtree.find(shortree) != string::npos;
    }
};