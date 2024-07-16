#include<bits/stdc++.h>
using namespace std;
int main(){
    set<pair<int,int>>st;
    vector<int>distance(V,1e9);//V is vertices
    st.insert({0,S});//S is source
    distance[S]=0;
    while(!st.empty()){
        auto it=*(st.begin());
        int node=it.second;
        int dis=it.first;
        st.erase(it);
        for(auto jt:adj[node]){
            int adjNode=jt[0];
            int ew=jt[1];
            if(distance[adjNode]>ew+dis){
                if(distance[adjNode]!=1e9){
                    st.erase({distance[adjNode],adjNode});
                }
                distance[adjNode]=ew+dis;
                st.insert({distance[adjNode],adjNode});
            }
        }
    }
    return distance
}