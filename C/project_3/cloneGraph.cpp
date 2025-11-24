#include <vector>


using namespace std; 


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

    Node(int _val, vector<Node*> _neighboors) {
        val = _val; 
        neighbors = _neighboors;
    }
};

class Solution {
    public:
    Node* cloneGraph(Node* graph) {
        Node response;



        return &response;
    }
};

int main() {

    Solution solution; 

    Node Node1(1);
    Node Node2(2);
    Node Node3(3);
    Node Node4(4);

    Node1.neighbors.push_back(&Node2);
    Node1.neighbors.push_back(&Node4);

    Node2.neighbors.push_back(&Node1);
    Node2.neighbors.push_back(&Node3);

    Node3.neighbors.push_back(&Node2);
    Node3.neighbors.push_back(&Node4);

    Node4.neighbors.push_back(&Node1);
    Node4.neighbors.push_back(&Node3);

    solution.cloneGraph(&Node1);

    return 1; 
}