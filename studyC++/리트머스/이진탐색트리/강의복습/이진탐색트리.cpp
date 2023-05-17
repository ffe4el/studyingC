#include <cstdio>
#include <cstdlib>

class BinaryNode{
protected:
    int data;
    BinaryNode *left;
    BinaryNode *right;
public :
    BinaryNode(int val=0, BinaryNode *l = NULL, BinaryNode *r=NULL)
        :data(val), left(l), right(r) { }
    ~BinaryNode() { }

    void setDAta(int val) {data = val;}
    void setLeft(BinaryNode *l) {left = l;}
    void setRight(BinaryNode *r){right = r;}
    int getData() {return data;}
    BinaryNode* getLeft() {return left;}
    BinaryNode* getRight() {return right;}
    bool isLeaf() {return left == NULL && right == NULL;}
};

class BinaryTree{
private:
    BinaryNode * root;
public : 
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
    BinSrchTree(void){}
    ~BinSrchTree(void){}

    //탐색연산(키값으로 노드를 탐색하는 함수)
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

    
};