// 寻找奇特的数字---acwing3545
#include<iostream>
using namespace std;


int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int n,m;
        int cnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) {
            if(m%i==0&&m/i<=n) {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
