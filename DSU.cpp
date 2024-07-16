#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int findUpar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_v]>size[ulp_u]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
}