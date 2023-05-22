#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class BinaryNode{
protected:
    int data;
    BinaryNode *left;
    BinaryNode *right;
public :
    BinaryNode(int val=0, BinaryNode *l = NULL, BinaryNode *r=NULL)
        :data(val), left(l), right(r) { }
    ~BinaryNode() { }

    void setData(int val) {data = val;}
    void setLeft(BinaryNode *l) {left = l;}
    void setRight(BinaryNode *r){right = r;}
    int getData() {return data;}
    BinaryNode* getLeft() {return left;}
    BinaryNode* getRight() {return right;}
    bool isLeaf() {return left == NULL && right == NULL;}
};

class BinaryTree{

public :
    BinaryNode *root; 
    BinaryTree() : root(NULL){ }
    ~BinaryTree() { }

    void setRoot(BinaryNode* node){root = node;}
    BinaryNode* getRoot() {return root;}
    bool isEmpty() {return root == NULL; }
    
    //중위순회
    void inorder() {printf("\n inorder: "); inorder(root);}
    //전위순회
    void preorder() {printf("\n preorder: "); preorder(root);}
    //후위순회
    void postorder() {printf("\n postorder: "); postorder(root);}
    //레벨순회
    // void levelorder(){
    //     printf("\nlevelorder: ");
    //     if(!isEmpty()){
    //         CircularQueue q;
    //         q.enqueue(root);
    //         while(!q.isEmpty()){
    //             BinaryNode* n = q.dequeue();
    //             if( n != NULL ) {
	// 				printf(" [%c] ", n->getData());
	// 				q.enqueue(n->getLeft ());
	// 				q.enqueue(n->getRight());
	// 			}
    //         }
    //     }
    //     printf("\n");
    // }

    int getCount() {return isEmpty() ? 0:getCount(root);}
    int getLeafCount() {return isEmpty() ? 0:getLeafCount(root);}
    int getHeight() {return isEmpty() ? 0:getHeight(root);}
    
    //root부터 왼오 자식트리를 바꾸게 해주는 함수임
    void reverse() {if(!isEmpty()) reverse(root);}

    //균형이 잡혔는지 root부터 확인해주는 함수임
    void isBalanced() {
        if(isBalanced(root) == 0)
            printf("균형안잡힘\n");
        else
            printf("균형잡힘\n");
    }

    //트리의 노드 개수를 구하는 함수
    int getCount(BinaryNode *node){
        if(node == NULL) return 0;
        return 1+getCount(node->getLeft())+getCount(node->getRight());
    }

    //트리의 단말노드 개수를 구하는 함수
    int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

    //트리의 높이를 구하는 함수
    //서브트에 대하여 순환호출하고 서브 트리들의 반환값 중에서 큰 값을 구하여 1을 더해 반환
    int getHeight(BinaryNode *node){
        if(node == NULL) return 0;
        int hLeft = getHeight(node -> getLeft());
        int hRight = getHeight(node -> getRight());
        return (hLeft > hRight) ? hLeft+1 : hRight+1;
    }

    //포화이진트리인지 확인해주는 함수
    //전체노드개수와 2^k-1(k는 트리의 높이)를 비교하여 판별할 수 있다.
    void isFull() {
        int n=1;
        for(int i=0; i<getHeight(); i++){
            n= n*2;
        }
        if(getCount() == n-1){
            printf("포화이진트리O\n");
        }
        else{
            printf("포화이진트리X\n");
        }
    }
    
    //왼쪽서브트리와 오른쪽서브트리의 높이의 차이가 2보다 작으면 균형잡혀있다(balanced)고 본다.
    bool isBalanced(BinaryNode* node){
        int hLeft = getHeight(node -> getLeft()); //왼쪽 서브트리 높이 구하기
        int hRight = getHeight(node -> getRight()); //오른쪽 서브트리 높이 구하기
        if(hLeft > hRight){
            if(hLeft - hRight < 2)
                return true;
            else{
                return false;
            }
        }
        else{
            if(hRight - hLeft < 2)
                return true;
            else{
                return false;
            }
        }
    }

    //시험에 안나옴(별로 쓸데없음)
    //왼쪽서브트리와 오른쪽 서브트리를 바꾸는 함수
    void reverse(BinaryNode* node){
        //임의 변수 tmp정해서 일단 왼쪽꺼 저장
        BinaryNode* tmp = node->getLeft();
        //오른쪽꺼를 왼쪽 자식노드에 저장
        node -> setLeft(node->getRight());
        //오른쪽에 왼쪽꺼 저장해놓은거 저장 
        node -> setRight(tmp);


        //왼쪽노드가 안비어있을때만
        if(node->getLeft() != NULL)
            //왼쪽노드 reverse돌리기
        reverse(node -> getLeft());

        //오른쪽노드가 안비어있을때만
        if(node->getLeft() != NULL)
            //오른쪽노드 reverse돌리기
            reverse(node -> getLeft());
    }

// private:
    void inorder(BinaryNode *node){
        if(node != NULL){
            if(node -> getLeft() != NULL) inorder(node->getLeft());
            printf("[%d] ", node->getData());
            if(node -> getRight() != NULL) inorder(node->getRight());
        }
    }
    void preorder(BinaryNode *node) {
		if( node != NULL ) {
			printf( "[%d] ", node->getData());
			if( node->getLeft() != NULL ) preorder(node->getLeft());
			if( node->getRight()!= NULL ) preorder(node->getRight());
		}
	}
	void postorder(BinaryNode *node) {
		if( node != NULL ) {
			if( node->getLeft() != NULL ) postorder(node->getLeft());
			if( node->getRight()!= NULL ) postorder(node->getRight());
			printf( "[%d] ", node->getData());
		}
	}
};

class BinSrchTree:public BinaryTree{
public :
    // BinSrchTree(void){}
    // ~BinSrchTree(void){}

    //탐색연산(키값으로 노드를 탐색하는 함수)
    BinaryNode* search(int key){
        BinaryNode* node = search(root, key);
        if(node != NULL)
            printf("탐색성공 : 키값이 %d인 노드 = 0x\n", node->getData());
        else
            printf("탐색실패 : 키값이 %d인 노드 없음\n", key);
                return node;
    }
    BinaryNode* search(BinaryNode *n, int key){
        if(n==NULL) return NULL;
        if(key ==n->getData()) //key==현재노드데이터
            return n;
        else if(key < n-> getData()) //key < 현재노드데이터
            return searchRecur(n->getLeft(), key);
        else    //key > 현재노드데이터
            return searchRecur(n->getRight(), key);
    }

    //순환으로 구현
    BinaryNode* searchRecur(BinaryNode *n, int key){
        if(n==NULL) return NULL;
        if(key ==n->getData()) //key==현재노드데이터
            return n;
        else if(key < n-> getData()) //key < 현재노드데이터
            return searchRecur(n->getLeft(), key);
        else    //key > 현재노드데이터
            return searchRecur(n->getRight(), key);
    }
    //반복으로 구현
    BinaryNode* searchIter(BinaryNode *n, int key){
        while(n!=NULL){
            if(key==n->getData()) return n;
            else if(key < n-> getData())
                n= n->getLeft();
            else
                n = n->getRight();
        }
        return NULL;
    }
    //BinaryNode 클래스의 멤버 함수로 구현(순환)
    // BinaryNode* BinaryNode::search(int key){
    //     if(key==data) return this;
    //     else if(key < data && left!= NULL)
    //         return left->search(key);
    //     else if(key > data && right != NULL)
    //         return right->search(key);
    //     else    
    //         return NULL;
    // }

    //삽입연산
    //이진탐색트리에 원소를 삽입하기 위해서는 먼저 탐색을 수행해야한다
    //탐색에 실패한 위치가 바로 새로운 노드를 삽입하는 위치!!
    void insert(BinaryNode* n){
        if(n==NULL) return;
        if(isEmpty()) root = n;
        else insert(root, n);
    }
    //순환방법
    void insert(BinaryNode* r, BinaryNode* n){
        if(n->getData() == r->getData())
            return ;
        else if(n->getData() < r->getData()){   //새로 입력한 데이터가 기존 데이터보다 작으면
            if(r->getLeft() == NULL) r-> setLeft(n); //기존데이터의 왼쪽이 비었으면 왼쪽에 위치 시키기
            else insert(r->getLeft(), n); //비어있지 않으면 기존데이터의 오른쪽방향으로 다시 삽입함수 돌리기
        }
        else{ //새로 입력한 데이터가 기존 데이터보다 크면
            if(r->getRight()==NULL) r -> setRight(n); //기존데이터의 오른쪽이 비었으면 오른쪽에 위치 시키기
            else insert(r->getRight(),n); //비어있지 않으면 기존데이터의 오른쪽방향으로 다시 삽입함수 돌리기
        }
    }


    //삭제연산
    //1.삭제하려는 노드가 단말노드인 경우:단말노드의 부모노드를 찾아서 연결을 끊는다.
    //2.삭제하려는 노드가 하나의 서브트리만 가지고 있는 경우:노드는 삭제하고, 서브트리를 부모노드에 붙여준다.
    //3.삭제하려는 노드가 두개의 서브트리를 가지고 있는 경우:가장비슷한 값을 가진 노드를 삭제노드 위치로 가져온다.(후계 노드의 선택)
    void remove (int data){
        if(isEmpty()) return;
        //없앨노드와 그 노드의 부모를 찾는다.
        BinaryNode *parent = NULL;
        BinaryNode *node = root;
        while(node != NULL && node->getData() != data){
            parent = node;
            node = (data < node->getData()) ? node->getLeft():node->getRight();
        }
        if(node == NULL){
            printf(" Error : key is not in the tree!\n");
            return;
        }
        else{remove (parent, node);} //삭제할 노드를 찾았음
    }
    void remove(BinaryNode *parent, BinaryNode *node){
        //1.삭제하려는 노드가 단말노드인 경우
        if(node->isLeaf()){
            if(parent ==NULL) root =NULL; //삭제할노드가 root인 경우
            else{
                if(parent->getLeft() == node) //노드가 부모의 왼쪽자식일 경우
                    parent -> setLeft(NULL);  //해당자식을 NULL처리해서 삭제
                else
                    parent -> setRight(NULL); //노드가 부모의 오른쪽자식
            }
        }
        //2.삭제하려는 노드가 왼쪽 또는 오른쪽 자식만 가진 경우
        else if(node->getLeft()==NULL || node->getRight()==NULL){
            BinaryNode *child = 
            (node->getLeft() != NULL)?node->getLeft():node->getRight();
            if(node==root) root = child;
            else{   //부모노드의 자식으로 자식노드의 child를 직접 연결한다
                if(parent->getLeft() == node)
                    parent->setLeft(child);
                else   
                    parent->setRight(child);
            }
        }
        //3.삭제하려는 노드가 두개의 child가 있는 경우
        else{//삭제노드의 오른족 서브트리에서 가장 작은 노드를 탐색
            BinaryNode* succp = node;
            BinaryNode* succ = node->getRight();
            while(succ -> getLeft() != NULL){
                succp = succ;
                succ = succ->getLeft();
            }
            if(succp->getLeft() == succ)
                succp->setLeft(succ->getRight());//1.succ의 Rchild를 succp의 Lchild로..
            else
                succp->setRight(succ->getRight());//2.succ의 Rchild를 succp의 Rchild로..
            
            node->setData(succ->getData()); //삭제노드에 후계노드 정보를 복사
            node = succ; //후계노드를 삭제
        }
        delete node;
    }

    //균형이 잡혔는지 root부터 확인해주는 함수임
    bool isBalanced() {
        if(isBalanced(root) == 0)
            return false;
        else
            return true;
    }
    //왼쪽서브트리와 오른쪽서브트리의 높이의 차이가 2보다 작으면 균형잡혀있다(balanced)고 본다.
    bool isBalanced(BinaryNode* node){
        int hLeft = getHeight(node -> getLeft()); //왼쪽 서브트리 높이 구하기
        int hRight = getHeight(node -> getRight()); //오른쪽 서브트리 높이 구하기
        if(hLeft > hRight){
            if(hLeft - hRight < 2)
                return true;
            else{
                return false;
            }
        }
        else{
            if(hRight - hLeft < 2)
                return true;
            else{
                return false;
            }
        }
    }
    
};

int main(){
    BinSrchTree tree;

    int tc;
    cin >> tc;

    for(int i=0; i<tc; i++){
        char type;
        int n;
        cin >> type >> n;
        BinaryNode* a = new BinaryNode(n);
        if(type=='I'){//삽입연산
            tree.insert(a);
        }
        else { //삭제연산
            tree.remove(n);
        }

    }
    if(tree.isBalanced()){
        cout << "Balanced"<<endl;
    }
    else{
        cout << "Unbalanced"<<endl;
    }

    return 0;
}