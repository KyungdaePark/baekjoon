#include<iostream>
#include<vector>
using namespace std;

int Height, Width;
char board[10][10];

vector<pair<int,int>> wall;
pair<int,int> red;
pair<int,int> blue;
pair<int,int> hole;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

bool isWall(pair<int,int> marble){
    for(int i=0;i<wall.size();i++){
        pair<int,int> w = wall[i];
        if(marble.first == w.first && marble.second == w.second)
        return true;
    }
    return false;
}

bool isHole(pair<int,int> marble){
    if(marble.first == hole.first && marble.second == hole.second) return true;
    else return false; 
}


bool isMarble(pair<int,int> marble, pair<int,int> marble2){
    if(marble.first == marble2.first && marble.second == marble2.second) return true;
    else return false; 
}
void move(int swi){
    if(swi==0){ // right
        while(true){
            //cout<<"While True : \n";
            pair<int,int> nextRed = make_pair(red.first,red.second+1);
            pair<int,int> nextBlue = make_pair(blue.first,blue.second+1);
            if((red.first == blue.first && red.second>blue.second)){ // 같은 줄에 있고 빨간색이 더 오른쪽이면
              //  cout<<"red front"<<"\n";
                if(!isWall(nextRed)){
                    red = nextRed;
                    blue = nextBlue;
                } else if(isWall(nextRed)) break; //빨간색이 벽에 닿아있는 상태면 끝냄
                if(isHole(red)) break;; //빨간색이 들어가면?
                if(isHole(blue)) break;
            }
            else if((red.first == blue.first && red.second<blue.second)){
             //   cout<<"blue front"<<"\n";
                if(!isWall(nextBlue)){
                    red = nextRed;
                    blue = nextBlue;
                } else if(isWall(nextBlue)) break;
                if(isHole(red)) break;; //빨간색이 들어가면?
                if(isHole(blue)) break;
            }
        }
    }
    else if(swi==1){ // down
        while(true){
            //cout<<"While True : \n";
            pair<int,int> nextRed = make_pair(red.first+1,red.second);
            pair<int,int> nextBlue = make_pair(blue.first+1,blue.second);
            if((red.first > blue.first && red.second==blue.second)){ // 같은 줄에 있고 빨간색이 더 아래쪽이면
              //  cout<<"red front"<<"\n";
                if(!isWall(nextRed)){
                    red = nextRed;
                    blue = nextBlue;
                } else if(isWall(nextRed)) break; //빨간색이 벽에 닿아있는 상태면 끝냄
                if(isHole(red)) break;; //빨간색이 들어가면?
                if(isHole(blue)) break;
            }
            else if((red.first < blue.first && red.second==blue.second)){
             //   cout<<"blue front"<<"\n";
                if(!isWall(nextBlue)){
                    red = nextRed;
                    blue = nextBlue;
                } else if(isWall(nextBlue)) break;
                if(isHole(red)) break;; //빨간색이 들어가면?
                if(isHole(blue)) break;
            }
        }
    }
    else if(swi==2){ // left
        while(true){
            //cout<<"While True : \n";
            pair<int,int> nextRed = make_pair(red.first,red.second-1);
            pair<int,int> nextBlue = make_pair(blue.first,blue.second-1);
            if((red.first == blue.first && red.second<blue.second)){ // 같은 줄에 있고 빨간색이 더 왼쪽이면
              //  cout<<"red front"<<"\n";
                if(!isWall(nextRed)){
                    red = nextRed;
                    blue = nextBlue;
                } else if(isWall(nextRed)) break; //빨간색이 벽에 닿아있는 상태면 끝냄
                if(isHole(red)) break;; //빨간색이 들어가면?
                if(isHole(blue)) break;
            }
            else if((red.first == blue.first && red.second>blue.second)){
             //   cout<<"blue front"<<"\n";
                if(!isWall(nextBlue)){
                    red = nextRed;
                    blue = nextBlue;
                } else if(isWall(nextBlue)) break;
                if(isHole(red)) break;; //빨간색이 들어가면?
                if(isHole(blue)) break;
            }
        }
    }
    else if(swi==3){ // up
        while(true){
            //cout<<"While True : \n";
            pair<int,int> nextRed = make_pair(red.first-1,red.second);
            pair<int,int> nextBlue = make_pair(blue.first-1,blue.second);
            if((red.first < blue.first && red.second==blue.second)){ // 같은 줄에 있고 빨간색이 더 위쪽이면
              //  cout<<"red front"<<"\n";
                if(!isWall(nextRed)){
                    red = nextRed;
                    blue = nextBlue;
                } else if(isWall(nextRed)) break; //빨간색이 벽에 닿아있는 상태면 끝냄
                if(isHole(red)) break; //빨간색이 들어가면?
                if(isHole(blue)) break;
            }
            else if((red.first > blue.first && red.second==blue.second)){
             //   cout<<"blue front"<<"\n";
                if(!isWall(nextBlue)){
                    red = nextRed;
                    blue = nextBlue;
                } else if(isWall(nextBlue)) break;
                if(isHole(red)) break; //빨간색이 들어가면?
                if(isHole(blue)) break;
            }
        }
    }
    if(isHole(red)) cout<<"RED HOLE IN\n";
    else if(isHole(blue)) cout<<"BLUE HOLE IN\n";
}

int main(){
    cin>>Height>>Width;
    for(int h=0;h<Height;h++){
        string s;
        cin>>s;
        for(int w=0;w<Width;w++){
            board[h][w] = s[w];
        }
    }

    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    for(int h=0;h<Height;h++){
        for(int w=0;w<Width;w++){
            if(board[h][w] == '#')
                wall.push_back(make_pair(h,w));
            if(board[h][w] == 'R')
                red = (make_pair(h,w));
            if(board[h][w] == 'B')
                blue = (make_pair(h,w));
            if(board[h][w] == 'O')
                hole = (make_pair(h,w));
        }
    }
    // for(int i=0;i<wall.size();i++)
    //     cout<<wall[i].first<<" "<<wall[i].second<<"\n";
    // cout<<"\n";
    // cout<<red.first<<" "<<red.second<<"\n";
    // cout<<blue.first<<" "<<blue.second<<"\n";
    // cout<<hole.first<<" "<<hole.second<<"\n";
    
    move(2);
    cout<<"moved"<<endl;
    cout<<red.first<<" "<<red.second<<"\n";
    cout<<blue.first<<" "<<blue.second<<"\n";
    move(1);
    cout<<"moved"<<endl;
    cout<<red.first<<" "<<red.second<<"\n";
    cout<<blue.first<<" "<<blue.second<<"\n";
    move(0);
    cout<<"moved"<<endl;
    cout<<red.first<<" "<<red.second<<"\n";
    cout<<blue.first<<" "<<blue.second<<"\n";
    move(1);
    cout<<"moved"<<endl;
    cout<<red.first<<" "<<red.second<<"\n";
    cout<<blue.first<<" "<<blue.second<<"\n";
    move(2);
    cout<<"moved"<<endl;
    cout<<red.first<<" "<<red.second<<"\n";
    cout<<blue.first<<" "<<blue.second<<"\n";

    
}

//https://www.acmicpc.net/problem/13460