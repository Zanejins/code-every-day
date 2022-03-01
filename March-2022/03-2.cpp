//Acwing840---开放寻址法处理散列表
#include<iostream>
#include<cstring>
using namespace std;

const int N=2e5+3;  //常常用质数，范围通常是要映射的2倍

const int flag=0x3f3f3f3f; //表示没有插入数，一定要在范围外
int h[N];


int find(int x) {  //查找，如何存在，返回的是下标，如果不存在，返回的是应该插入的下标
    int k=(x%N+N) % N;
    while(h[k]!=flag && h[k]!=x) {
        k++;
        if(k==N) k=0;
    }
    return k;
}
int main() {
    int n;
    scanf("%d",&n);
    memset(h,0x3f,sizeof h);  //初始全为坑
    while(n--) {
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(op[0]=='I') {
            int k=find(x);
            h[k]=x;
        }
        else {
            int k=find(x);
            if(h[k]!=flag) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

