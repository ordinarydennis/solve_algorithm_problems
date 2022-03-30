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


    int sum = 0;

    void treeTraversal(TreeNode* root, int num)
    {
        int cur = (num * 10) + root->val;

        if (nullptr == root->left && nullptr == root->right)
        {
            sum += cur;
            return;
        }

        if (root->left)
        {
            treeTraversal(root->left, cur);
        }

        if (root->right)
        {
            treeTraversal(root->right, cur);
        }
    }

public:
    int sumNumbers(TreeNode* root) {

        treeTraversal(root, 0);

        return sum;
    }
};