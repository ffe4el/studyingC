#include <iostream>
#include <string>
using namespace std;

const int MAX_STACK_SIZE = 20;

class ArrayStack
{
    int top;    //요소 개수
    int data[MAX_STACK_SIZE]; //요소의 배열

public :
    ArrayStack(){top = -1;} //스택의 생성자
    //반환자가 bool 타입이기 때문에 return top==-1일때 True를 반환하고, top!=-1이면 False를 반환한다.
    bool isEmpty(){return top == -1;}
    bool isFull(){return top == MAX_STACK_SIZE-1;}

    void push(int e){
        //만약 스택이 가득 찼다면
        // if(isFull()) error ("스택 포화 에러");
        data[++top] =e; //top에 먼저 1 더하고, 그 자리에 새로운 e값 넣기
    }

    int pop(){
        return data[top--];
    }

    int peek(){
        return data[top];
    }

    void display(){
        printf("[스택 항목의 수 = %2d] ==> ", top+1);
        for(int i=0; i<=top; i++){
            printf("<%2d>", data[i]);
            printf("\n");
        }
    }
};

void checkMatching(string Str, int cnt){
    ArrayStack stack;
    string ans;
    int bc = 0;
    bool quotes=false;
    int a;
    int aa;

    a = Str.length();
    for(int i=0; i<a; i++){
        if(quotes){ //큰따옴표가 열려있는 상태
            if (Str[i]=='\"'){
                quotes=false;
            }
        }
        else{ //큰따옴표가 닫혀있는 상태 => ()짝맞추기
            if(Str[i] == '[' || Str[i] =='(' || Str[i] =='{'){
                stack.push(Str[i]);
            }
            else if(Str[i] == ']' || Str[i]==')' || Str[i]=='}'){
                if(stack.isEmpty()){
                ans = "Error";
                }
                else{
                    int prev = stack.peek();
                    if((Str[i] == ']'&& prev !='[')||(Str[i] == ')'&& prev !='(')||(Str[i] == '}'&& prev !='{')){
                        ans = "Error";
                        continue;
                    }
                    bc++;
                    stack.pop();
                }
            }
            else if(Str[i]=='\"'){
                quotes= true;
            }
        }
    }

    if (stack.isEmpty()){
        ans = "OK";
    }
    else{
        ans = "Error";
    }
     

    cout << ans <<", Line_count : "<<cnt<<", bracket_count : "<<bc<<endl;

}

int main(){
    string Str,temp;
    int cnt;
    while(true){
        getline(cin,temp);
        if(temp=="EOF")break;
        cnt++;
        Str.append(temp);
        // Str.append("\n");
        // cin.clear();
    }
    checkMatching(Str, cnt);
    return 0;
}