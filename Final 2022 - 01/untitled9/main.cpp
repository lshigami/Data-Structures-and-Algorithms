#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

void DFS(int u,int v,int n,vector<int>adj[]){
    vector<int>parent(n+100,-1);
    vector<bool>visited(n+100,false);
    stack<int>st;
    st.push(u);
    while(!st.empty()){
        if(visited[st.top()]){
            st.pop();
            continue;
        }
        int top = st.top();
        visited[top]=true;
        st.pop();
        cout<<top<<" ";
        for(auto x:adj[top]){
            if(!visited[x]){
                st.push(x);
                parent[x]=top;
            }
        }
    }
    cout<<endl;
    if(!visited[v]){
        cout<<"Khong ton tai duong di"<<endl;
    }else{
        vector<int>ans;
        while(v!=u){
            ans.push_back(v);
            v=parent[v];
        }
        ans.push_back(u);
        reverse(ans.begin(),ans.end());
        cout<<"Path from "<<u<<" to "<<v<<" is : "<<endl;
        for(auto x:ans){
            cout<<x<<" ";
        }
    }
}

void BFS(int u,int v,int n,vector<int>adj[]){
    vector<int>parent(n+100,-1);
    vector<bool>visited(n+100,false);
    queue<int>q;
    q.push(u);
    while (!q.empty()){
        if(visited[q.front()]){
            q.pop();
            continue;
        }
        int top=q.front();
        cout<<top<<" ";
        q.pop();
        visited[top]=true;
        for(auto x:adj[top]){
            if(!visited[x]){
                q.push(x);
                parent[x]=top;
            }
        }
    }
    cout<<endl;
    if(!visited[v]){
        cout<<"Khong ton tai duong di"<<endl;
    }else{
        vector<int>ans;
        while(v!=u){
            ans.push_back(v);
            v=parent[v];
        }
        ans.push_back(u);
        reverse(ans.begin(),ans.end());
        cout<<"Path from "<<u<<" to "<<v<<" is : "<<endl;
        for(auto x:ans){
            cout<<x<<" ";
        }
    }
}

vector<int> Dijkstra(int u,int v,int n,vector<pair<int,int>>adj[]){
    vector<int>dis(n+100,INT_MAX);
    vector<bool>visited(n+100,false);
    vector<int>parent(n+100,-1);
    dis[u]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,u});
    while (!pq.empty()){
        pair<int,int>top=pq.top();
        pq.pop();
        int dinh= top.second;
        if(!visited[dinh]){
            visited[dinh]=true;
            for(auto x:adj[dinh]){
                int dinhke=x.second;
                int trongso=x.first;
                if(dis[dinhke] > dis[dinh]+trongso){
                    dis[dinhke] = dis[dinh]+trongso;
                    pq.push({dis[dinhke],dinhke});
                    parent[dinhke]=dinh;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<"tong khoang cach : "<<dis[v]<<endl;
    vector<int>ans;
    cout<<"Path from "<<u<<" to "<<v<<" is : ";
    while(v!=u){
        ans.push_back(v);
        v=parent[v];
    }
    ans.push_back(u);
    reverse(ans.begin(),ans.end());
    for(auto x:ans) {
        cout << x << " ";
    }
    cout<<endl;
    return ans;
}

void Prim(int u,int n,vector<pair<int,int>>adj[]){
    int trongso=0;
    vector<int>dis(n+100,INT_MAX);
    vector<bool>visited(n+100,false);
    vector<int>parent(n+100,-1);
    vector<pair<int,int>>mst;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    dis[u]=0;
    pq.push({0,u});

    while (!pq.empty()){
        pair<int,int>top=pq.top();
        int dinh=top.second;
        pq.pop();
        if(!visited[dinh]){
            visited[dinh]=true;
            trongso+=top.first;
            for(auto x:adj[dinh]){
                int dinhke=x.second;
                int w=x.first;
                if(!visited[dinhke] && dis[dinhke]>w){
                    dis[dinhke]=w;
                    parent[dinhke]=dinh;
                    pq.push(x);
                }
            }
        }
    }

    cout<<trongso<<endl;
    for(int i=1;i<n;i++){
        cout<<parent[i]<<"-"<<i<<" ";
    }

}


// duong di dai nhat
int main() {
//    ifstream CIN("input.txt");
    int n,m=0;
//    string x;
//    CIN>>n>>m;
//    vector<int>adj[n+100];
//    for(int i=0;i<m;i++){
//        int x,y;
//        CIN>>x>>y;
//        adj[x].push_back(y);
//    }
    int u,v;
//    CIN>>u>>v;
//
//    DFS(u,v,n,adj);
//    cout<<endl;
//    BFS(u,v,n,adj);
//    cout<<endl;

    ifstream Cin("input2.txt");
    Cin>>n>>m;
    vector<pair<int,int>>ADJ[n+100];
    for(int i=0;i<m;i++){
        int x,y,w;
        Cin>>x>>y>>w;
        ADJ[x].push_back({w,y});
//        ADJ[y].push_back({w,x});
    }
    Cin>>u>>v;
//    vector<int>FuT6=Dijkstra(u,6,n,ADJ);
//    vector<int>F6Tv=Dijkstra(6,v,n,ADJ);
//    cout<<endl<<"so path is : ";
//    for(auto x:FuT6){
//        cout<<x<<" ";
//    }
//    cout<<" then ";
//    for(auto x:F6Tv){
//        cout<<x<<" ";
//    }
    Prim(0,n,ADJ);

}
