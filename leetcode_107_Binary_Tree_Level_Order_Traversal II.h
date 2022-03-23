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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        if (nullptr == root)
        {
            return {};
        }

        std::stack<vector<int>> nodeListStack;

        std::queue<TreeNode*> nodeQueue;

        nodeQueue.push(root);

        while (0 < nodeQueue.size())
        {
            int size = nodeQueue.size();

            vector<int> list;

            for (int i = 0; i < size; i++)
            {
                auto* node = nodeQueue.front();

                nodeQueue.pop();

				if (node->left)
				{
					list.push_back(node->left->val);
                    nodeQueue.push(node->left);
				}

				if (node->right)
				{
					list.push_back(node->right->val);
                    nodeQueue.push(node->right);
				}

            }

            if (list.size())
            {
                nodeListStack.push(std::move(list));
            }
            
        }

        vector<vector<int>> ret;

        int size = nodeListStack.size();
        
        ret.reserve(size);

        for (int i = 0; i < size; i++)
        {
            auto nodeList = std::move(nodeListStack.top());

            nodeListStack.pop();

            ret.emplace_back(std::move(nodeList));
        }

        if(root)
            ret.emplace_back(std::move(vector<int>{root->val}));

        return ret;
    }
};