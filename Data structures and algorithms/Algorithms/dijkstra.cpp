#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

int MAX = 1e6 + 7;
int TOTAL = 1e5 + 2;

/* int getMax(map<int, vector<int, int>> &graph) {
    int maxIndex = 0;

    for (auto it = graph.begin(); it != graph.end(); it++) {
        maxIndex = max((*it).first, maxIndex);

        for (auto it2 = graph[(*it).first].begin(); it2 != graph[(*it).first].end(); it2++) {
            maxIndex = max((*it2).first, maxIndex);
        }
    }

    return maxIndex;
}

void solve(map<int, vector<int, int>> &graph, int start, int stop) {
    // int maxNodeIndex = getMax(graph);
    int maxNodeIndex = stop;

    // cout << "Total number of nodes: " << maxNodeIndex << "\n";

    bool visited[maxNodeIndex + 1] = {0};
    int dist[maxNodeIndex + 1] = {0};
    int before[maxNodeIndex + 1];

    for (int i = 0; i <= maxNodeIndex; i++) {
        dist[i] = MAX;
    }

    priority_queue<pair<int, int>> q;
    q.push(pair<int, int>(start, 0));
    dist[start] = 0;

    while (!q.empty()) {
        int curIndex = q.top().first;
        q.pop();

        for (auto it = graph[curIndex].begin(); it != graph[curIndex].end(); it++) {
            int addIndex = (*it).first;
            int cost = (*it).second;

            if (dist[curIndex] + cost < dist[addIndex]) {
                before[addIndex] = curIndex;
            } 
            dist[addIndex] = min(dist[curIndex] + cost, dist[addIndex]);
            
            if (visited[addIndex]) {
                continue;
            }

            q.push(pair<int, int>(addIndex, dist[addIndex]));
        }

        visited[curIndex] = 1;
    }

    if (!visited[stop]) {
        cout << "-1";
        return;
    }

    for (int i = 0; i <= maxNodeIndex; i++) {
        cout << "Node index: " << i << " with cost " << dist[i] << "\n";
    } 

    int pathIndex = stop;
    string solPath = to_string(stop);

    while (pathIndex != start) {
        pathIndex = before[pathIndex];
        solPath = to_string(pathIndex) + " " + solPath;
    }

    // cout << "Solution path: " << solPath;
    cout << solPath;

    return;
} */

/* auto find(vector<pair<int, vector<pair<int, int>>>> &graph, int index) {
    for (auto it = graph.begin(); it != graph.end(); it++) {
        if (index == (*it).first) {
            return it;
        }
    }
    return graph.end();
} */


int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<pair<int, int>> graph[n + 2];

    int e1, e2, cost;

    while (m--) {
        cin >> e1 >> e2 >> cost;
        graph[e1].push_back(pair<int, int>(e2, cost));
        graph[e2].push_back(pair<int, int>(e1, cost));
    }

    /* for (auto itOut = graph.begin(); itOut != graph.end(); itOut++) {
        cout << "Node " << (*itOut).first << " with edges and costs:" << "\n";

        for (auto itIn = (*itOut).second.begin(); itIn != (*itOut).second.end(); itIn++) {
            cout << "Edge " << (*itIn).first << " cost " << (*itIn).second << "\n";
        }
    } */
    
    // int start, stop;
    // cin >> start >> stop;

    // solve(graph, 1, n);

    // int maxNodeIndex = n;

    // cout << "Total number of nodes: " << maxNodeIndex << "\n";

    bool visited[n + 1] = {0};
    int dist[n + 1] = {0};
    int before[n + 1];

    for (int i = 0; i <= n; i++) {
        dist[i] = MAX;
    }

    priority_queue<pair<int, int>> q;
    q.push(pair<int, int>(1, 0));
    dist[1] = 0;

    while (!q.empty()) {
        int curIndex = q.top().first;
        q.pop();

        for (auto it = graph[curIndex].begin(); it != graph[curIndex].end(); it++) {
            int addIndex = (*it).first;
            int cost = (*it).second;

            if (dist[curIndex] + cost < dist[addIndex]) {
                before[addIndex] = curIndex;
            } 
            dist[addIndex] = min(dist[curIndex] + cost, dist[addIndex]);

            if (visited[addIndex]) {
                continue;
            }
            
            q.push(pair<int, int>(addIndex, dist[addIndex]));
        }

        visited[curIndex] = 1;
    }

    if (!visited[n]) {
        cout << "-1";
        return 0;
    }

    /* for (int i = 0; i <= maxNodeIndex; i++) {
        cout << "Node index: " << i << " with cost " << dist[i] << "\n";
    } */

    int pathIndex = n;
    string solPath = to_string(n);

    while (pathIndex != 1) {
        pathIndex = before[pathIndex];
        solPath = to_string(pathIndex) + " " + solPath;
    }

    // cout << "Solution path: " << solPath;
    cout << solPath;

    return 0;
}