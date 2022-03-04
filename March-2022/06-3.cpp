//字符串的各种操作----acwing 3545
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string s;
string t;
int n,m;

int main() {
    cin>>s>>n;
    while(n--) {
        string op;
        cin>>op;
        if(op=="COPY") {
            int l,r;
            scanf("%d%d",&l,&r);
            t=s.substr(l,r-l+1);
        }
        else if(op=="CUT") {
            int l,r;
            t=s.substr(l,r-l+1);
            s=s.erase(l,r-l+1);
            
        }
        else {
            int p;
            cin>>p;
            s.insert(p+1,t);
        }
    }
    
}
