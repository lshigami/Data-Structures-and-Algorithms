#include <bits/stdc++.h>

using namespace std;

void Prim(vector<pair<int,int>>adj[],int n){
    int ans=INT_MIN;
    vector<bool>visited(n+100,false);
    vector<int>dis(n+100,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int u=1;
    pq.push({0,u});
    while(!pq.empty()){
        pair<int,int>top=pq.top();
        pq.pop();
        int dinh=top.second;
        if(!visited[dinh]){
            visited[dinh]=true;
            ans=max(ans,top.first);
            for(auto x:adj[dinh]){
                int dinhke=x.second;
                int w=x.first;
                if(!visited[dinhke] && dis[dinhke] > w){
                    dis[dinhke]=w;
                    pq.push(x);
                }
            }
        }
    }
    cout<<ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+100];
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }
    Prim(adj,n);
}