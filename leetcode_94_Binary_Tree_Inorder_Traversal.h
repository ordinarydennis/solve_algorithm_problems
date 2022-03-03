class Solution {

    vector<int> ret;
    
    void inorder(TreeNode* root)
    {
        if (nullptr != root->left)
        {
            inorder(root->left);  
        }

        ret.push_back(root->val);

        if (nullptr != root->right)
        {
			inorder(root->right);
        }
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {

        if(nullptr != root)
            inorder(root);

        return ret;

    }
};