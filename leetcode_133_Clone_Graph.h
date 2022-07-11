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

	void traversalGraph(const Node* node, Node* dest, vector<bool>& check)
	{

		for (const auto* neighbor : node->neighbors)
		{
			Node* newNode = new Node(neighbor->val);

			dest->neighbors.push_back(newNode);

			if (false == check[neighbor->val])
			{
				check[neighbor->val] = true;
				traversalGraph(neighbor, newNode, check);
			}
		}

	}

public:
	Node* cloneGraph(Node* node) {

		vector<bool> check(101, false);

		Node* dest = new Node(node->val);

		check[node->val] = true;

		traversalGraph(node, dest, check);

		return dest;

	}
};