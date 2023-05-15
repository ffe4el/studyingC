#include <cstdio>

class BinaryNode
{
protected:
	int data;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l), right(r) {}
	~BinaryNode() {}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return left == NULL && right == NULL; }

};

class BinaryTree
{
private:
	BinaryNode* root;
public:
	BinaryTree() :root(NULL) {}
	~BinaryTree() {}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	void inorder() { printf("\n   inorder: "); inorder(root); }
	void preorder() { printf("\n   preorder: "); preorder(root); }
	void postorder() { printf("\n   postorder: "); postorder(root); }

	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	void reverse() { if (!isEmpty()) reverse(root); } //최상위 노드(root)부터 왼쪽 자식트리와 오른쪽 자식트리를 바꾸는 함수
	void isBalanced() { //최상위 노드(root)부터 봤을 때의 균형 잡힘 여부 확인 함수
		if (isBalanced(root) == 0)
			printf("이 트리는 균형 잡혀 있지 않습니다.\n");
		else
			printf("이 트리는 균형 잡혀 있습니다.\n");
	}

	void isFull() { //포화이진트리인지 검사하는 함수
		int n = 1;
		for (int i = 0; i < getHeight() - 1; i++) //2^(트리의 높이-1)가 단말노드의 수와 같으면 포화 이진 트리임
		{
			n = n * 2;
		}
		if (getLeafCount() == n)
			printf("이 트리는 포화이진트리입니다.\n");
		else
			printf("이 트리는 포화이진트리가 아닙니다.\n");
	}

	bool isBalanced(BinaryNode* node)
	{
		int hLeft = getHeight(node->getLeft()); //왼쪽 서브트리의 높이
		int hRight = getHeight(node->getRight()); //오른쪽 서브트리의 높이
		if (hLeft - hRight > -2 && hLeft - hRight < 2) //왼쪽 서브트리와 오른쪽 서브트리의 차이가 2보다 작을때 참 반환
			return true;
		return false; //그렇지 않을 시 거짓 반환
	}

	void inorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL) inorder(node->getLeft());
			printf("%d ", node->getData());
			if (node->getRight() != NULL) inorder(node->getRight());
		}
	}

	void preorder(BinaryNode* node) {
		if (node != NULL) {
			printf("%d ", node->getData());
			if (node->getLeft() != NULL) preorder(node->getLeft());
			if (node->getRight() != NULL) preorder(node->getRight());
		}
	}

	void postorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL) postorder(node->getLeft());
			if (node->getRight() != NULL) postorder(node->getRight());
			printf("%d ", node->getData());
		}
	}

	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}

	void reverse(BinaryNode* node)
	{
		BinaryNode* tmp = node->getLeft(); //해당 노드의 왼쪽 자식 노드를 tmp에 임시 저장
		node->setLeft(node->getRight()); //해당 노드의 오른쪽 자식 노드의 값을 왼쪽 자식 노드로 설정
		node->setRight(tmp); //tmp(왼쪽 자식 노드)의 값을 오른쪽 자식 노드로 설정

		if (node->getLeft() != NULL)
			reverse(node->getLeft()); //왼쪽 노드가 비어있지 않을때까지 재귀함수 실행
		if (node->getRight() != NULL)
			reverse(node->getRight()); //오른쪽 노드가 비어있지 않을때까지 재귀함수 실행
	}

};

int main(void)
{
	BinaryTree tree;
	BinaryNode* d = new BinaryNode(4, NULL, NULL);
	BinaryNode* e = new BinaryNode(5, NULL, NULL);
	BinaryNode* b = new BinaryNode(2, d, e);
	BinaryNode* f = new BinaryNode(6, NULL, NULL);
	BinaryNode* g = new BinaryNode(7, NULL, NULL);
	BinaryNode* c = new BinaryNode(3, f, g);
	BinaryNode* a = new BinaryNode(1, b, c);

	tree.setRoot(a);
	printf("노드의 개수 %d\n", tree.getCount());
	printf("단말의 개수 %d\n", tree.getLeafCount());
	printf("트리의 높이 %d\n", tree.getHeight());
	tree.isFull();
	tree.isBalanced();
	tree.inorder();
	tree.reverse();
	tree.inorder();
}