//模拟题----Acwing 3544 寻找变化前的01序列
#include<iostream>
using namespace std;

int main() {
    int n;
    string s;
    
    cin>>n;
    
    while(n--) {
        cin>>s;
        int cnt=0;
        
        for(int i=0;i<s.size();i++) {
            if(cnt==5) {
                cnt=0;
                continue;
            }
            if(s[i]=='1') cnt++;
            else cnt=0;
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
