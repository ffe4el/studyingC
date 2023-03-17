#include <iostream>
#include <string>
#include <stack>
using namespace std;
void checkMatching(const string &str) {
    stack<char> big_quote, bracket, annotation; //큰따옴표, 괄호 스택
    int lineCount = 0, bracketCount = 0; // 줄 갯수, 괄호 짝갯수
    bool flagError = false; // 따옴표 오류 여부
    for (auto ch : str) {
        if (ch == '\n') { // ch에 enter 키가 들어가면 줄 갯수 증가
            lineCount++;
            if (!annotation.empty())
                annotation.pop();
        }
        if (ch == '\"') { //ch에 "가 들어가면 
            if (!big_quote.empty()) { // 큰따옴표 스택이 비어있지 않으면 top 을 pop
                big_quote.pop();
            }

            else {                      //비어있으면 큰따옴표를 스택에 집어넣음
                big_quote.push(ch);
            }
        if (ch == '/' && ch + 1 == '/')
            {
            annotation.push(ch);
               
             }
        }
        if (big_quote.empty()&&annotation.empty()) { //큰따옴표 스택이 비어있으면
            if (ch == '(' || ch == '{' || ch == '[') {      //여는 괄호가 나올 경우 괄호 스택에 집어넣음
                bracket.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']') { // 닫는 괄호가 나올 경우 
                if (bracket.empty()) {                          //괄호 스택이 비어있으면 에러로 판단 후 라인 한 줄 더 생성 후 나옴
                    flagError = true;
                    lineCount++;
                    break;
                }
                else {                                          //괄호 스택이 비어있지 않으면 Top에 괄호 스택의 top 을 저장하고 top을 삭제
                    char Top = bracket.top();
                    bracket.pop();
                    if (ch == ')' && Top == '(' || ch == '}' && Top == '{' || ch == ']' && Top == '[') { //저장된 Top과 현재 받은 닫는 괄호의 짝이 맞으면 괄호짝 수 하나 증가
                        bracketCount++;
                    }
                    else {           // 짝이 맞지 않으면
                        if (bracket.empty()) { // 괄호스택이 더는 없는경우 오류로 판단함
                            flagError = true;
                        }
                        lineCount++; //줄을 한줄 더 늘리고 나옴
                        break;
                    }
                }
            }
        }
    }
    if (!big_quote.empty() || !bracket.empty() || flagError)  //다 끝났는데 따옴표가 비어있지않거나, 괄호가 비어있지 않거나, 오류가 true로 변환된경우 error문 출력
    {
        cout << "Error, Line_count : " << lineCount << ", bracket_count : " << bracketCount << endl;
    }
    else { //그렇지 않으면 ok문 출력
        cout << "OK, Line_count : " << lineCount << ", bracket_count : " << bracketCount << endl;
    }
}
int main() {
    string Str, temp;
    while (true) {
        getline(cin, temp);
        if (temp == "EOF")break;
        Str.append(temp);
        Str.append("\n");
        cin.clear();
    }
    checkMatching(Str);

    return 0;
}