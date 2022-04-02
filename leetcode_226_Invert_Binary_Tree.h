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

//Recursive
class Solution {

public:
	TreeNode* invertTree(TreeNode* root) {

		if (root)
		{
			invertTree(root->left);

			invertTree(root->right);

			std::swap(root->left, root->right);
		}

		return root;

	}
};

//Non-Recursive Using stack
class Solution {

public:
    TreeNode* invertTree(TreeNode* root) {

        std::stack<TreeNode*> stk;

        stk.push(root);

        while (!stk.empty()) {

            TreeNode* p = stk.top();

            stk.pop();

            if (p) {

                stk.push(p->left);

                stk.push(p->right);

                std::swap(p->left, p->right);

            }
        }
        return root;
    }
};

//Non-Recursive Using Queue
class Solution {

public:
    TreeNode* invertTree(TreeNode* root) {

        std::queue <TreeNode*> que;

        que.push(root);

        while (!que.empty()) {

            TreeNode* p = que.front();

            que.pop();

            if (p) {

                que.push(p->left);

                que.push(p->right);

                std::swap(p->left, p->right);

            }
        }
        return root;
    }
};
