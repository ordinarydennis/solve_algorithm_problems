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
    int findSecondMinimumValue(TreeNode* root) {

        int left = -1;
        if (root->left)
        {
            left = root->left->val;
        }

        int right = -1;
        if (root->right)
        {
            right = root->right->val;
        }


        if (left != right)
        {
            return std::max(left, right);
        }
        else
        {
            return -1;
        }
    }
};