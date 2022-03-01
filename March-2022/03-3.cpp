//acwing841--字符串哈希---前缀字符串哈希
#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ULL;
const int N=1e5+10;
const int P=131; //表示进制数，往往取131

ULL h[N];          //因为要对2^64取模，这里直接用unsign的即可
char str[N];
ULL p[N];
int n,m;

ULL hash_str(int l,int r) {
    return h[r]-h[l-1]*p[r-l+1];
}


int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", str + 1);
    p[0]=1;
    for(int i=1;i<=n;i++) {
        p[i]=p[i-1]*P;  //p[i]表示p的i次方
        h[i]=h[i-1]*P+str[i]; //h[i]表示前i个字母的hash值
    }
    
    while(m--) {
        int l1,r1,l2,r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(hash_str(l1,r1)==hash_str(l2,r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}
