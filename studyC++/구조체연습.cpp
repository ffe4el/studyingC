#include <iostream>
using namespace std;

struct Prop{
    int savings;
    int loan;
};



int calcproperty(Prop*);

int main(){
    int hong_prop; //인수 선언
    Prop hong = {1000000, 4000000}; //구조체 초기화
    hong_prop = calcproperty(&hong); //구조체의 주소를 함수의 인수로 전달함

    cout<<"홍길동의 재산은 적금 "<<hong.savings<<"원에 대출 "
    <<hong.loan<<"원을 제외한 총 "<<hong_prop<<"원입니다.";
    return 0;
}

int calcproperty(Prop *money){
    money -> savings =100; // 호출된 함수에서 원본 구조체의 데이터를 변경
    return (money->savings-money->loan);
}

