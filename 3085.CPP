/*
    N은 3~50사이
    서로 바꿔보는 모든 경우의 수 : (N-1)+(N-1)+N

    제한시간 1초 충분.

    갯수 세는법
    dy dx , 만약 상하 / 좌우 중 같은 게 있다면 거기서 한번 더 탐색
    0,0 -> 0,1 -> ...으로만 가도 됨
    무조건 오른쪽, 아래쪽 방향으로만 실시

    
*/

#include<iostream>
#include<algorithm>
using namespace std;
char map[51][51];
int func_cal(int n){
    int result = 1;
    for(int i=0;i<n;i++){
        for(int k=0;k<n-2;k++){
            int count = 1;
            for(int j=k;j<n-1;j++){
               if(map[i][j] == map[i][j+1]) count++;
               else break;
            }
            result = max(result, count);
        }        
    }

    for(int j=0;j<n;j++){
        for(int k=0;k<n-2;k++){
            int count = 1;
            for(int i=k;i<n-1;i++){
               if(map[i+1][j] == map[i][j]) count++;
               else break;
            }
            result = max(result, count);
        }        
    }
    return result;
}

int main(){
    int N; cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    int result = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            swap(map[i][j],map[i][j+1]);
            result = max(result,func_cal(N));
            swap(map[i][j],map[i][j+1]);

            swap(map[j+1][i],map[j][i]);
            result = max(result,func_cal(N));
            swap(map[j+1][i],map[j][i]);
        }
    }
    cout<<result;
}

