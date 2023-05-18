#define MAX_WORD_SIZE 40
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

class Record{
    char ko[MAX_WORD_SIZE]; //한국어
    char en[MAX_WORD_SIZE]; //영어
public : 
    Record(char* k=" ", char* e=" "){set(k,e);}
    void set(char* k, char* e){
        strcpy(ko, k);
        strcpy(en, e);
    }
    int compare(Record *n){return compare(n->ko);}
    int compare(char* k){return strcmp(k, ko);}

    // void display()
    // void copy(Record *n)
};


class BinaryNode:public Record{
    BinaryNode *left;
    BinaryNode *right;
public :
    BinaryNode(char* k=" ", char* e=" ")
        :Record(k,e), left(NULL), right(NULL) { }
    ~BinaryNode() { }

    // void setData(char* val) {data = val;}
    // int getData() {return data;}
    void setLeft(BinaryNode *l) {left = l;}
    void setRight(BinaryNode *r){right = r;}
    BinaryNode* getLeft() {return left;}
    BinaryNode* getRight() {return right;}
    bool isLeaf() {return left == NULL && right == NULL;}
};

class BinaryTree{
protected:
    BinaryNode* root;
public : 
    BinaryTree() : root(NULL){ }
    ~BinaryTree() { }
    bool isEmpty() {return root == NULL; }
    
    //중위순회
    void inorder() {printf("\n inorder: "); inorder(root);}

    void inorder(BinaryNode *node){
        if(node != NULL){
            inorder(node->getLeft());
            // node->display();
            inorder(node->getRight());
        }
    }
};

class BinSrchTree:public BinaryTree{
public :
//한국어 찾기
    //탐색연산(키값으로 노드를 탐색하는 함수)
    BinaryNode* search(char* key){
        return searchRecur(root, key);
    }
    BinaryNode* searchRecur(BinaryNode *n, char* key){
        if(n==NULL) return NULL;
        if(n->compare(key)==0) //key==현재노드데이터
            return n;
        else if(n->compare(key) < 0) //key < 현재노드데이터
            return searchRecur(n->getLeft(), key);
        else    //key > 현재노드데이터
            return searchRecur(n->getRight(), key);
    }

//영어 찾기
    // BinaryNode* search1(char* key){
    //     return searchRecur1(root, key);
    // }
    // BinaryNode* searchRecur1(BinaryNode *n, char* key){
    //     if(n==NULL) return NULL;
    //     if(n->compare1(key)==0) //key==현재노드데이터
    //         return n;
    //     else if(n->compare1(key) < 0) //key < 현재노드데이터
    //         return searchRecur(n->getLeft(), key);
    //     else    //key > 현재노드데이터
    //         return searchRecur(n->getRight(), key);
    // }
    

    //삽입연산
    //이진탐색트리에 원소를 삽입하기 위해서는 먼저 탐색을 수행해야한다
    //탐색에 실패한 위치가 바로 새로운 노드를 삽입하는 위치!!
    void insert(BinaryNode* n){
        if(n==NULL) return;
        if(isEmpty()) root = n;
        else insertRecur(root, n);
    }
    //순환방법
    void insertRecur(BinaryNode* r, BinaryNode* n){
        if(n->compare(r)==0)
            return ;
        else if(n->compare(r)>0){   //새로 입력한 데이터가 기존 데이터보다 작으면
            if(r->getLeft() == NULL) r-> setLeft(n); //기존데이터의 왼쪽이 비었으면 왼쪽에 위치 시키기
            else insertRecur(r->getLeft(), n); //비어있지 않으면 기존데이터의 오른쪽방향으로 다시 삽입함수 돌리기
        }
        else{ //새로 입력한 데이터가 기존 데이터보다 크면
            if(r->getRight()==NULL) r -> setRight(n); //기존데이터의 오른쪽이 비었으면 오른쪽에 위치 시키기
            else insertRecur(r->getRight(),n); //비어있지 않으면 기존데이터의 오른쪽방향으로 다시 삽입함수 돌리기
        }
    }

};

int main(){
    // BinaryNode* 
    BinSrchTree tree;

    // BinaryNode* arr[20];

    char type;
    while(type != 'q'){
        cin >> type;
        
        if(type=='i'){//삽입연산
            char korean[20];
            char english[30]; 
            cin >> korean >> english;
            BinaryNode* a = new BinaryNode(korean, english);
            tree.insert(a);
            // arr[i] = new BinaryNode(n);
            // tree.insert(arr[i]);
        }
        else if(type=='k'){ //한국어를 입력받아 영어를 출력함
            char korean[20];
            cin >> korean; 
            cout << tree.search(korean) << endl;
        }
        else if(type=='e'){ //영어를 입력받아 한국어를 출력함
            
        }
        else if(type=='p'){ //한, 영 둘다 출력

        }
    }


    return 0;
}