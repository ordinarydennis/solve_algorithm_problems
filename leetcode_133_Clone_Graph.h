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

//dfs
class Solution {

	Node* traverse(const Node* ori, std::unordered_map<const Node*, Node*>& checker)
	{

		Node* newNode = new Node(ori->val);

		checker.emplace(ori, newNode);

		for (const auto* nNode : ori->neighbors)
		{
			const auto& it = checker.find(ori);

			if (checker.end() == it)
			{
				newNode->neighbors.push_back(traverse(nNode, checker));
			}
			else
			{
				newNode->neighbors.push_back(it->second);
			}
		}

		return newNode;
	}


public:
	Node* cloneGraph(Node* node) {

		std::unordered_map<const Node*, Node*> checker;

		traverse(node, checker);

	}
};

//bfs
class Solution {

public:
	Node* cloneGraph(Node* node) {

		if (nullptr == node)
			return nullptr;

		std::queue<const Node*> q;

		q.push(node);

		std::unordered_map<const Node*, Node*> m;

		while (false == q.empty())
		{
			const Node* e = q.front();
			q.pop();

			Node* n = new Node(e->val);

			m.emplace(e, n);

			for (const Node* neighbor : e->neighbors)
			{
				const auto& it = m.find(neighbor);

				Node* newNeighbor = nullptr;

				if (m.end() == it)
				{
					newNeighbor = new Node(e->val);
					q.push(neighbor);
				}
				else
				{
					newNeighbor = it->second;
				}

				n->neighbors.push_back(newNeighbor);
			}

		}

		return m[node];

	}
};