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

		m[node] = new Node(node->val);

		while (false == q.empty())
		{
			const Node* e = q.front();

			q.pop();

			for (const Node* neighbor : e->neighbors)
			{
				const auto& it = m.find(neighbor);

				if (m.end() == it)
				{
					m[neighbor] = new Node(neighbor->val);
					q.push(neighbor);
				}

				m[e]->neighbors.push_back(m[neighbor]);
			}

		}

		return m[node];

	}
};