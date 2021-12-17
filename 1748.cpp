/*
    N이 383이라고 가정하자 , 세자리수
    그럼 N/(10^3) < 1을 이용해 i는 3으로 시작
    이거 자릿수 다 구하는 법은 9*1+ ... + 9*{10^(i-2)} * (i-1) + i * (N-10^(i-1)+1)이다
    그럼 383은 9 + 90*2 + 3*(383-100+1) = 189 + 284*3 = 852+189=1041이다

    N이 120이면
    9*1 + 90*2 + 3*(120-100+1) = 189+21*3=189+63=252 이다.
*/
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int N; cin>>N;
    int digits = 0;
    int ans = 0;

    for(int i=1;i<10;i++){
        if(N/pow(10,i) < 1){
            digits = i;
            break;
        }
    }

    ans += digits*(N-pow(10,(digits-1))+1);

    for(int i=0;i<digits-1;i++){
        ans+=9*(pow(10,i)) * (i+1);
    }

    cout << ans;
}