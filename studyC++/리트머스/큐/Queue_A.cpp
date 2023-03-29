#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int n; //미팅에 입장하고자 하는 총 인원수
    cin >> n;

    // string s;
    int id;
    string name;
    char sex, type;
    deque<string> fe;   //여자 덱
    deque<string> ma;   //남자 덱
    int ans=0; //매치된 미팅 수

    //덱에 차곡차곡 넣어주기
    for(int i=0; i<n; i++){
        string him, her;
        cin >> id;
        cin >> name;
        cin >> sex;
        cin >> type;
        if(sex=='f'&&type=='F'){
            fe.push_front(name);
        }
        else if(sex=='f'&&type=='R'){
            fe.push_back(name);
        }
        else if(sex=='m'&&type=='F'){
            ma.push_front(name);
        }
        else if(sex=='m'&&type=='R'){
            ma.push_back(name);
        }

        if(!ma.empty() && !fe.empty()){
            him = ma.front();
            ma.pop_front();
            her = fe.front();
            fe.pop_front();
            ans++;
            cout << "Matched : "<<him<<" "<<her<<endl; 
        }
        
    }

    int men=0;
    int women=0;
    while(!ma.empty()){
        ma.pop_front();
        men++;
    }
    while(!fe.empty()){
        fe.pop_front();
        women++;
    }

    cout << ans <<" "<< men <<" "<< women << endl;

    return 0;
}