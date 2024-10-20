#include <bits/stdc++.h>
using namespace std;
#define int long long
class SegTree{
    public:
    vector<int>seg;
    int size=1;
    SegTree(vector<int>&a){
        int n=a.size();
        while(size<n)size=size<<1;
        seg.resize(2*size,0);
        build(a,0,0,size);
    }
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size())seg[x]=a[lx];
            return;
        }
        int m=(lx+rx)>>1;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        seg[x]=seg[2*x+1]+seg[2*x+2];
        return;
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            seg[x]=v;
            return;
        }
        int m=(lx+rx)>>1;
        if(i<m)set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        seg[x]=seg[2*x+1]+seg[2*x+2];
        return;
    }
    void set(int i,int v){
        return set(i,v,0,0,size);
    }
    int sum(int l,int r,int x,int lx,int rx){
        if(l>=rx||lx>=r)return 0;
        if(l<=lx&&r>=rx)return seg[x];
        int m=(lx+rx)>>1;
        int s1=sum(l,r,2*x+1,lx,m);
        int s2=sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    int sum(int l,int r){
        return sum(l,r,0,0,size);
    }
    
};
signed main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	SegTree st(a);
	for(int i=0;i<m;i++){
	    int op;
	    cin>>op;
	    if(op==1){
	        int i,v;
	        cin>>i>>v;
	        a[i]=v;
	        st.set(i,v);
	    }
	    else{
	        int l,r;
	        cin>>l>>r;
	        cout<<st.sum(l,r)<<endl;
	    }
	}

}
