#include<iostream>
using namespace std;
const int N=4;
bool check(int x) {
    int a[N],i=0;
    while(x) {
        a[i++]=x%10;
        x/=10;
    }
    int len=i;
    for(int i=0;i<len/2;i++) {
        if(a[i]!=a[len-i-1]) return false;
    }
    return true;
}

int main() {
    for(int i=0;i<=256;i++) {
        if(check(i*i)) {
           printf("%d\n",i);
        }
    } 
}

