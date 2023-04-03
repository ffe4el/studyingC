#include <iostream>
#include <string>
#include <stack>
#include <deque>
using namespace std;

int main(){
    deque <char> un;
    stack <char> re;
    int n=11;
    bool undo=false; //undo 이후 redo가 아닌 일반데이터를 입락받으면 redo스택은 비우기
    char c;

    //개행문자가 들어올때까지 입력받기
    do {
        cin >> c;
        if(c=='U'){
            if(!un.empty()){
                re.push(un.back());
                un.pop_back();
            }
            else{
                cout << "ERROR" << endl;
                exit(0);
            }
            undo = true;
        }
        else if(c=='R'){
            if(!re.empty()){
                un.push_back(re.top());
                re.pop();
            }
            else{
                cout << "ERROR" <<endl;
                exit(0);
            }
            undo = false;
            
        }
        else{
            un.push_back(c);
            if(undo==true){
                //redu 초기화
                while(!re.empty()){
                    re.pop();
                }
            }
        }
        //un스택에 사이즈가 10보다 클때 10이 될때까지 pop_front()
        if(un.size()>10){
            while(un.size()!=10){
                un.pop_front();
            }
        }
    } while (getc(stdin) == ' ');

    //undo 스택 출력하기
    if(un.empty()){
        cout << "EMPTY";
    }
    else{
        while(!un.empty()){
            char a = un.back();
            cout << a << " ";
            un.pop_back();
        }
    }

    cout << endl;

    //redo 스택 출력하기
    if(re.empty()){
        cout << "EMPTY" <<endl;
    }
    else{
        while(!re.empty()){
            char b = re.top();
            cout << b << " ";
            re.pop();
        }
    }
    cout << endl;

    return 0;
}
