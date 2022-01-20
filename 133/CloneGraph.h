//
// Created by nikhi on 01-07-2021.
//

#ifndef LEETCODE_CLONEGRAPH_H
#define LEETCODE_CLONEGRAPH_H

#include <vector>
#include <map>


class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val,std:: vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class CloneGraph{

public:
    Node* cloneGraph(Node* ) ;

    Node * dfs(Node *pNode, std::map<Node *, Node *>& map);

    Node *deepCopy(Node *node);
};

#endif //LEETCODE_CLONEGRAPH_H
