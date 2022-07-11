#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    if(n/2 < m) m = n-m;
    long long mul_top = 1;
    long long mul_bot = 1;
    for(int k=m;k>0;k--){
        mul_top = mul_top * (n-k+1);
        mul_bot = mul_bot * k;
    }
    cout << mul_top / mul_bot;
}