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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (nullptr == root)
        {
            return vector<vector<int>>();
        }

        std::queue<TreeNode*> q;

        q.push(root);

        vector<vector<int>> ret;

        while (!q.empty())
        {

            int size = q.size();

            std::vector<int> v;

            for (int i = 0; i < size; i++)
            {
                auto* node = q.front();

                q.pop();

                v.push_back(node->val);
               
                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }

            }

            ret.push_back(std::move(v));

        }

        return ret;

    }
};