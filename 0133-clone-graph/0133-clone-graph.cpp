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
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> oldnew;
        return dfs(node,oldnew);
    }
    Node* dfs(Node* node,map<Node*,Node*>&oldnew)
    {
        if(node==nullptr){
            return nullptr;
        }
        if(oldnew.count(node)){
            return oldnew[node];
        }
        Node* copy = new Node(node->val);
        oldnew[node] = copy;
        for(Node* ni : node->neighbors){
            copy->neighbors.push_back(dfs(ni,oldnew));
        }
        return copy;
    }
};