#include<iostream>
#include<cmath>
#include<time.h>

using namespace std;

int main(){
    double n; cin>>n;
    double sum = 0;
    clock_t start,end; double result;
    start = clock();
    for(double i=1;i<=n;i++){
        sum +=ceil(n/i);
    }
    cout<<sum;
    end = clock();
    result = double(end - start);
    cout<<"\n"<<result;
}