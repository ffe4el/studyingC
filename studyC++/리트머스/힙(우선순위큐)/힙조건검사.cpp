#include <cstdio>
#include <iostream>
#define MAX_ELEMENT 200
using namespace std;


class HeapNode{
    int key;
public :
    HeapNode(int k=0) : key(k){}
    void setKey(int k){key=k;}
    int getKey() {return key;}
    void display(){printf("%d ", key);}
};

class MaxHeap{
    HeapNode node[MAX_ELEMENT]; //요소의 배열
    int size;
public:
    MaxHeap() : size(0) { }
    bool isEmpty(){return size==0;}
    bool isFull(){return size == MAX_ELEMENT-1;}

    HeapNode& getParent(int i){return node[i/2];} //부모노드
    HeapNode& getLeft(int i){return node[i*2];} //왼쪽 자식노드
    HeapNode& getRight(int i){return node[i*2+1];} //오른쪽 자식노드

    //UP heap
    void insert(int key){
        if(isFull()) return;
        int i= ++size; //증가된 힙 크기 위치에서 시작!

        //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
        while(i!=1 && key > getParent(i).getKey()){ //루트가 아니고 부모보다 키값이 크면
            node[i] = getParent(i); //부모를 끌어내림
            i /= 2; //한 레벨 위로 상승시킴
        }
        node[i].setKey(key); //최종 위치에 키 삽입
    }
    //Down heap
    HeapNode remove(){
        if(isEmpty()) printf("NO");
        HeapNode item = node[1]; //루트노드(우선적으로 서비스할 요소)
        HeapNode last = node[size--]; //힙의 마지막 노드
        int parent =1; //마지막 노드의 위치를 루트로 생각함
        int child =2; //루트의 왼쪽 자식 위치
        while(child <= size) {//힙 트리를 벗어나지 않는 동안..
            if(child<size&&getLeft(parent).getKey() < getRight(parent).getKey()){
                child++; //작은값을 오른쪽 자식이 갖고 있음
            }
            if(last.getKey() >= node[child].getKey()) break;
            //한단계 아래로 이동
            node[parent] = node[child];
            parent = child;
            child *= 2; 
        }
        node[parent] = last; //마지막 노드를 최종 위치에 저장
        return item; // 루트 노드 반환
    }

    HeapNode find() {
        return node[1];
    }

    void display() {
        for(int i=1, level=1; i<=size; i++){
            if(i==level){
                level *= 2;
            }
            node[i].display();
        }
        printf("\n");
    }

    bool isHeap(){
        for(int i=1, level=1; i<=size; i++){
            if(i==level){
                level *= 2;
            }
            node[i].display();
        }
        printf("\n");
    }
};


int main(){
    MaxHeap heap;

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        //num을 insert해주기
        heap.insert(num);
    }
    heap.display();

    

    printf("\n");

    return 0;
}