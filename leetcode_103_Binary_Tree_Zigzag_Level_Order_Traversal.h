class Solution {

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (nullptr == root)
        {
            return vector<vector<int>>();
        }

        queue<TreeNode*> q;

        q.push(root);

        vector<vector<int>> ret;

        bool isLeft = true;
        while (!q.empty())
        {
            vector<int> v(q.size());

            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto* n = q.front();

                q.pop();

                if (isLeft)
                {
                    v[i] = n->val;
                }
                else
                {
                    v[size - i - 1] = n->val;
                }

                if (n->left)
                {
                    q.push(n->left);
                }

                if (n->right)
                {
                    q.push(n->right);
                }
            }

            ret.push_back(std::move(v));

            isLeft = !isLeft;
        }

        return ret;
    }

};