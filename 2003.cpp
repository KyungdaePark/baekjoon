#include<iostream>
using namespace std;

int main(){
    int N,M;
    int count = 0;
    cin>>N>>M;
    int arr[10001];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=0;i<N;i++){
        int j = i;
        int sum = 0;
        while(true){
            if(sum>=M) break;
            sum = sum + arr[j];
            j++;
        }
        if(sum==M) count++;
    }
    cout<<count;
}