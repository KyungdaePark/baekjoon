#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int cal1 = (a+b)%c;
    int cal2 = ((a%c) + (b%c))%c;
    int cal3 = (a*b)%c;
    int cal4 = ((a%c) * (b%c))%c;
    cout<<cal1<<endl;
    cout<<cal2<<endl;
    cout<<cal3<<endl;
    cout<<cal4<<endl;
}