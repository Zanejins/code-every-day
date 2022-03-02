//acwing 843  n皇后问题----DFS智商点
#include<iostream>
using namespace std;

const int N=20;

int n;
char g[N][N];
bool row[N];
bool col[N]; //列
bool dg[N];  //正对角线
bool udg[N]; //负对角线





void dfs(int x,int y,int s) {
    if(y==n) {  //1. 确定枚举的顺序
        y=0;x++;
    }
    if(x==n) {    //2. 确定枚举的终止条件
        if(s==n) {
            for(int i=0;i<n;i++) puts(g[i]);
            puts("");
        }
        return;
    }
                  //3. 确定分支采取的行动
    // 不放皇后
    g[x][y] = '.';
    dfs(x,y+1,s);
    
    //放皇后
    if(!row[x] && !col[y] && !dg[x+y] && !udg[x-y+n]) {
        g[x][y]='Q';
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=true;
        dfs(x,y+1,s+1);
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=false;
        g[x][y]='.';
    }
    
}



int main() {
    scanf("%d",&n);
    dfs(0,0,0);
    return 0;
}
