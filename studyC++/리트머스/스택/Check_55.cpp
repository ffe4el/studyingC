#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    getline(cin, input); // 입력 받기
    string numStr = ""; // 추출한 숫자를 저장할 문자열
    for (char c : input) { // 입력 문자열을 한 문자씩 검사
        if (isdigit(c) || c == '.') { // 숫자나 소수점인 경우
            numStr += c; // 문자열에 추가
        }
    }
    double num = stod(numStr); // 문자열을 double형으로 변환
    cout << num << endl; // 변환한 숫자 출력
    return 0;
}