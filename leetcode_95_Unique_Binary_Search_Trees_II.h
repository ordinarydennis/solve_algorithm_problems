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
 //Divide-and-conquer.
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end)
    {
        vector<TreeNode*> binarySearchTrees;
        if (start > end)
        {
            binarySearchTrees.push_back(NULL);
            return binarySearchTrees;
        }
        if (start == end)
        {
            binarySearchTrees.push_back(new TreeNode(start));
            return binarySearchTrees;
        }

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*> leftList = generateTrees(start, i - 1);
            vector<TreeNode*> rightList = generateTrees(i + 1, end);

            for (int l = 0; l < leftList.size(); l++)
            {
                for (int r = 0; r < rightList.size(); r++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftList[l];
                    root->right = rightList[r];

                    binarySearchTrees.push_back(root);
                }
            }
        }

        return binarySearchTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};

//DP
class Solution2 {
public:
    TreeNode* clone(TreeNode* root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode* newroot = new TreeNode(root->val);
        newroot->left = clone(root->left);
        newroot->right = clone(root->right);

        return newroot;
    }
    vector<TreeNode*> generateTrees(int n)
    {
        vector<TreeNode*> res(1, nullptr);

        for (int i = 1; i <= n; i++)
        {
            vector<TreeNode*> tmp;
            for (int j = 0; j < res.size(); j++)
            {
                TreeNode* oldroot = res[j];
                TreeNode* root = new TreeNode(i);
                TreeNode* target = clone(oldroot);

                root->left = target;

                tmp.push_back(root);

                if (oldroot != nullptr)
                {
                    TreeNode* tmpold = oldroot;
                    while (tmpold->right != nullptr)
                    {
                        TreeNode* nonroot = new TreeNode(i);
                        TreeNode* tright = tmpold->right;
                        tmpold->right = nonroot;
                        nonroot->left = tright;
                        TreeNode* target = clone(oldroot);
                        tmp.push_back(target);
                        tmpold->right = tright;
                        tmpold = tmpold->right;
                    }

                    tmpold->right = new TreeNode(i);
                    TreeNode* target = clone(oldroot);
                    tmp.push_back(target);
                    tmpold->right = nullptr;
                }
            }
            res = tmp;
        }
        return res;
    }
};
