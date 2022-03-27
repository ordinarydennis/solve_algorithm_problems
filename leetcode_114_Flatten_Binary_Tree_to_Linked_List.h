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

    vector<TreeNode*> nodeList;

    void preOrderTraversal(TreeNode* root)
    {

        nodeList.push_back(root);

        if (root->left)
        {
            preOrderTraversal(root->left);
        }

        if (root->right)
        {
            preOrderTraversal(root->right);
        }
    }

public:
    void flatten(TreeNode* root) {

        if (nullptr == root)
        {
            return;
        }

        nodeList.reserve(2000);

        preOrderTraversal(root);

        TreeNode** it = &root;

        root->left = nullptr;

        for (int i = 1; i < nodeList.size(); i++)
        {
            (*it)->right = nodeList[i];

            (*it)->left = nullptr;
            
            it = &(*it)->right;
        }

    }
};