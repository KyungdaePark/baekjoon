#include<iostream>
using namespace std;
char board[5][5]={"ACAG","CGTA","ATCG","GAGT"};

int change(char x){
    if(x=='A') return 0;
    if(x=='G') return 1;
    if(x=='C') return 2;
    if(x=='T') return 3;
}
int main(){
    int N; cin>>N;
    string s; cin>>s;
    while(s.size()>1){
        int size = s.size();
        char first = s[size-2];
        char second = s[size-1];
        string temp = s.substr(0,size-2);
        int first_change = change(first);
        int second_change = change(second);
        char sum = board[first_change][second_change];
        s = temp + sum;      
    }
    cout<<s;
}