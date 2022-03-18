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

    map<int, TreeNode*> m;
    int index = 0;

    void traversal(TreeNode* root)
    {
        if (nullptr == root)
        {
            return;
        }

        traversal(root->left);

        m[index++] = root;

        traversal(root->right);

        if (nullptr == root->right && nullptr == root->left)
        {
            m[index++] = nullptr;
        }
    }


public:
    bool isSymmetric(TreeNode* root) {

        traversal(root);

        int size = m.size();
        int end = size / 2;

        for (int i = 0; i < end; i++)
        {
            auto* left = m[i];
            auto* right = m[size - i - 1];
            if (left && right)
            {
                if (left->val != right->val)
                {
                    return false;
                }

            }
        }

        return true;

    }
};