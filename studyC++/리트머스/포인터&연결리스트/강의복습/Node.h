//연결리스트로 구현된 스택을 위한 노드 클래스
#include "Student.h"
class Node: public Student{ //Student를 상속하여 구현함
    Node* link; //다음노드를 가리키는 포인터 변수
public:
    Node(int id=0, char* name="", char* dept="") //생성자. 멤버 초기화 리스트를 사용하여 부모클래스 Student의 생성자를 선택하여
    : Student(id, name, dept){link = NULL;} //호출한것에 유의할것. link는 반드시 NULLfh chrlghk godigka.
    ~Node(void){} //소멸자.

    Node* getLink(){ return link; }

    void setLink(Node *p) { link = p;}


};