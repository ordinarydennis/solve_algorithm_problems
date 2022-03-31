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

    vector<int> ret;

    void traversal(TreeNode* root)
    {
        ret.push_back(root->val);

        if (root->left)
        {
			traversal(root->left);

        }

        if (root->right)
        {
			traversal(root->right);

        }
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {

        if (root)
        {
            traversal(root);
        }

        return ret;

    }
};