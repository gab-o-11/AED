#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
    int val;
    vector<Graph*> connections;
public:
    Graph(int value) : val(value) {}
    void addEdge(Graph* newEdge) {
        connections.push_back(newEdge);
    }
    void dfsAlg(unordered_map<Graph*, bool>& visited) {
        visited[this] = true;
        for (auto neighbor : connections) {
            if (!visited[neighbor]) {
                neighbor->dfsAlg(visited);
            }
        }
    }
    void dfs() {
        unordered_map<Graph*, bool> visited;
        dfsAlg(visited);
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {

}
