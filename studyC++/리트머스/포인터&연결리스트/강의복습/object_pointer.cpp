//클래스 객체를 포인터로 조작하는 프로그램
#include <iostream>

struct MyNewType{
    int i;
    float f;
};

int main(){
    MyNewType s, *ps;
    ps= &s;
    ps -> i=2; //(*ps).i=2; 와 동일
    ps -> f=3.14f; //(*ps).f=2; 와 동일
}