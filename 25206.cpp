#include<iostream>
using namespace std;

float score_to_num(string s){
    if(s == "A+") return 4.5;
    else if(s=="A0") return 4.0;
    else if(s=="B+") return 3.5;
    else if(s=="B0") return 3.0;
    else if(s=="C+") return 2.5;
    else if(s=="C0") return 2.0;
    else if(s=="D+") return 1.5;
    else if(s=="D0") return 1.0;
    else if(s=="F") return 0.0;
}
int main(){
    float sum = 0;
    float score_sum = 0;
    for(int i=0;i<20;i++){
        string s; float p; string score;
        cin>>s>>p>>score;
        if(score=="P") continue;
        sum += p;
        score_sum += score_to_num(score) * p;
    }
    cout << score_sum / sum;
}