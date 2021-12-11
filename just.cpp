#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
vector<long long> v;
int main(){
    time_t start = clock();
    for(double i=0;i<100000000;i++){
        v.push_back(i); //1억에 1.6초?
    };
    time_t end = clock();
    double times = double(end-start);
    cout<<times;
}