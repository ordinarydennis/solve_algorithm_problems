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

    TreeNode* root = nullptr;

    void dfs(TreeNode* preNode, TreeNode* currentNode, bool isLeft)
    {

        if (isLeft)
        {
            if (root->val < currentNode->val)
            {
                TreeNode temp = *root;

				root->left = currentNode->left;
				root->right = currentNode->right;

                currentNode->left = temp.left;
                currentNode->right = temp.right;

                preNode->left = root;

                return;
            }
        }
        else
        {
			if (currentNode->val < root->val)
			{
				TreeNode temp = *root;

				root->left = currentNode->left;
				root->right = currentNode->right;

				currentNode->left = temp.left;
				currentNode->right = temp.right;

				preNode->right = root;
                return;
			}
        }

		if (currentNode && currentNode->left)
		{
			dfs(currentNode, currentNode->left, isLeft);
		}

		if (currentNode && currentNode->right)
		{
			dfs(currentNode, currentNode->right, isLeft);
		}
    }


public:
    void recoverTree(TreeNode* root) {

        this->root = root;

        if (root && root->left)
        {
            dfs(root, root->left, true);
        }

        if (root && root->right)
        {
            dfs(root, root->right, false);
        }
        
    }
};