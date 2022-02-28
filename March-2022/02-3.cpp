//acwing839 堆模拟-----堆的一些基本操作
#include<iostream>
#include<string.h>
using namespace std;

const int N=1e5+10;
int n;
int h[N],psize;
int ph[N]; //  第k个插入的指向了堆中的哪一个
int hp[N]; // 堆总的第k个指向了插入的哪一个

void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}


void down(int u) {
    int t=u;
    if(u*2<=psize && h[u*2]<h[t]) t=2*u;
    if(u*2+1<=psize && h[u*2+1]<h[t]) t=2*u+1;
    if(u!=t) {
        heap_swap(u,t);
        down(t);
    }
}
void up(int u) {
    while(u/2 && h[u/2]>h[u]) {
        heap_swap(u,u/2);
        u>>=1;
    }
}
/*
简要总结一下读入的问题：
字符串的读入：char s[10]; -> scanf("%d",s); 注意不能加引用符合->判断的话用strcmp，如何相等为0,注意不能用==
*/
int main() {
    int n;
    int m=0; //用于计数第一个插入
    scanf("%d",&n);
    while(n--) {
        char op[5];
        int k,x;
        scanf("%s",op);
        if(!strcmp(op,"I")) {
            scanf("%d",&x);
            psize++;
            m++;
            ph[m]=psize;
            hp[psize]=m;
            h[psize]=x;
            up(psize);
        }
        else if(!strcmp(op,"PM")) 
            printf("%d\n",h[1]);
        else if(!strcmp(op,"DM")) {
            heap_swap(1,psize);
            psize--;
            down(1);
        }
        else if(!strcmp(op,"D")) {
            scanf("%d",&k);
            k=ph[k];
            heap_swap(k,psize);
            psize--;
            up(k);
            down(k);
        }
        else {
            scanf("%d%d",&k,&x);
            k=ph[k];
            h[k]=x;
            up(k);
            down(k);
        }
    }
    return 0;
}

