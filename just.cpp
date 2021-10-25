#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[51]{false};
int count[51];
bool isthere(int words_number, int index, vector<string> words, string target){
    //words_number : words의 index, index는 hit의 알파벳 index (고정), target은 hit
    for(int i=0;i<target.length();i++){
        if(i==index) continue;
        if(words[words_number][i] != target[i]) return false;
    }
    
    return true;
}

bool beforeCheck(vector<string> words, string target){
    for(int i=0;i<words.size();i++){
        if(target == words[i]) return true;
    }
    return false;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int size = words.size();
    if(!beforeCheck(words,target)) return 0;

    // for(int i=0;i<size;i++){  //i는 전체 갯수 : 6 
    //         for(int j=0;j<begin.length();j++) //j 는 hit의 index
    //             if(isthere(i, j, words, "lox")) cout<<words[i]<< " ";
    //     }
    queue<int> q;
    q.push(-1);
    while(!q.empty()){
        int current = q.front();
        if(current!=-1){
            if(words[current] == target){
                answer = count[current];
                break;
            }
        }
        q.pop();
        for(int i=0;i<size;i++){  //i는 전체 갯수 : 6 
            for(int j=0;j<begin.length();j++) //j 는 hit의 index
                {
                string next = current == -1 ? begin : words[current];
                if(isthere(i, j, words,next) && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                    if(current == -1) count[i] = 1;
                    else count[i] = count[current] + 1;
                } 
            }
        }
    }
    return answer;
}

int main(){
    string begin, target;
    cin>>begin>>target;
    vector<string> words;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        words.push_back(temp);
    }
    cout<<solution(begin,target,words);
}