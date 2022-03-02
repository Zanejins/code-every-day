//acwing842--DFS实现排列组合
#include<iostream>
using namespace std;

const int N=10;
int n;
int path[N];
bool st[N]; //True表示该值用过了
void dfs(int u) {
    if(u==n) {
        for(int i=0;i<n;i++) printf("%d ",path[i]);
        puts("");
    }
    for(int i=1;i<=n;i++) {
        if(!st[i]) {
            path[u]=i;
            st[i]=true;
            dfs(u+1);
            st[i]=false; //恢复现场
        }
    }
    
}
int main() {
    scanf("%d",&n);
    dfs(0);
    return 0;
}
