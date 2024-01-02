#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
#define ii pair<int,int>

void Prim(vector<ii>adj[],int n){
    int u=1;
    int trongso=0;
    vector<int>dis(n+100,INT_MAX);
    vector<int>par(n+100,-1);
    vector<bool>visited(n+100,false);
    priority_queue<ii,vector<ii>,greater<ii>>pq;
    dis[u]=0;
    pq.push({0,u});
    while (!pq.empty()){
        ii top = pq.top();
        pq.pop();
        int dinh =top.second;
        if(!visited[dinh]){
            visited[dinh]=true;
            trongso+=top.first;
            for(auto x:adj[dinh]){
                int dinhke=x.second;
                int w=x.first;
                if(!visited[dinhke] && dis[dinhke]>w){
                    dis[dinhke]=w;
                    pq.push(x);
                    par[dinhke]=dinh;
                }
            }
        }
    }
    cout<<trongso<<endl;
    for(int i=2;i<=n;i++){
        cout<<i<<" "<<par[i]<<endl;
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<ii>adj[n+100];
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }
    Prim(adj,n);
}
