//Acwing 836--并查集
#include<iostream>
using namespace std;
const int N=1e5+10;
int n,m;
int p[N];

int find(int x) { //返回x的祖宗节点+路径压缩优化
    if(p[x]!=x) return p[x]=find(p[x]);
}

int main() {
    scanf("%d%d",&n,&m);
    //初始化，所有集合对应的根节点的父亲节点等于自己
    for(int i=1;i<=n;i++) p[i]=i;
    
    while(m--) {
        char op[2]; //读字符的时候建议以字符串的形式，因为可以为我们过滤到空格和回车，避免读入控制的难度
        int a,b;
        scanf("%s%d%d",&op,&a,&b);
        if(op[0]=='M') p[find(a)]=find(b);  //a的祖宗节点的父节点变为b的祖宗节点
        else {
            if(find(a)==find(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}
