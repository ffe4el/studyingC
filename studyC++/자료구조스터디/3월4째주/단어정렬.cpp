#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cmp(string a, string b){
    //길이가 같다면 사전순으로
    if(a.length() == b.length()){
        return a<b;
    }
    //길이가 다르다면, 짧은순으로
    else{
        return a.length()<b.length();
    }
}

string word[20000];

int main(){
    int n;
    cin >> n;

    //string형 단어를 배열 word에 넣을 수 있다!
    for(int i=0; i<n; i++){
        cin >> word[i];
    }
    //첫 번째 인자: iterator(or 포인터)에서 정렬을 시작 할 부분
    //두 번째 인자: iterator(or 포인터)에서 정렬을 마칠 부분
    //세 번째 인자 : 정렬을 어떤 식으로 할 것인지 알려주는 함수
    //세 번째 인자를 compare함수라고 많이들 부르던데, 이 부분에는 bool형 함수나 혹은 수식(수식도 0또는 1이 나오므로)을 넣어 줄 수 있다.
    //주의해야 할 점은 인자로는 compare()가 아닌 compare를 넣어줘야 한다는 것
    sort(word, word+n, cmp);

    for(int i=0;i<n;i++){
        if(word[i]==word[i-1]){
            continue;
        }
        cout <<word[i]<<endl;
    }
    return 0;
}