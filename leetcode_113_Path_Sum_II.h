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

    int target = 0; 

    vector<vector<int>> ret;

    void dfs(TreeNode* root, int sum, vector<int> nodes)
    {

        nodes.push_back(root->val);

        if (nullptr == root->left && nullptr == root->right)
        {
            if (target == root->val + sum)
            {
                ret.push_back(nodes);
                return;
            }
        }

        if (root->left)
        {
            dfs(root->left, root->val + sum, nodes);
        }

        if (root->right)
        {
            dfs(root->right, root->val + sum, nodes);
        }

    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        if (nullptr == root)
        {
            return ret;
        }

        target = targetSum;

        vector<int> nodes;

        dfs(root, 0, nodes);

        return ret;
    }
};