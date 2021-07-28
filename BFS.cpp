#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n , m;
vector<int> gr[N];


void BFS(int node) {
    bool vis[n + 1] = {false};
    int dis[n + 1] , pre[n + 1];
    queue <int> q;
    vector <int> res;

    dis[node] = 0;
    vis[node] = true;
    q.push(node);
    res.push_back(node);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : gr[cur]) {
            if (!vis[i]) {
                vis[i] = true;
                dis[i] = dis[cur] + 1;
                res.push_back(i);
                pre[i] = cur;
                q.push(i);

            }
        }
    }

    for (auto &i : res) cout << i << " ";
    cout << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    int node = 1;                 // starting node
    // cin >> node;
    BFS(node);
}
