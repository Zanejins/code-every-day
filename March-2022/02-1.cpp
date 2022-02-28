//acwing837.连接块中点的数量----> 并查集
#include<iostream>
using namespace std;

const int N=1e5+10;
int n,m;

int p[N],size[N]; //注意只有根节点的size是有意义的

//找祖宗
int find(int x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}

int main() {
    scanf("%d%d",&n,&m);
    //初始化--->切记不要忘
    for(int i=1;i<=n;i++) {
        p[i]=i;
        size[i]=1;
    }
    while(m--) {
        char op[5];
        int a,b;
        scanf("%s",op);
        // 合并
        if(op[0]=='C') {
            scanf("%d%d",&a,&b);
            if(!(find(a)==find(b)))  {
                size[find(b)]+=size[find(a)];// 这两个顺序语句不能错
                p[find(a)]=find(b);
            }
        }
	// 查找是否联通
        else if(op[1]=='1') {
            scanf("%d%d",&a,&b);
            if(find(a)==find(b)) puts("Yes");
            else puts("No");
        }
	// 返回连通块的数量
        else {
            scanf("%d",&a);
            printf("%d\n",size[find(a)]);
        }
    }
    return 0;
