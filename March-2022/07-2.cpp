// acwing 周赛
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

map<double,int> kmap;

int res=0;
int main() {
    int n;
    int flag=1;
    int x0,y0;
    cin>>n>>x0>>y0;
    while(n--) {
        int x,y;
        cin>>x>>y;
        if(x==x0 && flag) {
            
        }
        double k=(y-y0)*1.0/(x-x0);
        cout<<k<<endl;
        if(kmap.find(k)==kmap.end()) { //没有查找到
            res++;
            kmap.insert(make_pair(k,1));
        }
    }
    cout<<res<<endl;
}
