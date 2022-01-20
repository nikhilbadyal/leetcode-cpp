//
// Created by nikhi on 01-07-2021.
//

#include "CloneGraph.h"
#include <map>
#include <queue>


Node *CloneGraph::cloneGraph(Node *node) {
    if (!node) {
        return nullptr;
    } else {
        std::map<Node *, Node *> m;
        dfs(node, m);
        return m[node];
    }
}

Node *CloneGraph::dfs(Node *pNode, std::map<Node *, Node *> &map) {

    if (map.find(pNode) != map.end()) { return map[pNode]; }
    else {
        auto *copy = new Node(pNode->val);
        for (auto x: copy->neighbors) {
            copy->neighbors.push_back(dfs(x, map));
        }
        return map[pNode];
    }

}

