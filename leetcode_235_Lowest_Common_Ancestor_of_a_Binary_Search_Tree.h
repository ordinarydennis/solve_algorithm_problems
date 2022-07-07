/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

    TreeNode* ret = nullptr;

    bool dfs(TreeNode* root, int val1 , int val2)
    {
        if (nullptr == root)
        {
            return false;
        }

        if (ret != nullptr)
        {
            return false;
        }
        
        bool isFind = false;

        if (root->val == val1 || root->val == val2)
        {
            isFind = true;
        } 
        
        bool r1 =  dfs(root->left, val1, val2);
        bool r2 = dfs(root->right, val1, val2);

        if (r1 && r2)
        {
            ret = root;
        }

        if (isFind && (r1 || r2))
        {
            ret = root;
        }

        return isFind || r1 || r2;
    }


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, p->val, q->val);

        return ret;

    }
};