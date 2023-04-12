#include <cstdio>
class Node{
    Node* link; //다음 노드를 가리키는 포인터 변수
    int data; //노드의 데이터 필드
public:
    Node(int val =0): data(val), link(NULL){ }
    Node* getLink() { return link;}
    void setLink(Node* next) {link = next;}
    void display() {printf(" <%2d>", data);}
};