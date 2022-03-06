#include <string>
#include <vector>
#include <sstream>
#include<iostream>

using namespace std;


int finduser(string s, vector<string> id_list){
    for(int i=0;i<id_list.size();i++){
        if(id_list[i] == s) return i;
    }
}
vector<string> solution(vector<string> id_list, vector<string> report, int k) {
    vector<string> answer;
    vector<string> inputs;
    for(int i=0;i<report.size();i++){
        string tmp = report[i];
        istringstream ss(tmp);
        string stringBuffer;
        while(getline(ss,stringBuffer,' ')){
            answer.push_back(stringBuffer);
        }
    }
    return answer;
}

int main(){
    vector<string> id_list;
    vector<string> report;
    id_list.push_back("con");
    id_list.push_back("ryan");

    report.push_back("ryan con");
    report.push_back("ryan con");
    report.push_back("ryan con");
    report.push_back("ryan con");

    vector<string> answers(solution(id_list, report, 3));
    for(int i=0;i<answers.size();i++){
        cout<<" "<<answers[i]<<" ";
    }
}