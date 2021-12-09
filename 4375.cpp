/*
    입력값을 n,
    1,11,111 ... 을 N이라고 하자
    정답을 구하는 방법은 N의 자릿수를 늘려가면서 모두 나눠보면 된다.
    대신 N을 늘려갈수록 숫자가 급격하게 커지므로 mod를 이용하면 된다.

    $공식$ N % k = (N % k) % k

    N1 = 1, N2 = 11, N=111 ...
    N이 늘어나는 방식은 N2 = N1 * 10 + 1이다.
    우리는 N2가 n의 배수가 아니라면,
    N2*10+1 이 n의 배수인지 검사할 것이다.
    
    여기서 (N2*10+1)%n  =  ((N2%n)*10+1)%n 이므로
    N3 = N2*10+1로 올리기 전, n으로 mod를 취하고 그 수를 *10 + 1 할것이다.

    가령, n=3인 경우,
    11 -> 11%3 =2
    111 -> (2*10+1)%3 = 0
    답 : 3

*/

#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n; cin>>n;
    int tmp = 1;
    int count = 1;
    while(true){
        if(tmp % 3 == 0) break;
        tmp = (tmp*10+1);
        tmp = tmp % 3;
        count++;
    }
    cout<<count<<endl;
}