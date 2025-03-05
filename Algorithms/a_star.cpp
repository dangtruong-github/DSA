#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve(map<int, vector<int>> &graph) {
    return;
}

int main() {
    int n;
    map<int, vector<int>> graph;
    vector<int> blankVec;

    cin >> n;

    int e1, e2, cost;

    while (n--) {
        cin >> e1 >> e2 >> cost;
        if (graph.find(e1) == graph.end()) {
            graph[e1] = blankVec;
        }
        /* if (graph.find(e2) == graph.end()) {
            graph[e2] = blankVec;
        } */

        graph[e1].push_back(e2);
        // graph[e2].push_back(e1);
    }

    solve(graph);

    return 0;
}