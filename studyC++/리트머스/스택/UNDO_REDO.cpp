#include <iostream>
#include <string>
#include <stack>
#include <deque>
using namespace std;

int main(){
    deque <char> un; //undo는 갯수가 10이 넘으면 앞에것을 지워야함으로 deque으로 구현
    stack <char> re;
    int  undo=0; //undo 이후 redo가 아닌 일반데이터를 입락받으면 redo스택은 비우기
    char c;

    //개행문자가 들어올때까지 입력받기
    do {
        cin >> c;
        if(c=='U'){
            if(!un.empty()){//un스택이 비어있지 않으면
                re.push(un.back());//un스택에서 꺼내서 re스택에 넣기
                un.pop_back();
            }
            else{//비어있으면 에러 띄우기
                cout << "ERROR" << endl;
                exit(0);
            }
            undo++;//undo count
        }
        else if(c=='R'){
            if(!re.empty()){//re스택이 비어있지 않으면
                un.push_back(re.top());//re스택에서 꺼내서 un스택에 넣기
                re.pop();
            }
            else{//비어있으면 에러 띄우기
                cout << "ERROR" <<endl;
                exit(0);
            }
            undo--;//undo상쇄
            
        }
        else{
            //일반 문자열이 들어오면 un스택에 넣기
            un.push_back(c);
            if(undo!=0){//undo가 모두 상쇄되지 않았다면
                //redu 전체 초기화
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
    } while (getc(stdin) == ' ');//엔터가 들어올때까지 입력받기

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
        cout << "EMPTY";
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
