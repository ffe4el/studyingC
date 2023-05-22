#include <iostream>
#include <cstring>
#define MAX_WORD_SIZE 100
using namespace std;

class Record {
    char ko[MAX_WORD_SIZE]; //한국어
    char en[MAX_WORD_SIZE]; //영어
public:
    Record(char* k = "", char* e = "") {
        set(k, e);
    }
    void set(char* k, char* e) {
        strcpy(ko, k);
        strcpy(en, e);
    }
    int compare(Record* n) { return compare(n->ko); }
    int compare(char* k) { return strcmp(k, ko); }
    int compare1(Record* n) { return compare1(n->en); }
    int compare1(char* e) { return strcmp(e, en); }

    void display() {
        cout << ko << " " << en << endl;
    }

    void display1(){
        cout << en << " "<< ko << endl;
    }

    void copy(Record* n) {
        set(n->ko, n->en);
    }

    char* getKo() {
        return ko;
    }

    char* getEn() {
        return en;
    }
};

class BinaryNode : public Record {
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(char* k = "", char* e = "")
        : Record(k, e), left(NULL), right(NULL) { }
    ~BinaryNode() { }

    void setLeft(BinaryNode* l) { left = l; }
    void setRight(BinaryNode* r) { right = r; }
    BinaryNode* getLeft() { return left; }
    BinaryNode* getRight() { return right; }
    bool isLeaf() { return left == NULL && right == NULL; }
};

class BinaryTree {
protected:
    BinaryNode* root;
public:
    BinaryTree() : root(NULL) { }
    ~BinaryTree() { }
    bool isEmpty() { return root == NULL; }

    void insert(BinaryNode* node) {
        if (isEmpty()) {
            root = node;
        }
        else {
            BinaryNode* current = root;
            while (true) {
                if (node->compare(current) > 0) {
                    if (current->getLeft() == NULL) {
                        current->setLeft(node);
                        break;
                    }
                    else {
                        current = current->getLeft();
                    }
                }
                else {
                    if (current->getRight() == NULL) {
                        current->setRight(node);
                        break;
                    }
                    else {
                        current = current->getRight();
                    }
                }
            }
        }
    }

    void insert1(BinaryNode* node) {
        if (isEmpty()) {
            root = node;
        }
        else {
            BinaryNode* current = root;
            while (true) {
                if (node->compare1(current) > 0) {
                    if (current->getLeft() == NULL) {
                        current->setLeft(node);
                        break;
                    }
                    else {
                        current = current->getLeft();
                    }
                }
                else {
                    if (current->getRight() == NULL) {
                        current->setRight(node);
                        break;
                    }
                    else {
                        current = current->getRight();
                    }
                }
            }
        }
    }

    void inorder() {
        // cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }
    void inorder1() {
        // cout << "Inorder: ";
        inorder1(root);
        cout << endl;
    }

    void inorder(BinaryNode* node) {
        if (node != NULL) {
            inorder(node->getLeft());
            node->display();
            inorder(node->getRight());
        }
    }

    void inorder1(BinaryNode* node) {
        if (node != NULL) {
            inorder1(node->getLeft());
            node->display1();
            inorder1(node->getRight());
        }
    }

    BinaryNode* search(char* key) {
        BinaryNode* current = root;
        while (current != NULL) {
            if (current->compare(key) == 0) {
                return current;
            }
            else if (current->compare(key) > 0) {
                current = current->getLeft();
            }
            else {
                current = current->getRight();
            }
        }
        return NULL;
    }

    BinaryNode* search1(char* key) {
        BinaryNode* current = root;
        while (current != NULL) {
            if (current->compare1(key) == 0) {
                return current;
            }
            else if (current->compare1(key) > 0) {
                current = current->getLeft();
            }
            else {
                current = current->getRight();
            }
        }
        return NULL;
    }
};

class Dictionary {
private:
    BinaryTree ke_dictionary;
    BinaryTree ek_dictionary;

public:
    void insertKE(char* korean, char* english) {
        Record record(korean, english);
        BinaryNode* node = new BinaryNode();
        node->copy(&record);
        ke_dictionary.insert(node);
    }

    void insertEK(char* english, char* korean) {
        Record record(korean, english);
        BinaryNode* node = new BinaryNode();
        node->copy(&record);
        ek_dictionary.insert1(node);
    }

    void searchKE(char* korean) {
        BinaryNode* result = ke_dictionary.search(korean);
        if (result == NULL) {
            cout << "<한국어단어 UNKNOWN ENTRY>" << endl;
        }
        else {
            cout << korean << " " << result->getEn() << endl;
        }
    }

    void searchEK(char* english) {
        BinaryNode* result = ek_dictionary.search1(english);
        if (result == NULL) {
            cout << "<영어단어 UNKNOWN ENTRY>" << endl;
        }
        else {
            cout << english << " " << result->getKo() << endl;
        }
    }

    void printKE() {
        cout << "K-E dictionary:" << endl;
        ke_dictionary.inorder();
    }

    void printEK() {
        cout << "E-K dictionary:" << endl;
        ek_dictionary.inorder1();
    }
};

int main() {
    Dictionary dictionary;
    char choice;

    do {
        cin >> choice;

        switch (choice) {
        case 'i': {
            char korean[MAX_WORD_SIZE], english[MAX_WORD_SIZE];
            cin >> korean >> english;
            // gets(korean);
            // gets(english);
            dictionary.insertKE(korean, english);
            dictionary.insertEK(english, korean);
            break;
        }
        case 'k': {
            char korean[MAX_WORD_SIZE];
            cin >> korean;
            dictionary.searchKE(korean);
            break;
        }
        case 'e': {
            char english[MAX_WORD_SIZE];
            cin >> english;
            dictionary.searchEK(english);
            break;
        }
        case 'p': {
            dictionary.printKE();
            dictionary.printEK();
            break;
        }
        }
    } while (choice != 'q');

    return 0;
}
