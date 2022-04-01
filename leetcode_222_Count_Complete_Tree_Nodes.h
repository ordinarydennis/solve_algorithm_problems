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

    int num = 0;

    void traversal(TreeNode* root)
    {
        if (nullptr == root)
        {
            return;
        }

        num++;

		traversal(root->left);

		traversal(root->right);

    }

public:
    int countNodes(TreeNode* root) {

		traversal(root);

        return num;

    }
};
