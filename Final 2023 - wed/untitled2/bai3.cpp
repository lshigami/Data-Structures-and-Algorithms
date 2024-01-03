#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int Dijkstra(int u, int v, int n, vector<pair<int, int>> adj[]) {
    vector<bool> visited(n + 100, false);
    vector<int> dis(n + 100, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[u] = 0;
    pq.push({0, u});

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        int dinh = top.second;
        pq.pop();
        if (!visited[dinh]) {
            visited[dinh] = true;
            for (auto x: adj[dinh]) {
                int dinhke = x.second;
                int w = x.first;
                if (dis[dinhke] > dis[dinh] + w) {
                    dis[dinhke] = dis[dinh] + w;
                    pq.push({dis[dinhke], dinhke});
                }
            }
        }
    }
    return dis[v];
}

int main() {
    int n, m;
    ifstream CIN("map.txt");
    CIN >> n >> m;
    vector<pair<int, int>> adj[n + 100];


    vector<pair<int, int>> adjwithout4[n + 100];

    for (int i = 0; i < m; i++) {
        int x, y, w;
        CIN >> x >> y >> w;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
        if(x!=4 && y!=4){
            adjwithout4[x].push_back({w, y});
            adjwithout4[y].push_back({w, x});
        }
    }
    int timeStart = min(Dijkstra(0, 7, n, adj) + Dijkstra(7, 6, n, adj) + Dijkstra(6, 8, n, adj),
                        Dijkstra(0, 6, n, adj) + Dijkstra(6, 7, n, adj) + Dijkstra(7, 8, n, adj));
    int timeEnd = Dijkstra(8,7,n,adjwithout4) + Dijkstra(7,0,n,adj);

    cout<<"Time start : "<<timeStart<<endl;
    cout<<"Time end : "<<timeEnd<<endl;

    cout<<timeEnd+timeStart;
}