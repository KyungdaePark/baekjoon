#include<iostream>

using namespace std;

/*
    g(10)을 생각해보자. g(10) = f(1) + f(2) + f(3) + ... + f(9) + f(10)이다.
    여기서 각 f 정의역의 약수를 정리하면,
    x = 1 : 1
    x = 2 : 1,2
    x = 3 : 1,3
    x = 4 : 1,2,4
    x = 5 : 1,5
    x = 6 : 1,2,3,6
    x = 7 : 1,7
    x = 8 : 1,2,4,8
    x = 9 : 1,3,9
    x = 10 : 1,2,5,10
    여기서 1은 10개, 2는 5개, 3은 3개 ... 이다
    즉, g(x)에 대하여 x보다 작은 자연수 n이 있을 때
    각 n은 x/n개 만큼 존재한다.
    1 -> 10/1 : 10개
    2 -> 10/2 : 5개
    3 -> 10/3 : 3개 ...


*/

int main(){
    int tmp; cin>>tmp;
    long long sum = 0;
    for(int i=1;i<=tmp; i++){
        sum += i*(tmp/i);
    }
    cout<<sum;
}