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
    int maxDepth(TreeNode* root) {


        std::queue<TreeNode*> q;

        if (root)
        {
            q.push(root);
        }

        int ret = 0;

        while (q.size())
        {
			int size = q.size();

			for (int i = 0; i < size; i++)
			{
				auto* node = q.front();

				q.pop();

				if (node->left)
                    q.push(node->left);

				if (node->right)
					q.push(node->right);

			}
            ret++;
        }

        return ret;
    }
};
