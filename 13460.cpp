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
int cnt = 0;
bool isWall(pair<int,int> marble){
    for(int i=0;i<wall.size();i++){
        pair<int,int> w = wall[i];
        if(marble.first == w.first && marble.second == w.second)
        cnt++;
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
   bool done = false;
   pair<int,int> nextRed;
   pair<int,int> nextBlue;
   while(!done){
       bool H_sameline = false; //가로가 같은거
       bool W_sameline = false; //세로가 같은거
       bool redpositive = false;
       nextRed = make_pair(red.first + dy[swi], red.second + dx[swi]);
       nextBlue = make_pair(blue.first + dy[swi], blue.second + dx[swi]);

       if(isMarble(nextRed,nextBlue)){
           if((red.second > blue.second && red.first == blue.first))
           { 
               H_sameline = true;
               redpositive = true;
           }else if((red.second == blue.second && red.first > blue.first)){
               W_sameline = true;
               redpositive = true;
           }
        }

       if(!isWall(nextRed)) red = nextRed;
       if(!isWall(nextBlue)) blue = nextBlue;
       if(W_sameline){
           cout<<"W_sameline start, "<<red.first<<" "<<red.second<<" "<<blue.first<<" "<<blue.second;
           if(redpositive){
               blue.first--;
           } else red.first--;
       }
       else if(H_sameline){
           cout<<"H_sameline start, "<<red.first<<" "<<red.second<<" "<<blue.first<<" "<<blue.second;
           if(redpositive){
               blue.second--;
           } else red.second--;
       }
       if(isWall(nextRed) && isWall(nextBlue)) done = true;
       if(isHole(nextRed) || isHole(nextBlue)) done = true;
        cout<<"HERE";
   }
   if(nextRed == hole){
       red = nextRed;
       cout<<"RED HOLE IN";
       return;
   }
   if(nextBlue == hole){
       blue = nextBlue;
       cout<<"BLUE HOLE IN";
       return;
   }
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
                wall.push_back(make_pair() h,w));
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