#include <stdio.h>

int main(void){
    int coffee = 4500;
    int coffe = 3500;
    int c;
    int sandwich = 6000;
    int s;
    printf("커피를 몇개 주문하시겠습니까?");
    scanf("%d", &c);
    printf("샌드위치를 몇개 주문하시겠습니까?");
    scanf("%d", &s);
    if(s>0){
        printf("주문하신 메뉴의 총 금액은 %d원 입니다.", coffe*c+sandwich*s);
    }
    else if(s==0){
        printf("주문하신 메뉴의 총 금액은 %d원 입니다.", coffee*c);
    }
    else {
        printf("오류입니다.");
    }
}