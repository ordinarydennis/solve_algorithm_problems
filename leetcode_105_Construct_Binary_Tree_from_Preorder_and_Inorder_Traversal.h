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

    std::unordered_map<int, int> inorderIndexMap;

    int rootIndex = 0;

    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int left, int right)
    {
        if (right < left)
        {
            return nullptr;
        }

        int inoderRootValue = preorder[rootIndex++];

        TreeNode* newNode = new TreeNode(inoderRootValue);

        int inoderRootIndex = inorderIndexMap[inoderRootValue];

        newNode->left = buildSubTree(preorder, inorder, left, inoderRootIndex - 1);
        newNode->right = buildSubTree(preorder, inorder, inoderRootIndex + 1, right);

        return newNode;

    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++)
        {
            inorderIndexMap.emplace(inorder[i], i);
        }

        return buildSubTree(preorder, inorder, 0, preorder.size() - 1);

    }
};