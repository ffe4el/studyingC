#include <cstdio>
#define MAX_DEGREE 80
class polynomial{
    int degree;
    float coef[MAX_DEGREE];
public:
    polynomial(){degree=0;} //생성자 : 최대차수를 0으로 초기화

    //다항식의 내용을 입력받는 멤버함수
    void read(){
        printf("다항식으 최고차수를 입력하시오: ");
        scanf("%d", &degree);
        printf("각 항의 계수를 이벽하시오 (총 %d개): ", degree+1);
        for(int i=0; i<=degree; i++)
            scanf("%f", coef+i);
    }

    //다항식의 내용을 화면에 출력하는 함수
    void display(char *str=" Poly = "){ //디폴트 매개변수 사용
        printf("\t%s", str);    //\t는 탭코드이다.
        for(int i=0; i<degree; i++)
            //소수 자릿수 부족시 반올림 실행, 소수점도 자리수에 해당, 정수는 자리수에 관련 없이
            printf("%5.1f x^%d + ", coef[i], degree-i);
        printf("%4.1f\n", coef[degree]);
    }

    //다항식 a와 b를 더하는 함수. a와 b를 더해 자신의 다항식 설정
    void add(polynomial a, polynomial b){
        if (a.degree > b.degree){ //a항> b항
            *this =a;
            for(int i=0; i<b.degree; i++)
                coef[i+(degree-b.degree)] += b.coef[i];
        }
        else {
            *this = b;
            for(int i=0; i<a.degree; i++)
                coef[i+(degree-a.degree)]+= a.coef[i];
        }
    }

    bool isZero(){return degree ==0;}   //최고차수가 0인가?
    void negate(){  //모든 계수의 부호를 바꿈
        for(int i=0; i<=degree; i++)
            coef[i] = -coef[i];
    }

};

void main(){
    polynomial a, b,c;
    a.read();
    b.read();
    c.add(a,b);
    a.display("A = ");
    b.display("B = ");
    c.display("A+B = ");
}