#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

long long MAX = 1e11 + 1;
const long long TOTAL = 1e5 + 3;

vector<vector<pair<long long, long long>>> graph(TOTAL);
vector<pair<long long, long long>> blankVec;
bool visited[TOTAL] = {0};
long long dist[TOTAL] = {0};
long long before[TOTAL];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;

/* long long getMax(map<long long, vector<long long, long long>> &graph) {
    long long maxIndex = 0;

    for (auto it = graph.begin(); it != graph.end(); it++) {
        maxIndex = max((*it).first, maxIndex);

        for (auto it2 = graph[(*it).first].begin(); it2 != graph[(*it).first].end(); it2++) {
            maxIndex = max((*it2).first, maxIndex);
        }
    }

    return maxIndex;
}

void solve(map<long long, vector<long long, long long>> &graph, long long start, long long stop) {
    // long long maxNodeIndex = getMax(graph);
    long long maxNodeIndex = stop;

    // cout << "Total number of nodes: " << maxNodeIndex << "\n";

    bool visited[maxNodeIndex + 1] = {0};
    long long dist[maxNodeIndex + 1] = {0};
    long long before[maxNodeIndex + 1];

    for (long long i = 0; i <= maxNodeIndex; i++) {
        dist[i] = MAX;
    }

    priority_queue<pair<long long, long long>> q;
    q.push(pair<long long, long long>(start, 0));
    dist[start] = 0;

    while (!q.empty()) {
        long long curIndex = q.top().first;
        q.pop();

        for (auto it = graph[curIndex].begin(); it != graph[curIndex].end(); it++) {
            long long addIndex = (*it).first;
            long long cost = (*it).second;

            if (dist[curIndex] + cost < dist[addIndex]) {
                before[addIndex] = curIndex;
            } 
            dist[addIndex] = min(dist[curIndex] + cost, dist[addIndex]);
            
            if (visited[addIndex]) {
                continue;
            }

            q.push(pair<long long, long long>(addIndex, dist[addIndex]));
        }

        visited[curIndex] = 1;
    }

    if (!visited[stop]) {
        cout << "-1";
        return;
    }

    for (long long i = 0; i <= maxNodeIndex; i++) {
        cout << "Node index: " << i << " with cost " << dist[i] << "\n";
    } 

    long long pathIndex = stop;
    string solPath = to_string(stop);

    while (pathIndex != start) {
        pathIndex = before[pathIndex];
        solPath = to_string(pathIndex) + " " + solPath;
    }

    // cout << "Solution path: " << solPath;
    cout << solPath;

    return;
} */

/*auto find(
    //vector<pair<long long, vector<pair<long long, long long>>>> &graph,
    long long index
) {
    for (auto it = graph.begin(); it != graph.end(); it++) {
        if (index == (*it).first) {
            return it;
        }
    }
    return graph.end();
} */

void printPath(long long index) {
    if (index == 1) {
        cout << 1;
        return;
    }
    printPath(before[index]);

    cout << " " << index;
}


int main() {
    long long n, m;
    cin >> n;
    cin >> m;

    long long e1, e2, cost;

    while (m--) {
        cin >> e1 >> e2 >> cost;
        
        graph[e1].push_back({e2, cost});
        graph[e2].push_back({e1, cost});
    }

    /* for (auto itOut = graph.begin(); itOut != graph.end(); itOut++) {
        cout << "Node " << (*itOut).first << " with edges and costs:" << "\n";

        for (auto itIn = (*itOut).second.begin(); itIn != (*itOut).second.end(); itIn++) {
            cout << "Edge " << (*itIn).first << " cost " << (*itIn).second << "\n";
        }
    } */
    
    // long long start, stop;
    // cin >> start >> stop;

    // solve(graph, 1, n);

    // long long maxNodeIndex = n;

    // cout << "Total number of nodes: " << maxNodeIndex << "\n";

    for (long long i = 0; i <= n; i++) {
        dist[i] = MAX;
    }

    q.push({0, 1});
    dist[1] = 0;

    while (!q.empty()) {
        long long curIndex = q.top().second;
        long long curDist = q.top().first;
        q.pop();

        for (auto it = graph[curIndex].begin(); it != graph[curIndex].end(); it++) {
            long long addIndex = (*it).first;
            long long cost = (*it).second;

            if (visited[addIndex]) {
                continue;
            }

            if (dist[curIndex] + cost < dist[addIndex]) {
                before[addIndex] = curIndex;
                dist[addIndex] = dist[curIndex] + cost;
                q.push({dist[addIndex], addIndex});
            } 
        }

        visited[curIndex] = 1;
    }

    if (!visited[n]) {
        cout << "-1";
        return 0;
    }

    /* for (long long i = 0; i <= maxNodeIndex; i++) {
        cout << "Node index: " << i << " with cost " << dist[i] << "\n";
    } */

    long long pathIndex = n;
    printPath(pathIndex);

    // cout << "Solution path: " << solPath;
    // cout << solPath;

    return 0;
}