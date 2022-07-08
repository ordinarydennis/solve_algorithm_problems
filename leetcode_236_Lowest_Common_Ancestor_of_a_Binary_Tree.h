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

    bool traversal(TreeNode* root, int va1, int val2)
    {
        if (ret)
        {
            return false;
        }

        if (nullptr == root)
        {
            return false;
        }

        bool isFind = (root->val == va1 || root->val == val2);

        bool find1 = traversal(root->left, va1, val2);

        bool find2 = traversal(root->right, va1, val2);

        if (find1 && find2)
        {
            ret = root;
        }

        if (isFind && (find1 || find2))
        {
            ret = root;
        }

        return isFind || find1 || find2;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        traversal(root, p->val, q->val);

        return ret;

    }
};