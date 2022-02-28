//acwing 838 堆排序---> 堆的基本操作
#include<iostream>
#include<algorithm>

using namespace std;
const int N=1e5+10;

int n,m;
int h[N]; //堆
int hsize; //堆中元素的数量


void down(int u) {   //往下调整
    int t=u; //t用来存三者之间最小的标号，一开始默认为t
    if(u*2<=hsize&&h[u*2]<h[t]) t=u*2;
    if(u*2+1<=hsize&&h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t) {
        swap(h[u],h[t]);
        down(t);
    }
}
void up(int u) {  //往上调整
    while(u/2 && h[u/2]>h[u]) {
        swap(h[u/2],h[u]);
        u/=2;
    }
}
int main() {
   scanf("%d%d",&n,&m);
   //初始化，这是还不满足小顶堆
   for(int i=1;i<=n;i++) scanf("%d",&h[i]); //对数组又了新的理解 x父节点->左孩子 2x 右孩子2x+1
   hsize=n;  //注意这个不要忘
   //数组->堆，调整使它满足小顶堆
   for(int i=n/2;i>=0;i--) down(i);  //时间复杂度是O(n)；如果对于每个元素，分别插入是O(nlgn)，相比于插入的方法，效率更高
   
   while(m--) {
       printf("%d ",h[1]); //输出堆顶
       h[1]=h[hsize];
       hsize--;
       down(1);
   }
   return 0;
}
