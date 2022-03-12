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

    vector<TreeNode*> ret;

    int max = 0; 

    void dfs(int n, TreeNode* root, int c)
    {
        if (max <= c)
        {
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (root->val == i)
            {
                continue;
            }

            if (root->val < i)
            {
               auto* node = new TreeNode;

               node->val = i;

               root->right = node;

               dfs(n, node, c + 1);

               ret.push_back(root);
            }
            else if(i < root->val)
            {
                auto* node = new TreeNode;

                node->val = i;

                root->left = node;

                dfs(n, node, c + 1);

                ret.push_back(root);
            }
        }

    }



public:
    vector<TreeNode*> generateTrees(int n) {

        max = n;

        TreeNode* root = new TreeNode;

        root->val = 1;

        dfs(0, root, 1);

        return ret;
    }
};