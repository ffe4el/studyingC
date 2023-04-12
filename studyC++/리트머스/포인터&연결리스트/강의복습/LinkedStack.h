#include "Node.h" //Node클래스 포함
class LinkedStack{
    Node* top; //헤드 포인터
public :
    LinkedStack() {top=NULL;}                           // 생성자
    //현재의 연결 리스트에 동적으로 할당한 노드가ㅣ 하나라도 있으면 모두 동적으로 해제해야 함.
    ~LinkedStack() {while(!isEmpty()) delete pop();}    // 소멸자
    bool isEmpty(){return top == NULL;}
    void push(Node *p){
        if(isEmpty()) top = p;
        else{
            p -> setLink(top);
            top = p;
        }
    }
    Node* pop(){
        if(isEmpty()) return NULL;
        Node *p = top;
        top = top -> getLink();
        return p;
    }
    Node* peek(){return top;}
    
    void display(){
        printf("[LinkedStack]\n");
        for(Node *p = top; p!=NULL; p=p->getLink())
            p->display();
        printf( "\n");
    }

};