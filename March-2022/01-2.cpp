//Acwing143---Trie树
#include<iostream>
using namespace std;

const int N=1e5+10;
const int M=3e6+10;

int son[M][2],idx;

void insert(int x) {
    int p=0;
    for(int i=30;i>=0;i--) {
        int u=x>>i & 1;
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
}

int query(int x) {
    int res=0;
    int p=0;
    for(int i=30;i>=0;i--) {
        int u=x>>i & 1;
        if(son[p][!u]) {
            p=son[p][!u];
            res+=1<<i;
        }
        else {
            p=son[p][u];
            res+=0<<i;
        }
    }
    return res;
}
int main() {
    int n,a[N];
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        insert(a[i]);
    }
    int res=0;
    for(int i=0;i<n;i++) {
        res=max(res,query(a[i]));
    }
    cout<<res;
}
