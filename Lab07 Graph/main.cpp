#include <bits/stdc++.h>

using namespace std;
int parent[1005];
int sz[1005];

struct edge {
    int x, y, w;

    edge(int x, int y, int w) {
        this->x = x;
        this->y = y;
        this->w = w;
    }
};

void Make(int x) {
    parent[x] = x;
    sz[x] = 1;
}

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
    return true;
}

void Krusal(int n, vector<edge> v) {
    vector<edge> ans;
    int trongso = 0;
    for (auto x: v) {
        if (ans.size() == n - 1) break;
        if (Union(x.x, x.y)) {
            ans.push_back(x);
            trongso += x.w;
        }
    }
    for (auto x: ans) {
        cout << x.x << " " << x.y << endl;
    }
    cout << "trong so : " << trongso;
}

void DFS(int n, int par[], bool visited[], vector<int> adj[], int u) {
    cout << u << " ";
    visited[u] = true;
    for (auto x: adj[u]) {
        if (!visited[x]) {
            par[x] = u;
            DFS(n, par, visited, adj, x);
        }
    }
}

void URDFS(int n, int par[], bool visited[], vector<int> adj[], int u) {
    stack<int> st;
    st.push(u);
    visited[u] = true;
    while (!st.empty()) {
        int v = st.top();
        cout << v << " ";
        visited[v] = true;
        st.pop();
        for (auto x: adj[v]) {
            if (!visited[x]) {
                par[x] = v;
                st.push(x);
            }
        }
    }
}

void BFS(int n, int par[], bool visited[], vector<int> adj[], int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        visited[v] = true;
        for (auto x: adj[v]) {
            if (!visited[x]) {
                visited[x] = true;
                par[x] = v;
                q.push(x);
            }
        }
    }
}

void Dijkstra(int n, int par[], bool visited[], vector<pair<int, int>> adj[], int dis[], int u) {
    dis[u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,u});
    while(!pq.empty()){
        pair<int,int> front =pq.top();
        pq.pop();
        int v=front.second;
        if(!visited[v]){
            visited[v]=true;
            for(auto x: adj[v]){
                int k=x.second;
                int w=x.first;
                if(dis[k] > dis[v]+w ){
                    par[k]=v;
                    dis[k]=dis[v]+w;
                    pq.push({dis[k],k});
                }
            }
        }
    }
}

void Prim(int n, int par[], bool visited[], vector<pair<int, int>> adj[],int u){
    int trongso=0;
    priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<pair<int,int>>mst;
    for(auto x:adj[u]){
        par[x.second]=u;
        pq.push(x);
    }
    visited[u]=true;
    while (!pq.empty()){
        int top=pq.top().second;
        int w=pq.top().first;
        pq.pop();
        if(!visited[top]){
            trongso+=w;
            mst.push_back({par[top],top});
            visited[top]=true;
            for(auto x:adj[top]){
                if(!visited[x.second]){
                    par[x.second]=top;
                    pq.push(x);
                }
            }
        }
    }
    for(auto x:mst){
        cout<<x.first<<"-"<<x.second<<" ";
    }
    cout<<endl<<trongso<<endl;
}

int main() {
//    int n,m;
//    cin>>n>>m;
//    vector<edge>v;
//    for(int i=1;i<=m;i++){
//        int x,y,w;
//        cin>>x>>y>>w;
//        Make(x);
//        Make(y);
//        edge ed=edge(x,y,w);
//        v.push_back(ed);
//    }
//    sort(v.begin(),v.end(),[](edge a, edge b)->bool{
//        return a.w<b.w;
//    });
//
//    Krusal(n,v);

//    int n, m;
//    ifstream CIN("input.txt");
//    CIN >> n >> m;
//    vector<int> adj[n];
//    for (int i = 0; i < m; i++) {
//        int x, y;
//        CIN >> x >> y;
//        adj[x].push_back(y);
//        adj[y].push_back(x);
//    }
//    int par[n];
//    bool visited[n];
//    fill(par, par + n, 0);
//    fill(visited, visited + n, false);
//    int u, v;
//    CIN >> u >> v;
//    // DFS(n,par,visited,adj,u);
//    //URDFS(n,par,visited,adj,u);
//    BFS(n, par, visited, adj, u);
//
//    cout << endl;
//    if (!visited[v]) {
//        cout << "Khong ton tai duong di" << endl;
//    } else {
//        vector<int> ans;
//        while (v != u) {
//            ans.push_back(v);
//            v = par[v];
//        }
//        ans.push_back(u);
//        reverse(ans.begin(), ans.end());
//        for (auto x: ans) {
//            cout << x << " ";
//        }
//    }

    int n, m;
    ifstream CIN("input2.txt");
    CIN >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int x, y, w;
        CIN >> x >> y >> w;
        adj[x].push_back({w, y});
    }
    int par[n];
    bool visited[n];
    int dis[n];
    fill(par, par + n, 0);
    fill(dis, dis + n, INT_MAX);
    fill(visited, visited + n, false);
    int u, v;
    CIN >> u >> v;

//    Dijkstra(n,par,visited,adj,dis,u);
//    cout<<"DISTANCE"<<endl;
//    for(int i=0;i<n;i++){
//        cout<<dis[i]<< " ";
//    }
//    vector<int>ans;
//    cout<<endl<<"Path"<<endl;
//    while(v!=u){
//        ans.push_back(v);
//        v=par[v];
//    }
//    ans.push_back(u);
//    reverse(ans.begin(),ans.end());
//    for(auto x:ans){
//        cout<<x<<" ";
//    }

    Prim(n,par,visited,adj,0);
}