#include<iostream>
#include<string>
using namespace std;

int solve(int n){
    int k = 666;
    int count = 0;
    string s;   
    while(1){
        s = to_string(k);
        for(int i=0;i<s.length()-2;i++){
           if(s[i]=='6' && s[i+1]=='6' && s[i+2]=='6'){
                count++;
                if(count == n){
                    return k;
                }           
                break; 
           }
        }
        k++;
    }
}

int main(){
   int N;
   cin>>N;
   cout<<solve(N);
}