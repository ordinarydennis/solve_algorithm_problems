/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    Node* traverse(Node* node, std::unordered_map<Node*, Node*>& checker)
    {
        Node* newNode = new Node(node->val);

        checker.insert(
            { node, newNode }
        );

        for (Node* neighbor : node->neighbors)
        {
            const auto& it = checker.find(neighbor);

            Node* node = nullptr;

            if (checker.end() != it)
            {
                node = it->second;
            }
            else
            {
                node = traverse(neighbor, checker);
            }

            newNode->neighbors.push_back(node);

        }

        return newNode;
    }

public:
    Node* cloneGraph(Node* node) {

        if (nullptr == node)
        {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> checker;

        return traverse(node, checker);

    }
};