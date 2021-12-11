/*
    키의 합이 100 , 9명 중 7명
    20 7 23 19 10 15 25 8 13    --> 7 8 10 13 19 20 23
    
    입력받은 수를 vector에 저장하고 오름차순으로 정렬한다.
    전체 다 합친 수에서 100을 뺀 차이값 이용한다.
    그 차이값을 만들 수 있는 두 수를 빼내어 출력한다.

    *goto : 이중 for문을 바로 빠져나올 수 있음*
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main(){ 
    for(int i=0;i<9;i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int total_sum = 0;
    for(int i=0;i<9;i++){
        total_sum +=v[i];
    }
    int dif = total_sum - 100;
    for(int i=0;i<9;i++){
        for(int j=i;j<9;j++){
            if(v[i] + v[j] == dif){
                v[i] = 0;
                v[j] = 0;
                goto point;
            }
        }
    }

point:
    for(int i=0;i<9;i++){
        if(v[i]!=0) cout<<v[i]<<"\n";
    }
}