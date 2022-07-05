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

    void traversalGraph(Node* origin, Node* dest)
    {
        if (nullptr == origin)
            return;

        Node* newNode = nullptr;

        for (auto* node : origin->neighbors)
        {
            newNode = new Node;
            newNode->val = node->val;
            dest->neighbors.push_back(newNode);
        }

        for (int i = 0; i < dest->neighbors.size(); i++)
        {
            traversalGraph(origin->neighbors[i], dest->neighbors[i]);
        }

    }

public:
    Node* cloneGraph(Node* node) {

        Node* dest = new Node;

        traversalGraph(node, dest);

        return dest;

    }
};