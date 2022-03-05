//acwing 第41场周赛
#include<iostream>
#include<string>

using namespace std;

string s1,s2;
int main() {
    cin>>s1>>s2;
    int i=1;
    while(s1[i]&&s1[i]<s2[0]) i++;
    
    string s;
    s=s1.substr(0,i)+s2[0];
    cout<<s<<endl;
}
