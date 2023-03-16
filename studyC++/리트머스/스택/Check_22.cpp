#include <iostream>
#include <string>
using namespace std;

void checkMatching(string Str, int cnt){
    int qc = 0;     // 작은따옴표 수
    bool quotes = false; // 작은따옴표 내부에 있는지 여부
    for(int i=0; i<Str.length(); i++){
        if(Str[i] == '\''){
            if (i > 0 && Str[i - 1] == '\\') { // 이스케이프 시퀀스 처리
                continue;
            }
            if (quotes){    // 작은따옴표 닫기
                qc++;
                quotes = false;
            }
            else {  // 작은따옴표 열기
                quotes = true;
            }
        }
    }

    string ans = (quotes) ? "Error" : "OK";
    cout << ans << ", Line_count : " << cnt << ", quotes_count : " << qc << endl;
}

int main(){
    string Str, temp;
    int cnt;
    while(true){
        getline(cin, temp);
        if(temp == "EOF") break;
        Str.append(temp);
        cnt++;
    }
    checkMatching(Str,cnt);

    return 0;
}
