// Graph should be 0-based index, will return distance from SRC to every node in array
// Works for both directed and undirected graphs, but weights should be positive
vector<int> Dijkstra(vector<vector<pair<int, int>>> gr, int n, int src){
    vector<int> dis(n, inf), par(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dis[src] = 0;
    q.push({0, src});

    while (q.size()){
        auto [nodeDis, curNode] = q.top();
        q.pop();
        if (dis[curNode] < nodeDis)continue;
        for (auto [nextNode, w] : gr[curNode]){
            if (dis[nextNode] > dis[curNode] + w){
                dis[nextNode] = dis[curNode] + w;
                par[nextNode] = curNode;
                q.push({dis[nextNode], nextNode});
            }
        }
    }
    return dis;
}
