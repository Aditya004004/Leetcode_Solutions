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
    int ans=0;
    pair<int,int>dfs(TreeNode*node){
        if(!node) return{0,0};
        auto[leftsum,leftcnt]=dfs(node->left);
        auto[rightsum,rightcnt]=dfs(node->right);

        int sum=leftsum+rightsum+node->val;
        int cnt=leftcnt+rightcnt+1;
        if(sum/cnt == node->val)
            ans++;

        return{sum,cnt};

    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};