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
public:
    vector<Node*> clonedNodes;
    Node* cloneGraph(Node* node) {
        clonedNodes.assign(101, nullptr);
        return cloneDfs(node, clonedNodes);
    }

    Node* cloneDfs(Node* node, vector<Node*>& clonedNodes) {
        if (node == nullptr) return nullptr;
        if (clonedNodes[node->val]) {
            return clonedNodes[node->val];
        }
        Node* clonedNode = new Node(node->val);
        clonedNodes[node->val] = clonedNode;
        for(Node* neighbor : node->neighbors) {
            Node* clonedNeighbor = cloneDfs(neighbor, clonedNodes);
            clonedNode->neighbors.push_back(clonedNeighbor);
        }
        return clonedNode;
    }
};