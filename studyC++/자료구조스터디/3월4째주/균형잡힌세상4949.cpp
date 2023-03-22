#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(){
    while(true){ //일단 계속 입력을 받고 실행을 한다 
        stack <char> st; // while문 안에서 초기화 시켜줘야한다.
        string ans = "yes"; // while문 안에서 초기화 시켜줘야한다.
        string str = ""; // while문 안에서 초기화 시켜줘야한다.
        getline(cin, str);
        if(str=="."){ //만약 . 이 입력된다면 exit하기
            exit(0);
        }
        for(int i=0; i<str.length(); i++){
            if(str[i]=='(' || str[i]=='['){
                st.push(str[i]);
            }
            else if(str[i]==')' || str[i]==']'){
                if(st.empty()){
                    ans = "no";
                    break;
                }
                else{
                    char prev = st.top();
                    if((str[i] == ']'&& prev !='[')||(str[i] == ')'&& prev !='(')){
                        ans = "no";
                        break;
                    }         
                    st.pop();
                }
            }
        }
        if(!st.empty()){
            ans = "no";
        }
        cout<<ans<<endl;
    }
    return 0;
}