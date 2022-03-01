//acwing826---拉链法散列表的插入和查找
#include<iostream>
#include<cstring>
using namespace std;

const int N=1e5+3;  //常常用质数，可以先写个程序计算一下

int h[N];//h[k]指向该链表的第一个节点的idx
int e[N],ne[N],idx; //链表

void insert(int x) {
    int k=(x%N+N)%N;
    e[idx]=x;       //头插法
    ne[idx]=h[k];
    h[k]=idx++;
}

bool find(int x) {
    int k=(x%N+N) % N;
    for(int i=h[k];i!=-1;i=ne[i]) {
        if(e[i]==x)
            return true;
    }
    return false;
}
int main() {
    int n;
    scanf("%d",&n);
    
    memset(h,-1,sizeof h); //初始链表为空，用-1来表示
    while(n--) {
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(op[0]=='I') insert(x);
        else {
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

