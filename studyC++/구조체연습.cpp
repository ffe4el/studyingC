/*위와 같이 구조체를 가리키는 포인터를 인수로 전달하는 방식은 구조체의 복사본이 아닌 주소 하나만을 전달하므로 빠르다는 장점을 가집니다.
    하지만 호출된 함수에서 원본 구조체에 직접 접근하므로, 원본 데이터의 보호 측면에서는 매우 위험합니다. */

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

