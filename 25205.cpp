#include<iostream>
using namespace std;

char mo[12] = {'y','u','i','o','p','h','j','k','l','n','b','m'};
int main(){
    int tmp; cin>>tmp;
    string s; cin>>s;
    int len = s.length();
    char last = s[len-1];
    for(int i=0;i<12;i++){
        if(mo[i] == last){
            cout<<0;
            return 0;
        }
        else continue;
    }
    cout<<1;
}