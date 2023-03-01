#include <iostream>
using namespace std;

struct Prop{
    int savings;
    int loan;
};

Prop InitProperty(void);
int CalcProperty(const Prop*);

int main()
{   
    Prop hong;
    int hong_prop;
    hong = InitProperty();
    hong_prop = CalcProperty(&hong); //구조체의 멤버 변수를 함수의 인수로 전달함

    cout<<"홍길동의 재산은 적금 "<<hong.savings<<"원에 대출 "
    <<hong.loan<<"원을 제외한 총 "<<hong_prop<<"원입니다.";


    return 0;
}

Prop InitProperty(void){
    Prop hong_prop = {1000000, 400000};
    return hong_prop; //구조체를 함수의 반환값으로 반환함
}

//const키워드를 사용하여 구조체의 데이터를 직접 수정하는것을 방지함
int CalcProperty(const Prop*money){
    //money -> savings = 100; //호출된 함수에서 원본 구조체의 데이터를 변경
    return(money->savings-money->loan);
} 

// 위의 코드에서 CalcProperty() 함수 내의 주석 처리된 부분을 실행하여 
// 원본 구조체에 대한 수정을 시도할 경우 C++ 컴파일러는 오류를 발생시킵니다

//또한, 위의 예제에서 InitProperty() 함수의 반환값으로 구조체를 반환합니다.
//기본적으로 C++의 함수는 한 번에 하나의 데이터만을 반환할 수 있습니다.
//하지만 이렇게 구조체를 사용하면 한 번에 여러 개의 데이터를 반환할 수 있게 됩니다.

